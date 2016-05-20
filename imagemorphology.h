#ifndef IMAGEMORPHOLOGY_H
#define IMAGEMORPHOLOGY_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "qtopencvbridge.h"

class ImageMorphology : public QObject
{
    Q_OBJECT
public:
    //Constructor & Destructor
    explicit ImageMorphology(QObject *parent = 0);
    ~ImageMorphology(){ delete qtOpenCVBridge; }

    //Function declarations of morphology operators
    QImage* applyErode(QImage* inputImage, const int &radius, const bool &roiFlag=false, QRect* roiRect=NULL) const;
    QImage* applyDilate(QImage* inputImage, const int &radius, const bool &roiFlag=false, QRect* roiRect=NULL) const;
    QImage* applyOpening(QImage* inputImage, const  int &radius, const bool &roiFlag=false, QRect* roiRect=NULL) const;
    QImage* applyClosing(QImage* inputImage, const int &radius, const bool &roiFlag=false, QRect* roiRect=NULL) const;

protected:
    //Pointer to QtOpenCVBridge for image conversion between QImage and cv::Mat
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // IMAGEMORPHOLOGY_H
