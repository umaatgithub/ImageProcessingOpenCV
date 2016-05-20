#ifndef IMAGEEDGEFILTER_H
#define IMAGEEDGEFILTER_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "qtopencvbridge.h"

class ImageEdgeFilter : public QObject
{
    Q_OBJECT
public:
    //Constructor & Destructor
    explicit ImageEdgeFilter(QObject *parent = 0);
    ~ImageEdgeFilter(){ delete qtOpenCVBridge; }

    //Function declarations of edge detectors
    QImage* applyCannysEdgeDetector(QImage* inputImage) const;
    QImage* applySobelEdgeDetector(QImage* inputImage) const;
    QImage* applyScharrEdgeDetector(QImage* inputImage) const;

protected:
    //Pointer to QtOpenCVBridge for image conversion between QImage and cv::Mat
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // IMAGEEDGEFILTER_H
