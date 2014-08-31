#include "main/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(800, 600);

    screen = new QGLWidget(this);
    screen->setGeometry(170, 20, 610, 560);

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

void MainWindow::clickButton0(){

    if (b[0] == false)
        cube.show();

    if (b[0] == true)
        cube.close();

    b[0] =! b[0];
}

void MainWindow::clickButton1(){

    if (b[1] == false)
        w3d.show();

    if (b[1] == true)
        w3d.close();

    b[1] =! b[1];
}

