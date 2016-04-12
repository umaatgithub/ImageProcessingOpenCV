#-------------------------------------------------
#
# Project created by QtCreator 2016-03-25T20:47:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageProcessingOpenCV
TEMPLATE = app

INCLUDEPATH += C:/Programs/opencv_build/install/include
LIBS += "C:/Programs/opencv_build/bin/*.dll"

SOURCES += main.cpp\
        mainwindow.cpp \
    centralgridlayoutwidget.cpp \
    imagedisplaywidget.cpp \
    imageprocessingtoolboxwidget.cpp \
    filterimage.cpp \
    filterwidget.cpp \
    imagechangehistory.cpp

HEADERS  += mainwindow.h \
    centralgridlayoutwidget.h \
    imagedisplaywidget.h \
    imageprocessingtoolboxwidget.h \
    filterimage.h \
    filterwidget.h \
    imagechangehistory.h

FORMS    += mainwindow.ui
