#include "imageedgefilter.h"

ImageEdgeFilter::ImageEdgeFilter(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

QImage *ImageEdgeFilter::applyCannysEdgeDetector(QImage *inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    if(inputMat.type() == CV_8UC4 || inputMat.type() == CV_8UC3){
        cv::cvtColor(inputMat, inputMat, CV_BGR2GRAY);
    }
    Canny( inputMat, outputMat, 100, 200, 3, true);
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage *ImageEdgeFilter::applySobelEdgeDetector(QImage *inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    if(inputMat.type() == CV_8UC4 || inputMat.type() == CV_8UC3){
        cv::cvtColor(inputMat, inputMat, CV_BGR2GRAY);
    }
    cv::Mat gradientX, gradientY;
    cv::Mat absGradientX, absGradientY;

    /// Gradient X
    //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
    Sobel( inputMat, gradientX, CV_8UC1, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT );
    convertScaleAbs( gradientX, absGradientX );

    /// Gradient Y
    //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
    Sobel( inputMat, gradientY, CV_8UC1, 0, 1, 3, 1, 0, cv::BORDER_DEFAULT );
    convertScaleAbs( gradientY, absGradientY );

    /// Total Gradient (approximate)
    addWeighted( absGradientX, 0.5, absGradientY, 0.5, 0, outputMat );
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

QImage *ImageEdgeFilter::applyScharrEdgeDetector(QImage *inputImage, int radius)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    if(inputMat.type() == CV_8UC4 || inputMat.type() == CV_8UC3){
        cv::cvtColor(inputMat, inputMat, CV_BGR2GRAY);
    }
    cv::Mat gradientX, gradientY;
    cv::Mat absGradientX, absGradientY;

    /// Gradient X
    //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
    Scharr( inputMat, gradientX, CV_8UC1, 1, 0, 1, 0, cv::BORDER_DEFAULT );
    convertScaleAbs( gradientX, absGradientX );

    /// Gradient Y
    //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
    Scharr( inputMat, gradientY, CV_8UC1, 0, 1, 1, 0, cv::BORDER_DEFAULT );
    convertScaleAbs( gradientY, absGradientY );

    /// Total Gradient (approximate)
    addWeighted( absGradientX, 0.5, absGradientY, 0.5, 0, outputMat );
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

