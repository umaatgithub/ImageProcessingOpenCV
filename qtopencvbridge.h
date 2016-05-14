#ifndef QTOPENCVBRIDGE_H
#define QTOPENCVBRIDGE_H

#include <QObject>
#include <QImage>
#include <QRgb>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

class QtOpenCVBridge : public QObject
{
    Q_OBJECT
public:
    explicit QtOpenCVBridge(QObject *parent = 0);
    ~QtOpenCVBridge();

    QImage *Mat2QImage(cv::Mat const& mat);
    cv::Mat QImage2Mat(QImage* image);
};

#endif // QTOPENCVBRIDGE_H
