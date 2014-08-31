#ifndef CSTAR_H
#define CSTAR_H

#include <QGLWidget>
#include <algorithm>
#include <math.h>


struct stStar{

    int r, g, b;                            //color of star
    GLfloat distance;                       //distance from (0,0,00 to star
    GLfloat angle;                          //angle (from 0 to 360)

};


class CStar : public QGLWidget{

    Q_OBJECT

public:
    CStar();

    GLvoid initGL();
    GLvoid scene(bool twinkle, GLfloat tilt, GLfloat zoom);
    GLvoid LoadGLTextures();

private:

    GLfloat spin;

    stStar pStar[50];
    GLuint texture[1];  QImage imTexture;

};

#endif // CSTAR_H
