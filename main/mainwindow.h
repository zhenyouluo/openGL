#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPushButton>
#include <QGLWidget>
#include "wopengl/cube3d.h"
#include "wopengl/world3d.h"

#define BUTTONS 2


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void keyPressEvent(QKeyEvent* );

    cube3d * cube;
    world3d w3d;


    QGLWidget* screen;

    QPushButton* Button[BUTTONS];

public slots:

    void clickButton0();
    void clickButton1();

};

#endif // MAINWINDOW_H
