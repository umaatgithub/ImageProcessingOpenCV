#ifndef IMAGEROTATION_H
#define IMAGEROTATION_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "qtopencvbridge.h"

class ImageRotation : public QObject
{
    Q_OBJECT
public:
    //Constructor & Destructor
    explicit ImageRotation(QObject *parent = 0);
    ~ImageRotation(){ delete qtOpenCVBridge; }

    //Function declarations of rotation functions
    QImage* applyAntiClockwiseRotation(QImage* inputImage, const int &angle) const;
    QImage* applyClockwiseRotation(QImage* inputImage, const int &angle) const;

protected:
    //Pointer to QtOpenCVBridge for image conversion between QImage and cv::Mat
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // IMAGEROTATION_H
