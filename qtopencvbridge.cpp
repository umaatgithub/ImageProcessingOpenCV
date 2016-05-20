#include "qtopencvbridge.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize all object
 *
 **************************************************************************/
QtOpenCVBridge::QtOpenCVBridge(QObject *parent) : QObject(parent)
{

}

/***************************************************************************
 * Input argument(s) : const cv::Mat &mat - Input Mat to convert
 * Return type       : QImage* - Output converted image
 * Functionality     : Function to convert cv::Mat to QImage. It gives the
 *                     image with the format corresponding to the Mat type.
 *                     It throws a "Format not supported." exception if
 *                     conversion is not supported.
 *
 **************************************************************************/
QImage *QtOpenCVBridge::Mat2QImage(const cv::Mat &mat)
{
    if(mat.type()==CV_8UC4){
        QImage *dest = new QImage((const uchar *) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB32);
        dest->bits();
        return dest;
    }
    else if(mat.type()==CV_8UC1){
        static QVector<QRgb>  sColorTable;
        if ( sColorTable.isEmpty() ){
            for ( int i = 0; i < 256; ++i )
                sColorTable.push_back( qRgb( i, i, i ) );
        }
        QImage *dest = new QImage((const uchar *) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        dest->setColorTable(sColorTable);
        dest->bits();
        return dest;
    }
    else if(mat.type()==CV_8UC3){
        QImage *dest = new QImage((const uchar *) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        dest->bits();
        return new QImage(dest->rgbSwapped());
    }
    throw " Format not supported.";
}

/***************************************************************************
 * Input argument(s) : QImage *image - Input image to convert
 * Return type       : cv::Mat - Output converted Mat
 * Functionality     : Function to convert QImage to cv::Mat . It gives the
 *                     Mat with the type corresponding to the QImage format.
 *                     It throws a "Format not supported." exception if
 *                     conversion is not supported.
 **************************************************************************/
cv::Mat QtOpenCVBridge::QImage2Mat(QImage *image)
{
    if(image->format()==QImage::Format_RGB32){
        cv::Mat mat( image->height(), image->width(), CV_8UC4, (uchar*)image->bits(), image->bytesPerLine() );
        return mat;
    }
    else if(image->format()==QImage::Format_Indexed8 || image->format()==QImage::Format_Grayscale8){
        cv::Mat mat( image->height(), image->width(), CV_8UC1, (uchar*)image->bits(), image->bytesPerLine() );
        return mat;
    }
    else if(image->format()==QImage::Format_RGB888){
        QImage swappedImage = image->rgbSwapped();
        cv::Mat mat( swappedImage.height(), swappedImage.width(), CV_8UC3, (uchar*)swappedImage.bits(), swappedImage.bytesPerLine() );
        return mat;
    }
    throw " Format not supported.";
}
