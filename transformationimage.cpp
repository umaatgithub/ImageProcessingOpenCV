#include "transformationimage.h"

TransformationImage::TransformationImage(QObject *parent) : QObject(parent)
{

}

QImage TransformationImage::applyBinaryTransformation(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat outputMat ;
    cv::threshold(inputMat, outputMat, radius, 255, THRESH_BINARY);
    return Mat2QImage(outputMat);
}

QImage TransformationImage::applyGrayscaleTransformation(const QImage &inputImage)
{
    if(inputImage.format()==QImage::Format_Indexed8){
        return inputImage;
    }
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat outputMat ;
    cv::cvtColor(inputMat, outputMat, CV_BGR2GRAY);
    return Mat2QImage(outputMat);
}





QImage TransformationImage::Mat2QImage(const cv::Mat &mat)
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

cv::Mat TransformationImage::QImage2Mat(const QImage& image)
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
