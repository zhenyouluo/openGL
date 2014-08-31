#include "ccube.h"

CCube::CCube()
{
}

GLvoid CCube::scene(GLfloat a){

    glBegin( GL_QUADS );                                                       //Build cube

    glTexCoord2f(0.0f, 0.0f); glVertex3d( a, a, a);           //#1 side of cube
    glTexCoord2f(1.0f, 0.0f); glVertex3d(-a, a, a);
    glTexCoord2f(1.0f, 1.0f); glVertex3d(-a,-a, a);
    glTexCoord2f(0.0f, 1.0f); glVertex3d( a,-a, a);

    glTexCoord2f(0.0f, 0.0f); glVertex3d(-a, a, a);           //#2 side
    glTexCoord2f(1.0f, 0.0f); glVertex3d(-a, a,-a);
    glTexCoord2f(1.0f, 1.0f); glVertex3d(-a,-a,-a);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(-a,-a, a);

    glTexCoord2f(0.0f, 0.0f); glVertex3d(-a, a,-a);           //#3 side
    glTexCoord2f(1.0f, 0.0f); glVertex3d( a, a,-a);
    glTexCoord2f(1.0f, 1.0f); glVertex3d( a,-a,-a);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(-a,-a,-a);

    glTexCoord2f(0.0f, 0.0f); glVertex3d( a, a,-a);           //#4 side
    glTexCoord2f(1.0f, 0.0f); glVertex3d( a, a, a);
    glTexCoord2f(1.0f, 1.0f); glVertex3d( a,-a, a);
    glTexCoord2f(0.0f, 1.0f); glVertex3d( a,-a,-a);

    glTexCoord2f(0.0f, 0.0f); glVertex3d(-a, a, a);           //#5 side
    glTexCoord2f(1.0f, 0.0f); glVertex3d( a, a, a);
    glTexCoord2f(1.0f, 1.0f); glVertex3d( a, a,-a);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(-a, a,-a);

    glTexCoord2f(0.0f, 0.0f); glVertex3d(-a,-a, a);           //#6 side
    glTexCoord2f(1.0f, 0.0f); glVertex3d( a,-a, a);
    glTexCoord2f(1.0f, 1.0f); glVertex3d( a,-a,-a);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(-a,-a,-a);

    glEnd();                                                                    //End of building


}

GLvoid CCube::LoadGLTextures(){

    imTexture.load(":/t1.bmp");
    imTexture = QGLWidget::convertToGLFormat(imTexture);

    glGenTextures(1, texture);

    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)imTexture.width(), (GLsizei)imTexture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, imTexture.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);     // задана линейная фильтрация вблизи
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);     // задана линейная фильтрация вдали

//    imTexture.load(":/t2.jpg");
//    imTexture = QGLWidget::convertToGLFormat(imTexture);

//    glBindTexture(GL_TEXTURE_2D, texture[1]);
//    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)imTexture.width(), (GLsizei)imTexture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, imTexture.bits());

//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    // линейная фильтрация вблизи
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);    // линейная фильтрация вдали


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);  // при фильтрации игнорируются тексели, выходящие за границу текстуры для s координаты
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);  // при фильтрации игнорируются тексели, выходящие за границу текстуры для t координаты
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 		  // цвет текселя полностью замещает цвет фрагмента фигуры

}
