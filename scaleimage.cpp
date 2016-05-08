#include "scaleimage.h"

ScaleImage::ScaleImage(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

QImage ScaleImage::applyScaleDown(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    resize(inputMat, outputMat, Size(inputMat.cols-round(inputMat.cols*(radius/100.)), inputMat.rows-round(inputMat.rows*(radius/100.))));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage ScaleImage::applyScaleUp(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    resize(inputMat, outputMat, Size(inputMat.cols+round(inputMat.cols*(radius/100.)), inputMat.rows+round(inputMat.rows*(radius/100.))));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}
