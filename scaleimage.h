#ifndef SCALEIMAGE_H
#define SCALEIMAGE_H

#include <QObject>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

class ScaleImage : public QObject
{
    Q_OBJECT
public:
    explicit ScaleImage(QObject *parent = 0);
    QImage applyScaleDown(QImage const& inputImage, int radius);
    QImage applyScaleUp(QImage const& inputImage, int radius);

protected:
    QImage Mat2QImage(cv::Mat const& mat);
    cv::Mat QImage2Mat(QImage const& image);
};

#endif // SCALEIMAGE_H
