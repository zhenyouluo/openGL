#ifndef CCUBE_H
#define CCUBE_H

#include <QGLWidget>

class CCube : public QGLWidget{

    Q_OBJECT

public:
    CCube();

    GLvoid scene(GLfloat a);
    GLvoid LoadGLTextures();

private:
    GLuint texture[1];  QImage imTexture;

};

#endif // CCUBE_H
