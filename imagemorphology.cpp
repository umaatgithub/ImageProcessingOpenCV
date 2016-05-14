#include "imagemorphology.h"

ImageMorphology::ImageMorphology(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

QImage *ImageMorphology::applyErode(QImage *inputImage, int radius, bool roiFlag, QRect *roiRect)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        erode( croppedInputMat, croppedOutputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    else{
    erode( inputMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage *ImageMorphology::applyDilate(QImage *inputImage, int radius, bool roiFlag, QRect *roiRect)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        dilate( croppedInputMat, croppedOutputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    else{
        dilate( inputMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage *ImageMorphology::applyOpening(QImage *inputImage, int radius, bool roiFlag, QRect *roiRect)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat tempMat = inputMat.clone();
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedTempMat(tempMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        erode( croppedInputMat, croppedTempMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
        dilate( croppedTempMat, croppedOutputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    else{
        erode( inputMat, tempMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
        dilate( tempMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage *ImageMorphology::applyClosing(QImage *inputImage, int radius, bool roiFlag, QRect *roiRect)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat tempMat = inputMat.clone();
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedTempMat(tempMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        dilate( croppedInputMat, croppedTempMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
        erode( croppedTempMat, croppedOutputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    else{
        dilate( inputMat, tempMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
        erode( tempMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

