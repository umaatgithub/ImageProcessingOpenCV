#include "morphologyimage.h"

MorphologyImage::MorphologyImage(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

QImage MorphologyImage::applyErode(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    //imshow("Input Matrix", inputMat);
    cv::Mat outputMat = inputMat.clone();
    erode( inputMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    //imshow("Output Matrix", outputMat);
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage MorphologyImage::applyDilate(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    dilate( inputMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage MorphologyImage::applyOpening(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat tempMat = inputMat.clone();
    cv::Mat outputMat = inputMat.clone();
    erode( inputMat, tempMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    dilate( tempMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage MorphologyImage::applyClosing(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat tempMat = inputMat.clone();
    cv::Mat outputMat = inputMat.clone();
    dilate( inputMat, tempMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    erode( tempMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

