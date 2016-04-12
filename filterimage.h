#ifndef FILTERIMAGE_H
#define FILTERIMAGE_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

class FilterImage : public QObject
{
    Q_OBJECT
public:
    explicit FilterImage(QObject *parent = 0);

    QImage normalizedBoxFilter(QImage const& inputImage, int radius);
    QImage gaussianFilter(QImage const& inputImage);
    QImage medianFilter(QImage const& inputImage);
    QImage bilateralFilter(QImage const& inputImage);

protected:
    QImage Mat2QImage(cv::Mat const& src);
    cv::Mat QImage2Mat(QImage const& image);
};

#endif // FILTERIMAGE_H
