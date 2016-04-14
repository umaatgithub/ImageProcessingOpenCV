#include "transformationimage.h"

TransformationImage::TransformationImage(QObject *parent) : QObject(parent)
{

}

QImage TransformationImage::applyRotateLeft(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    //imshow("Input Matrix", inputMat);
    cv::Mat outputMat ;
    Point2f pt(inputMat.cols/2., inputMat.rows/2.);
    Mat r = getRotationMatrix2D(pt, radius, 1.0);
    warpAffine(inputMat, outputMat, r, Size(inputMat.cols, inputMat.rows));
    //imshow("Output Matrix", outputMat);
    return Mat2QImage(outputMat);
}

QImage TransformationImage::applyRotateRight(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat outputMat ;
    Point2f pt(inputMat.cols/2., inputMat.rows/2.);
    Mat r = getRotationMatrix2D(pt, 360-radius, 1.0);
    warpAffine(inputMat, outputMat, r, Size(inputMat.cols, inputMat.rows));
    return Mat2QImage(outputMat);
}

QImage TransformationImage::applyScaleDown(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat outputMat ;
    resize(inputMat, outputMat, Size(inputMat.cols-round(inputMat.cols*(radius/100.)), inputMat.rows-round(inputMat.rows*(radius/100.))));
    return Mat2QImage(outputMat);
}

QImage TransformationImage::applyScaleUp(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat outputMat ;
    resize(inputMat, outputMat, Size(inputMat.cols+round(inputMat.cols*(radius/100.)), inputMat.rows+round(inputMat.rows*(radius/100.))));
    return Mat2QImage(outputMat);
}

QImage TransformationImage::Mat2QImage(const cv::Mat &src)
{
    QImage dest((const uchar *) src.data, src.cols, src.rows, src.step, QImage::Format_RGB32);
    dest.bits();
    return dest;

}

cv::Mat TransformationImage::QImage2Mat(const QImage& image)
{

    cv::Mat matv( image.height(), image.width(), CV_8UC4, (uchar*)image.bits(), image.bytesPerLine() );
    return matv;

}
