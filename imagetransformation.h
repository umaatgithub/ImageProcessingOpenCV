#ifndef IMAGETRANSFORMATION_H
#define IMAGETRANSFORMATION_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "qtopencvbridge.h"

class ImageTransformation : public QObject
{
    Q_OBJECT
public:
    explicit ImageTransformation(QObject *parent = 0);
    ~ImageTransformation(){}

    QImage* applyBinaryTransformation(QImage* inputImage, const int& radius);
    QImage* applyGrayscaleTransformation(QImage* inputImage);
    QImage* applyNegativeTransformation(QImage* inputImage, const int& radius);

protected:
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // IMAGETRANSFORMATION_H
