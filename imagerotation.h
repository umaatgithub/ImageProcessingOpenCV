#ifndef IMAGEROTATION_H
#define IMAGEROTATION_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "qtopencvbridge.h"

class ImageRotation : public QObject
{
    Q_OBJECT
public:
    explicit ImageRotation(QObject *parent = 0);
    ~ImageRotation(){}

    QImage* applyAntiClockwiseRotation(QImage* inputImage, int radius);
    QImage* applyClockwiseRotation(QImage* inputImage, int radius);

protected:
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // IMAGEROTATION_H
