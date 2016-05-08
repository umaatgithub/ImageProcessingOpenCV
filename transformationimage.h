#ifndef TRANSFORMATIONIMAGE_H
#define TRANSFORMATIONIMAGE_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "qtopencvbridge.h"

using namespace cv;

class TransformationImage : public QObject
{
    Q_OBJECT
public:
    explicit TransformationImage(QObject *parent = 0);
    QImage applyBinaryTransformation(QImage const& inputImage, const int& radius);
    QImage applyGrayscaleTransformation(QImage const& inputImage);
    QImage applyNegativeTransformation(QImage const& inputImage, const int& radius);

protected:
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // TRANSFORMATIONIMAGE_H
