#ifndef IMAGESMOOTHENINGFILTER_H
#define IMAGESMOOTHENINGFILTER_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "qtopencvbridge.h"

class ImageSmootheningFilter : public QObject
{
    Q_OBJECT
public:
    //Constructor & Destructor
    explicit ImageSmootheningFilter(QObject *parent = 0);
    ~ImageSmootheningFilter(){ delete qtOpenCVBridge; }

    //Function declarations of smoothening filters
    QImage* applyNormalizedBoxFilter(QImage* inputImage, const int &radius, const bool &roiFlag=false, QRect* roiRect=NULL) const;
    QImage* applyGaussianFilter(QImage* inputImage, const int &radius, const bool &roiFlag=false, QRect* roiRect=NULL) const;
    QImage* applyMedianFilter(QImage* inputImage, const int &radius, const bool &roiFlag=false, QRect* roiRect=NULL) const;
    QImage* applyBilateralFilter(QImage* inputImage, const int &radius, const bool &roiFlag=false, QRect* roiRect=NULL) const;

protected:
    //Pointer to QtOpenCVBridge for image conversion between QImage and cv::Mat
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // IMAGESMOOTHENINGFILTER_H
