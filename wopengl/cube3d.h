#ifndef CUBE3D_H
#define CUBE3D_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <gl.h>
#include <glu.h>

class cube3d : public QGLWidget{

    Q_OBJECT

public:
    cube3d(QWidget * parent = 0);

    void initializeGL();
    GLvoid LoadGLTextures();

    GLvoid resizeGL(int nWidth, int nHeight);

    GLvoid paintGL();
    GLvoid scene();

    void rotate();
    void keyPressEvent(QKeyEvent* );


private:

    GLuint texture[1];  QImage imTexture;

    GLfloat a;
    QTimer* timer;  bool timer_w;

    bool light = false;
    bool transparency = false;

    GLfloat rot_x, rot_y;
    GLfloat speed_x, speed_y;

    GLfloat mat_specular[4]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[1]={50.0};

    GLfloat BackgroundLightConst[4] = { 0.5f, 0.5f, 0.5f, 1.0f };                         //Background light
    GLfloat light_position[4]={1.0,1.0,1.0,0.0};                                          //Diffuse light
    GLfloat white_light[4]={1.0,1.0,1.0,1.0};                                             //Position of light

public slots:
    void slot_rotate();
};

#endif // CUBE3D_H
