#ifndef EDGEDETECTIONIMAGE_H
#define EDGEDETECTIONIMAGE_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "qtopencvbridge.h"

class EdgeDetectionImage : public QObject
{
    Q_OBJECT
public:
    explicit EdgeDetectionImage(QObject *parent = 0);
    QImage applyCannysEdgeDetector(QImage const& inputImage, int radius);
    QImage applySobelEdgeDetector(QImage const& inputImage, int radius);
    QImage applyScharrEdgeDetector(QImage const& inputImage, int radius);

protected:
    QtOpenCVBridge *qtOpenCVBridge;

};

#endif // EDGEDETECTIONIMAGE_H
