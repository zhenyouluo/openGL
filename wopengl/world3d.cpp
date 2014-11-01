#include "world3d.h"

world3d::world3d()
{
    a = 0.3f;

}


GLvoid world3d::initializeGL(){

    LoadGLTextures();
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.0,0.0,0.0,0.0);
    glClearDepth(1.0);

    glDepthFunc(GL_LESS);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);                        //Create background light
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  white_light);                           //Create diffuse light
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);                           //Create light position

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glEnable(GL_DEPTH_TEST);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

GLvoid world3d::resizeGL(int w, int h){

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}

GLvoid world3d::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    scene();
    swapBuffers();
    glFlush();

}

GLvoid world3d::scene(){

    glBegin( GL_QUADS );

    glTexCoord2f(0.0f, 0.0f); glVertex3d( a, a, a);           //#1
    glTexCoord2f(1.0f, 0.0f); glVertex3d(-a, a, a);
    glTexCoord2f(1.0f, 1.0f); glVertex3d(-a,-a, a);
    glTexCoord2f(0.0f, 1.0f); glVertex3d( a,-a, a);

    glTexCoord2f(0.0f, 0.0f); glVertex3d(-a, a, a);           //#2
    glTexCoord2f(1.0f, 0.0f); glVertex3d(-a, a,-a);
    glTexCoord2f(1.0f, 1.0f); glVertex3d(-a,-a,-a);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(-a,-a, a);

    glTexCoord2f(0.0f, 0.0f); glVertex3d(-a, a,-a);           //#3
    glTexCoord2f(1.0f, 0.0f); glVertex3d( a, a,-a);
    glTexCoord2f(1.0f, 1.0f); glVertex3d( a,-a,-a);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(-a,-a,-a);

    glTexCoord2f(0.0f, 0.0f); glVertex3d( a, a,-a);           //#4
    glTexCoord2f(1.0f, 0.0f); glVertex3d( a, a, a);
    glTexCoord2f(1.0f, 1.0f); glVertex3d( a,-a, a);
    glTexCoord2f(0.0f, 1.0f); glVertex3d( a,-a,-a);

    glTexCoord2f(0.0f, 0.0f); glVertex3d(-a, a, a);           //#5
    glTexCoord2f(1.0f, 0.0f); glVertex3d( a, a, a);
    glTexCoord2f(1.0f, 1.0f); glVertex3d( a, a,-a);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(-a, a,-a);

    glTexCoord2f(0.0f, 0.0f); glVertex3d(-a,-a, a);           //#6
    glTexCoord2f(1.0f, 0.0f); glVertex3d( a,-a, a);
    glTexCoord2f(1.0f, 1.0f); glVertex3d( a,-a,-a);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(-a,-a,-a);

    glEnd();

}


GLvoid world3d::LoadGLTextures(){

    tImage.load(":/t1.bmp");
    tImage = QGLWidget::convertToGLFormat(tImage);
    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)tImage.width(), (GLsizei)tImage.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tImage.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);         // задана линейная фильтрация вблизи
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);         // задана линейная фильтрация вдали
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);      // при фильтрации игнорируются тексели, выходящие за границу текстуры для s координаты
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);      // при фильтрации игнорируются тексели, выходящие за границу текстуры для t координаты


}

void world3d::LoadFiles(){

//    FILE* f;
//    f = fopen(":/res/world.txt", r);

//    //

//    fclose(f);
}
