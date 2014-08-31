#include "main/mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(800, 600);

    screen = new cube3d(this);
    screen->setGeometry(170, 20, 620, 550);

    Button[0] = new QPushButton(this);
    Button[1] = new QPushButton(this);

    Button[0]->setGeometry(20, 20 , 150, 50);   Button[0]->setText("Cube");
    Button[1]->setGeometry(20, 90, 150, 50);   Button[1]->setText("World");

    connect(Button[0], SIGNAL(clicked()), this, SLOT(clickButton0()));
    connect(Button[0], SIGNAL(clicked()), this, SLOT(clickButton1()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){

    cube->keyPressEvent(event);

}

void MainWindow::clickButton0(){

        cube->show();

}

void MainWindow::clickButton1(){

        w3d.show();

}

