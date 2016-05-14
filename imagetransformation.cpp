#include "imagetransformation.h"

ImageTransformation::ImageTransformation(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

QImage *ImageTransformation::applyBinaryTransformation(QImage *inputImage,const int &radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    cv::threshold(inputMat, outputMat, (radius/100.0)*255, 255, cv::THRESH_BINARY);
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage *ImageTransformation::applyGrayscaleTransformation(QImage *inputImage)
{
    if(inputImage->format()==QImage::Format_Indexed8 || inputImage->format()==QImage::Format_Grayscale8){
        return inputImage;
    }
    else if(inputImage->format()==QImage::Format_RGB32){
        cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
        cv::Mat outputMat ;
        cv::cvtColor(inputMat, outputMat, CV_BGR2GRAY);
        return qtOpenCVBridge->Mat2QImage(outputMat);
    }
    throw "Format not supported.";
}

QImage *ImageTransformation::applyNegativeTransformation(QImage *inputImage, const int &radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    cv::threshold(inputMat, outputMat, (radius/100.0)*255, 255, cv::THRESH_BINARY_INV);
    return qtOpenCVBridge->Mat2QImage(outputMat);
}
