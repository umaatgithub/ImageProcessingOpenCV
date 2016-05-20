#ifndef IMAGESCALING_H
#define IMAGESCALING_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "qtopencvbridge.h"

class ImageScaling : public QObject
{
    Q_OBJECT
public:
    //Constructor & Destructor
    explicit ImageScaling(QObject *parent = 0);
    ~ImageScaling(){ delete qtOpenCVBridge; }

    //Function declarations of scaling functions
    QImage* applyScaleDown(QImage* inputImage, const int &percentage);
    QImage* applyScaleUp(QImage* inputImage, const int &percentage);

protected:
    //Pointer to QtOpenCVBridge for image conversion between QImage and cv::Mat
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // IMAGESCALING_H
