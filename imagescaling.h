#ifndef IMAGESCALING_H
#define IMAGESCALING_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "qtopencvbridge.h"

class ImageScaling : public QObject
{
    Q_OBJECT
public:
    explicit ImageScaling(QObject *parent = 0);
    ~ImageScaling(){}

    QImage* applyScaleDown(QImage* inputImage, int radius);
    QImage* applyScaleUp(QImage* inputImage, int radius);

protected:
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // IMAGESCALING_H
