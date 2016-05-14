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
    imagechangehistory.cpp \
    infowidget.cpp \
    qtopencvbridge.cpp \
    displaylabel.cpp \
    imageprocessingtoolwidget.cpp \
    imageedgefilter.cpp \
    imageedgefiltertool.cpp \
    imagemorphology.cpp \
    imagemorphologytool.cpp \
    imagerotation.cpp \
    imagerotationtool.cpp \
    imagetransformation.cpp \
    imagetransformationtool.cpp \
    imagesmootheningfilter.cpp \
    imagesmootheningfiltertool.cpp \
    imagescaling.cpp \
    imagescalingtool.cpp

HEADERS  += mainwindow.h \
    centralgridlayoutwidget.h \
    imagedisplaywidget.h \
    imageprocessingtoolboxwidget.h \
    imagechangehistory.h \
    infowidget.h \
    qtopencvbridge.h \
    displaylabel.h \
    imageprocessingtoolwidget.h \
    imageedgefilter.h \
    imageedgefiltertool.h \
    imagemorphology.h \
    imagemorphologytool.h \
    imagerotation.h \
    imagerotationtool.h \
    imagetransformation.h \
    imagetransformationtool.h \
    imagesmootheningfilter.h \
    imagesmootheningfiltertool.h \
    imagescaling.h \
    imagescalingtool.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
