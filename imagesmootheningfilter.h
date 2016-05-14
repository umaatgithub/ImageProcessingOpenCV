#ifndef IMAGESMOOTHENINGFILTER_H
#define IMAGESMOOTHENINGFILTER_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "qtopencvbridge.h"

class ImageSmootheningFilter : public QObject
{
    Q_OBJECT
public:
    explicit ImageSmootheningFilter(QObject *parent = 0);
    ~ImageSmootheningFilter(){}

    QImage* applyNormalizedBoxFilter(QImage* inputImage, int radius, bool roiFlag=false, QRect* roiRect=NULL) const;
    QImage* applyGaussianFilter(QImage* inputImage, int radius, bool roiFlag=false, QRect* roiRect=NULL) const;
    QImage* applyMedianFilter(QImage* inputImage, int radius, bool roiFlag=false, QRect* roiRect=NULL) const;
    QImage* applyBilateralFilter(QImage* inputImage, int radius, bool roiFlag=false, QRect* roiRect=NULL) const;

protected:
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // IMAGESMOOTHENINGFILTER_H
