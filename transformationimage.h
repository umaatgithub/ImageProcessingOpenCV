#ifndef TRANSFORMATIONIMAGE_H
#define TRANSFORMATIONIMAGE_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

class TransformationImage : public QObject
{
    Q_OBJECT
public:
    explicit TransformationImage(QObject *parent = 0);
    QImage applyBinaryTransformation(QImage const& inputImage, int radius);
    QImage applyGrayscaleTransformation(QImage const& inputImage);

protected:
    QImage Mat2QImage(cv::Mat const& mat);
    cv::Mat QImage2Mat(QImage const& image);
};

#endif // TRANSFORMATIONIMAGE_H
