#include "imagesmootheningfilter.h"

ImageSmootheningFilter::ImageSmootheningFilter(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

QImage *ImageSmootheningFilter::applyNormalizedBoxFilter(QImage *inputImage, int radius, bool roiFlag, QRect *roiRect) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        blur( croppedInputMat, croppedOutputMat, cv::Size(radius, radius), cv::Point(-1,-1));
    }
    else{
        blur( inputMat, outputMat, cv::Size(radius, radius), cv::Point(-1,-1));
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage *ImageSmootheningFilter::applyGaussianFilter(QImage *inputImage, int radius, bool roiFlag, QRect *roiRect) const
{
    cv::Mat inputMat =  qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        GaussianBlur( croppedInputMat, croppedOutputMat, cv::Size(radius, radius), 0, 0);
    }
    else{
        GaussianBlur( inputMat, outputMat, cv::Size(radius, radius), 0, 0);
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage *ImageSmootheningFilter::applyMedianFilter(QImage *inputImage, int radius, bool roiFlag, QRect *roiRect) const
{
    cv::Mat inputMat =  qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        medianBlur(croppedInputMat, croppedOutputMat, radius);
    }
    else{
        medianBlur(inputMat, outputMat, radius);
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage *ImageSmootheningFilter::applyBilateralFilter(QImage *inputImage, int radius, bool roiFlag, QRect *roiRect) const
{
    cv::Mat inputMat =  qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        bilateralFilter(croppedInputMat, croppedOutputMat, radius, radius*2.0, radius/2.0);
    }
    else{
        bilateralFilter(inputMat, outputMat, radius, radius*2.0, radius/2.0);
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}
