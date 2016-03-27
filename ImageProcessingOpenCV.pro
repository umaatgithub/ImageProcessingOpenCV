#-------------------------------------------------
#
# Project created by QtCreator 2016-03-25T20:47:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageProcessingOpenCV
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    centralgridlayoutwidget.cpp \
    imagedisplaywidget.cpp \
    imageprocessingtoolboxwidget.cpp

HEADERS  += mainwindow.h \
    centralgridlayoutwidget.h \
    imagedisplaywidget.h \
    imageprocessingtoolboxwidget.h

FORMS    += mainwindow.ui
