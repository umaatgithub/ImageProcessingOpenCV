#include "filterimage.h"

FilterImage::FilterImage(QObject *parent) : QObject(parent)
{

}

QImage FilterImage::normalizedBoxFilter(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    //imshow("Input Matrix", inputMat);
    cv::Mat outputMat = inputMat.clone();
    blur( inputMat, outputMat, cv::Size( radius, radius  ), cv::Point(-1,-1));
    //imshow("Output Matrix", outputMat);
    return Mat2QImage(outputMat);
}

QImage FilterImage::gaussianFilter(const QImage &inputImage)
{
    return inputImage;
}

QImage FilterImage::medianFilter(const QImage &inputImage)
{
    return inputImage;
}

QImage FilterImage::bilateralFilter(const QImage &inputImage)
{
    return inputImage;
}

QImage FilterImage::Mat2QImage(const cv::Mat &src)
{
    //cv::Mat temp; // make the same cv::Mat
         //cvtColor(src, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
         QImage dest((const uchar *) src.data, src.cols, src.rows, src.step, QImage::Format_RGB32);
         dest.bits(); // enforce deep copy, see documentation
         // of QImage::QImage ( const uchar * data, int width, int height, Format format )
         return dest;
    //https://asmaloney.com/2013/11/code/converting-between-cvmat-and-qimage-or-qpixmap/
    //http://stackoverflow.com/questions/17127762/cvmat-to-qimage-and-back
//    switch(src.type()){
//        case CV_8UC4:
//        {
//            return QImage( (const uchar *)src.data, src.cols, src.rows, src.step, QImage::Format_RGB32 );
//        }
//        case CV_8UC3:
//        {
//            return QImage( (const uchar *)src.data, src.cols, src.rows, src.step, QImage::Format_RGB888 );
//        }
//        case CV_8UC1:
//        {
//            static QVector<QRgb>  sColorTable;
//            if ( sColorTable.isEmpty() ){
//                for ( int i = 0; i < 256; ++i )
//                    sColorTable.push_back( qRgb( i, i, i ) );
//            }
//            QImage image( (const uchar *)src.data, src.cols, src.rows, src.step, QImage::Format_Indexed8 );
//            image.setColorTable( sColorTable );
//            return image;
//        }
//        default:
//            break;
//    }

//    return QImage();
}

cv::Mat FilterImage::QImage2Mat(const QImage& image)
{
//    cv::Mat result(src.height(),src.width(),CV_8UC4,(uchar*)src.bits(),src.bytesPerLine());
//         cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)
//         cvtColor(tmp, result,CV_BGR2RGB);
//         return result;

//    switch(image.format()){
//        case QImage::Format_RGB32:
//        {
//            return cv::Mat( image.height(), image.width(), CV_8UC4, (uchar*)image.bits(), image.bytesPerLine() );

//        }
//        case QImage::Format_RGB888:
//        {
//            QImage swappedImage = image.rgbSwapped();
//            return cv::Mat( swappedImage.height(), swappedImage.width(), CV_8UC3, (uchar*)swappedImage.bits(), swappedImage.bytesPerLine() );
//        }
//        case QImage::Format_Indexed8:
//        {
//            return cv::Mat( image.height(), image.width(), CV_8UC1, (uchar*)image.bits(), image.bytesPerLine() );
//        }
//        default:
//            break;
//    }

//    return cv::Mat();
    cv::Mat matv( image.height(), image.width(), CV_8UC4, (uchar*)image.bits(), image.bytesPerLine() );
    return matv;

}


