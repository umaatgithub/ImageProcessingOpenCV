#ifndef IMAGETRANSFORMATION_H
#define IMAGETRANSFORMATION_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "qtopencvbridge.h"

class ImageTransformation : public QObject
{
    Q_OBJECT
public:
    //Constructor and Destructor
    explicit ImageTransformation(QObject *parent = 0);
    ~ImageTransformation(){ delete qtOpenCVBridge; }

    //Function declarations of transformation functions
    QImage* applyBinaryTransformation(QImage* inputImage, const int& percentage) const;
    QImage* applyGrayscaleTransformation(QImage* inputImage) const;
    QImage* applyNegativeTransformation(QImage* inputImage, const int& percentage) const;

protected:
    //Pointer to QtOpenCVBridge for image conversion between QImage and cv::Mat
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // IMAGETRANSFORMATION_H
