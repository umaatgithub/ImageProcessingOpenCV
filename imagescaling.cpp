#include "imagescaling.h"

ImageScaling::ImageScaling(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

QImage *ImageScaling::applyScaleDown(QImage *inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    resize(inputMat, outputMat, cv::Size(inputMat.cols-round(inputMat.cols*(radius/100.)), inputMat.rows-round(inputMat.rows*(radius/100.))));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage *ImageScaling::applyScaleUp(QImage *inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    resize(inputMat, outputMat, cv::Size(inputMat.cols+round(inputMat.cols*(radius/100.)), inputMat.rows+round(inputMat.rows*(radius/100.))));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}
