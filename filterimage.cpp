#include "filterimage.h"

FilterImage::FilterImage(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

FilterImage::~FilterImage()
{

}

QImage FilterImage::applyNormalizedBoxFilter(const QImage &inputImage, int radius) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    //imshow("Input Matrix", inputMat);
    cv::Mat outputMat = inputMat.clone();
    blur( inputMat, outputMat, cv::Size(radius, radius), cv::Point(-1,-1));
    //imshow("Output Matrix", outputMat);
    return  qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage FilterImage::applyGaussianFilter(const QImage &inputImage, int radius) const
{
    cv::Mat inputMat =  qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();

    cv::Rect regionOfInterest(10, 10, 300, 300);
    //cv::Mat croppedImage = outputMat(regionOfInterest);
    cv::Mat croppedInputImage(inputMat, regionOfInterest);
    cv::Mat croppedOutputImage(outputMat, regionOfInterest);


    GaussianBlur( croppedInputImage, croppedOutputImage, cv::Size(radius, radius), 0, 0);
    return  qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage FilterImage::applyMedianFilter(const QImage &inputImage, int radius) const
{
    cv::Mat inputMat =  qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    medianBlur(inputMat, outputMat, radius);
    return  qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage FilterImage::applyBilateralFilter(const QImage &inputImage, int radius) const
{
    cv::Mat inputMat =  qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    bilateralFilter(inputMat, outputMat, radius, radius*2.0, radius/2.0);
    return  qtOpenCVBridge->Mat2QImage(outputMat);
}
