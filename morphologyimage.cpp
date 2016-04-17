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

QImage MorphologyImage::Mat2QImage(const cv::Mat &mat)
{
    if(mat.type()==CV_8UC4){
        QImage dest((const uchar *) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB32);
        dest.bits();
        return dest;
    }
    else if(mat.type()==CV_8UC1){
        static QVector<QRgb>  sColorTable;
        if ( sColorTable.isEmpty() ){
            for ( int i = 0; i < 256; ++i )
                sColorTable.push_back( qRgb( i, i, i ) );
        }
        QImage dest((const uchar *) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        dest.setColorTable(sColorTable);
        dest.bits();
        return dest;
    }

}

cv::Mat MorphologyImage::QImage2Mat(const QImage& image)
{
    if(image.format()==QImage::Format_RGB32){
        cv::Mat mat( image.height(), image.width(), CV_8UC4, (uchar*)image.bits(), image.bytesPerLine() );
        return mat;
    }
    else if(image.format()==QImage::Format_Indexed8){
        cv::Mat mat( image.height(), image.width(), CV_8UC1, (uchar*)image.bits(), image.bytesPerLine() );
        return mat;
    }


}
