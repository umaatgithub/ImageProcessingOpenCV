#ifndef FILTERIMAGE_H
#define FILTERIMAGE_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

class FilterImage : public QObject
{
    Q_OBJECT
public:
    explicit FilterImage(QObject *parent = 0);

    QImage applyNormalizedBoxFilter(QImage const& inputImage, int radius);
    QImage applyGaussianFilter(QImage const& inputImage, int radius);
    QImage applyMedianFilter(QImage const& inputImage, int radius);
    QImage applyBilateralFilter(QImage const& inputImage, int radius);

protected:
    QImage Mat2QImage(cv::Mat const& mat);
    cv::Mat QImage2Mat(QImage const& image);
};

#endif // FILTERIMAGE_H
