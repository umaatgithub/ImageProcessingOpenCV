#ifndef ROTATIONIMAGE_H
#define ROTATIONIMAGE_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "qtopencvbridge.h"

using namespace cv;

class RotationImage : public QObject
{
    Q_OBJECT
public:
    explicit RotationImage(QObject *parent = 0);
    QImage applyAntiClockwiseRotation(QImage const& inputImage, int radius);
    QImage applyClockwiseRotation(QImage const& inputImage, int radius);

protected:
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // ROTATIONIMAGE_H
