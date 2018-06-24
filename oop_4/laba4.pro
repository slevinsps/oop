#-------------------------------------------------
#
# Project created by QtCreator 2017-05-27T21:36:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = laba4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lift_but.cpp \
    lift_cab.cpp \
    lift_contr.cpp \
    lift_door.cpp \
    lift.cpp

HEADERS  += mainwindow.h \
    times.h \
    lift_but.h \
    lift_cab.h \
    lift_contr.h \
    lift_door.h \
    lift.h

FORMS    += mainwindow.ui
