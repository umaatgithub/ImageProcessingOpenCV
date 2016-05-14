#ifndef IMAGEMORPHOLOGY_H
#define IMAGEMORPHOLOGY_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "qtopencvbridge.h"

class ImageMorphology : public QObject
{
    Q_OBJECT
public:
    explicit ImageMorphology(QObject *parent = 0);
    ~ImageMorphology(){}

    QImage* applyErode(QImage* inputImage, int radius, bool roiFlag=false, QRect* roiRect=NULL);
    QImage* applyDilate(QImage* inputImage, int radius, bool roiFlag=false, QRect* roiRect=NULL);
    QImage* applyOpening(QImage* inputImage, int radius, bool roiFlag=false, QRect* roiRect=NULL);
    QImage* applyClosing(QImage* inputImage, int radius, bool roiFlag=false, QRect* roiRect=NULL);

protected:
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // IMAGEMORPHOLOGY_H
