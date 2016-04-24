#ifndef ROTATIONIMAGE_H
#define ROTATIONIMAGE_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

class RotationImage : public QObject
{
    Q_OBJECT
public:
    explicit RotationImage(QObject *parent = 0);
    QImage applyRotateLeft(QImage const& inputImage, int radius);
    QImage applyRotateRight(QImage const& inputImage, int radius);

protected:
    QImage Mat2QImage(cv::Mat const& mat);
    cv::Mat QImage2Mat(QImage const& image);
};

#endif // ROTATIONIMAGE_H
