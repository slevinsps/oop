#-------------------------------------------------
#
# Project created by QtCreator 2018-02-16T22:26:21
#
#-------------------------------------------------

QT       += core gui
QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled2
TEMPLATE = app
LIBS += -lglu32 -lopengl32
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    actions.cpp \
    controlling.cpp \
    load_save_model.cpp \
    draw_model.cpp \
    file_func.cpp

HEADERS += \
        mainwindow.h \
    actions.h \
    constants.h \
    controlling.h \
    errors.h \
    model.h \
    load_save_model.h \
    draw_model.h \
    file_func.h \
    file_structs.h \
    my_scene.h \
    point.h

FORMS += \
        mainwindow.ui

RESOURCES +=
