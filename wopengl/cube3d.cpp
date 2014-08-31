#include "cube3d.h"
#include <QtOpenGL>

cube3d::cube3d(){
    a = 0.4f;

    rot_x = 0;    rot_y = 0;
    speed_x = 1;  speed_y = 1;

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), SLOT(slot_rotate()));
    timer->start(50);   timer_w = true;
}

void cube3d::initializeGL(){                                                   //Create background with black colour

    LoadGLTextures();															//Load textures
    glEnable(GL_TEXTURE_2D);													//Parameters of texture
    qglClearColor(Qt::black);													//Phone color
    glClearDepth(1.0);                                                          //Creating of depth buffer

    glDepthFunc(GL_LESS);                                                       //Parameters of depth


    glBlendFunc(GL_SRC_ALPHA, GL_ONE);                                          //Parameters of transparency
//    glEnable(GL_BLEND);


    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);                    //Create background light
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  white_light);                       //Create diffuse light
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);                           //Create light position

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glEnable(GL_DEPTH_TEST);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


}

GLvoid cube3d::resizeGL(int nWidth, int nHeight){                              //Resise of window

    glViewport(0, 0, nWidth, nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}

GLvoid cube3d::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glTranslatef(-0.1f, -0.1f, -0.1f);

    scene();

    swapBuffers();
    glFlush();
}

GLvoid cube3d::scene(){

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

void cube3d::rotate(){

    rot_x += speed_x;   if (rot_x >= 360) rot_x = 0;
    rot_y += speed_y;   if (rot_y >= 360) rot_y = 0;

                                                                                qDebug("rotate\n");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glRotated(rot_x, 1, 0, 0);
    glRotated(rot_y, 0, 1, 0);

    paintGL();                                                                  //Redrawning
}

void cube3d::slot_rotate(){
    rotate();
}

void cube3d::LoadGLTextures(){

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
//    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 		  // цвет текселя полностью замещает цвет фрагмента фигуры


}

void cube3d::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Space)
        if (timer_w == true){
            timer->stop();   timer_w = false;
        }
        else{
            timer->start();  timer_w = true;
        }

    if (event->key() == Qt::Key_L){

        light =! light;
        if (light) glEnable(GL_LIGHTING);
        else glDisable(GL_LIGHTING);

    }

    if (event->key() == Qt::Key_Right)
        speed_y += 0.2f;

    if (event->key() == Qt::Key_Left)
        speed_y -= 0.2f;

    if (event->key() == Qt::Key_Up)
        speed_x += 0.2f;

    if (event->key() == Qt::Key_Down)
        speed_x -= 0.2f;

    if (event->key() == Qt::Key_T)
        if (transparency){
            glEnable(GL_BLEND);
            glDisable(GL_DEPTH_TEST);
            transparency = false;
        }
        else {
            glEnable(GL_DEPTH_TEST);
            glDisable(GL_BLEND);
            transparency = true;
        }


}
