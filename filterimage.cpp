#include "filterimage.h"

FilterImage::FilterImage(QObject *parent) : QObject(parent)
{

}

QImage FilterImage::applyNormalizedBoxFilter(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    //imshow("Input Matrix", inputMat);
    cv::Mat outputMat = inputMat.clone();
    blur( inputMat, outputMat, cv::Size(radius, radius), cv::Point(-1,-1));
    //imshow("Output Matrix", outputMat);
    return Mat2QImage(outputMat);
}

QImage FilterImage::applyGaussianFilter(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    GaussianBlur( inputMat, outputMat, cv::Size(radius, radius), 0, 0);
    return Mat2QImage(outputMat);
}

QImage FilterImage::applyMedianFilter(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    medianBlur(inputMat, outputMat, radius);
    return Mat2QImage(outputMat);
}

QImage FilterImage::applyBilateralFilter(const QImage &inputImage, int radius)
{
    cv::Mat inputMat = QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    bilateralFilter(inputMat, outputMat, radius, radius*2.0, radius/2.0);
    return Mat2QImage(outputMat);
}

QImage FilterImage::Mat2QImage(const cv::Mat &mat)
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

//QImage FilterImage::Mat2QImage(const cv::Mat &mat)
//{
    //cv::Mat temp; // make the same cv::Mat
         //cvtColor(src, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
/*         QImage dest((const uchar *) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB32);
         dest.bits(); */// enforce deep copy, see documentation
         // of QImage::QImage ( const uchar * data, int width, int height, Format format )
 //        return dest;
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
//}

cv::Mat FilterImage::QImage2Mat(const QImage& image)
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
//{
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
//    cv::Mat matv( image.height(), image.width(), CV_8UC4, (uchar*)image.bits(), image.bytesPerLine() );
//    return matv;

//}



