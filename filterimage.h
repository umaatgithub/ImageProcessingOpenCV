#ifndef FILTERIMAGE_H
#define FILTERIMAGE_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "qtopencvbridge.h"

using namespace cv;

class FilterImage : public QObject
{
    Q_OBJECT
public:
    explicit FilterImage(QObject *parent = 0);
    ~FilterImage();

    QImage applyNormalizedBoxFilter(QImage const& inputImage, int radius) const;
    QImage applyGaussianFilter(QImage const& inputImage, int radius) const;
    QImage applyMedianFilter(QImage const& inputImage, int radius) const;
    QImage applyBilateralFilter(QImage const& inputImage, int radius) const;

protected:
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // FILTERIMAGE_H
