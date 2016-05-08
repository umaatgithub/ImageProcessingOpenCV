#ifndef SCALEIMAGE_H
#define SCALEIMAGE_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "qtopencvbridge.h"

using namespace cv;

class ScaleImage : public QObject
{
    Q_OBJECT
public:
    explicit ScaleImage(QObject *parent = 0);
    QImage applyScaleDown(QImage const& inputImage, int radius);
    QImage applyScaleUp(QImage const& inputImage, int radius);

protected:
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // SCALEIMAGE_H
