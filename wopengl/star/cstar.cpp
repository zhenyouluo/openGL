#include "cstar.h"

CStar::CStar()
{
    for(int i = 0; i < 50; i++){
        pStar[i].angle = 0;
        pStar[i].distance = (float(i)/50)*5.0f;
        pStar[i].r = rand()%256;
        pStar[i].g = rand()%256;
        pStar[i].b = rand()%256;
    }

}

GLvoid CStar::initGL(){

    LoadGLTextures();
    glEnable(GL_TEXTURE_2D);

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);                         //Maximal parameter of perspective corection

    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glEnable(GL_BLEND);

}

GLvoid CStar::scene(bool twinkle, GLfloat tilt, GLfloat zoom){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    for(int i = 0; i < 50; i++){

        glLoadIdentity();
        glTranslatef(0.0f,0.0f,zoom);
        glRotatef(tilt,           1.0f, 0.0f, 0.0f);
        glRotatef(pStar[i].angle, 0.0f, 1.0f, 0.0f);
        glTranslatef(pStar[i].distance,0.0f,0.0f);

        if (twinkle){

            glColor4ub(pStar[49-i].r, pStar[49-i].g, pStar[49-i].b, 255);
            glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
                    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,-1.0f, 0.0f);
                    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 0.0f);
                    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
            glEnd();

        }

        glRotatef(spin, 0.0f, 0.0f, 1.0f);
        glColor4ub(pStar[i].r, pStar[i].g, pStar[i].b, 255);
        glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
                glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,-1.0f, 0.0f);
                glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 0.0f);
                glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
        glEnd();



        spin += 0.1f;
        pStar[i].angle += (float(i)/50);
        pStar[i].distance -= 0.01f;

        if (pStar[i].distance < 0.0f){

            pStar[i].distance += 5.0f;
            pStar[i].r = rand()%256;
            pStar[i].g = rand()%256;
            pStar[i].b = rand()%256;

        }


    }




}

GLvoid CStar::LoadGLTextures(){

    imTexture.load(":/");
    imTexture = QGLWidget::convertToGLFormat(imTexture);

    glGenTextures(1, texture);

    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)imTexture.width(), (GLsizei)imTexture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, imTexture.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}
