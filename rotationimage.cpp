#include "rotationimage.h"

RotationImage::RotationImage(QObject *parent) : QObject(parent)
{

}

QImage RotationImage::applyRotateLeft(const QImage &inputImage, int radius)
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

QImage RotationImage::applyRotateRight(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat outputMat ;
    Point2f pt(inputMat.cols/2., inputMat.rows/2.);
    Mat r = getRotationMatrix2D(pt, 360-radius, 1.0);
    warpAffine(inputMat, outputMat, r, Size(inputMat.cols, inputMat.rows));
    return Mat2QImage(outputMat);
}

QImage RotationImage::Mat2QImage(const cv::Mat &mat)
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

cv::Mat RotationImage::QImage2Mat(const QImage& image)
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
