#include "scaleimage.h"

ScaleImage::ScaleImage(QObject *parent) : QObject(parent)
{

}

QImage ScaleImage::applyScaleDown(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat outputMat ;
    resize(inputMat, outputMat, Size(inputMat.cols-round(inputMat.cols*(radius/100.)), inputMat.rows-round(inputMat.rows*(radius/100.))));
    return Mat2QImage(outputMat);
}

QImage ScaleImage::applyScaleUp(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat outputMat ;
    resize(inputMat, outputMat, Size(inputMat.cols+round(inputMat.cols*(radius/100.)), inputMat.rows+round(inputMat.rows*(radius/100.))));
    return Mat2QImage(outputMat);
}

QImage ScaleImage::Mat2QImage(const cv::Mat &mat)
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

cv::Mat ScaleImage::QImage2Mat(const QImage& image)
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

