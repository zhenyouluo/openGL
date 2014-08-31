#ifndef WORLD3D_H
#define WORLD3D_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QDebug>
#include <vector>
#include <iostream>

#include <gl.h>
#include <glu.h>

//struct SECTOR{

//    int nTriangles;
//    TRIANGLE* tringle;

//};

//struct TRIANGLE{

//    VERTEX* vertex[3];

//};

//struct VERTEX{

//    float x, y, z;
//    float u, v;

//};



class world3d : public QGLWidget{

    Q_OBJECT

public:
    world3d();

    GLvoid initializeGL();
    GLvoid LoadGLTextures();

    GLvoid resizeGL(int w, int h);

    GLvoid paintGL(); GLvoid scene();

    void LoadFiles();

private:

    int numTriangles;
    char oneLine[255];




    GLfloat a;

    GLuint texture[1]; QImage tImage;

    GLfloat mat_specular[4]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[1]={50.0};
    GLfloat light_position[4]={1.0,1.0,1.0,0.0};                         //Diffuse light
    GLfloat white_light[4]={1.0,1.0,1.0,1.0};                             //Position of light


public slots:

};

#endif // WORLD3D_H
