#ifndef IMAGEEDGEFILTER_H
#define IMAGEEDGEFILTER_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "qtopencvbridge.h"

class ImageEdgeFilter : public QObject
{
    Q_OBJECT
public:
    explicit ImageEdgeFilter(QObject *parent = 0);
    ~ImageEdgeFilter(){}

    QImage* applyCannysEdgeDetector(QImage* inputImage, int radius);
    QImage* applySobelEdgeDetector(QImage* inputImage, int radius);
    QImage* applyScharrEdgeDetector(QImage* inputImage, int radius);

protected:
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // IMAGEEDGEFILTER_H
