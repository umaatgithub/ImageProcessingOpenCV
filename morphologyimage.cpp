#include "morphologyimage.h"

MorphologyImage::MorphologyImage(QObject *parent) : QObject(parent)
{

}

QImage MorphologyImage::applyErode(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    //imshow("Input Matrix", inputMat);
    cv::Mat outputMat = inputMat.clone();
    erode( inputMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    //imshow("Output Matrix", outputMat);
    return Mat2QImage(outputMat);
}

QImage MorphologyImage::applyDilate(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    dilate( inputMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    return Mat2QImage(outputMat);
}

QImage MorphologyImage::applyOpening(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat tempMat = inputMat.clone();
    cv::Mat outputMat = inputMat.clone();
    erode( inputMat, tempMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    dilate( tempMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    return Mat2QImage(outputMat);
}

QImage MorphologyImage::applyClosing(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat tempMat = inputMat.clone();
    cv::Mat outputMat = inputMat.clone();
    dilate( inputMat, tempMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    erode( tempMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    return Mat2QImage(outputMat);
}

QImage MorphologyImage::Mat2QImage(const cv::Mat &src)
{
    QImage dest((const uchar *) src.data, src.cols, src.rows, src.step, QImage::Format_RGB32);
    dest.bits();
    return dest;

}

cv::Mat MorphologyImage::QImage2Mat(const QImage& image)
{

    cv::Mat matv( image.height(), image.width(), CV_8UC4, (uchar*)image.bits(), image.bytesPerLine() );
    return matv;

}
