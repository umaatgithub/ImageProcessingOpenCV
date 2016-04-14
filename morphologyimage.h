#ifndef MORPHOLOGYIMAGE_H
#define MORPHOLOGYIMAGE_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

class MorphologyImage : public QObject
{
    Q_OBJECT
public:
    explicit MorphologyImage(QObject *parent = 0);
    QImage applyErode(QImage const& inputImage, int radius);
    QImage applyDilate(QImage const& inputImage, int radius);
    QImage applyOpening(QImage const& inputImage, int radius);
    QImage applyClosing(QImage const& inputImage, int radius);

protected:
    QImage Mat2QImage(cv::Mat const& src);
    cv::Mat QImage2Mat(QImage const& image);
};

#endif // MORPHOLOGYIMAGE_H
