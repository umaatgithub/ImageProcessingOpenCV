#include "imagerotation.h"

ImageRotation::ImageRotation(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

QImage *ImageRotation::applyAntiClockwiseRotation(QImage* inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    cv::Point2f pt(inputMat.cols/2., inputMat.rows/2.);
    cv::Mat r = getRotationMatrix2D(pt, radius, 1.0);
    warpAffine(inputMat, outputMat, r, cv::Size(inputMat.cols, inputMat.rows));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage *ImageRotation::applyClockwiseRotation(QImage* inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    cv::Point2f pt(inputMat.cols/2., inputMat.rows/2.);
    cv::Mat r = getRotationMatrix2D(pt, 360-radius, 1.0);
    warpAffine(inputMat, outputMat, r, cv::Size(inputMat.cols, inputMat.rows));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}
