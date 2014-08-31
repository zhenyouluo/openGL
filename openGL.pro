#-------------------------------------------------
#
# Project created by QtCreator 2014-07-23T02:00:50
#
#-------------------------------------------------

QT          += core gui
QT          += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = openGL
TEMPLATE = app


SOURCES     += main/main.cpp\
               main/mainwindow.cpp \
               wopengl/cube3d.cpp \
               wopengl/world3d.cpp


HEADERS     += main/mainwindow.h \
               wopengl/cube3d.h \
               wopengl/world3d.h


FORMS       += main/mainwindow.ui

RESOURCES   += res/res.qrc\

