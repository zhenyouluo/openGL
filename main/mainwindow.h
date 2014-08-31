#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
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

    cube3d cube;
    world3d w3d;


    QPushButton* Button[BUTTONS];
    bool b[BUTTONS] = { false, false };

public slots:

    void clickButton0();
    void clickButton1();

};

#endif // MAINWINDOW_H
