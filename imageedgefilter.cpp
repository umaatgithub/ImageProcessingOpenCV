#include "imageedgefilter.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize all the member variables
 *                     of the class
 *
 **************************************************************************/
ImageEdgeFilter::ImageEdgeFilter(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

/***************************************************************************
 * Input argument(s) : QImage *inputImage - Input image for the filter
 * Return type       : QImage* - Output image after Canny edge detection
 * Functionality     : Function to apply Canny's edge detection on the
 *                     given input image and returns the processed image
 **************************************************************************/
QImage *ImageEdgeFilter::applyCannysEdgeDetector(QImage *inputImage) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    if(inputMat.type() == CV_8UC4 || inputMat.type() == CV_8UC3){
        cv::cvtColor(inputMat, inputMat, CV_BGR2GRAY);
    }
    Canny( inputMat, outputMat, 100, 200, 3, true);
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

/***************************************************************************
 * Input argument(s) : QImage *inputImage - Input image for the filter
 * Return type       : QImage* - Output image after Sobel edge detection
 * Functionality     : Function to apply Sobel edge detection on the
 *                     given input image and returns the processed image
 **************************************************************************/
QImage *ImageEdgeFilter::applySobelEdgeDetector(QImage *inputImage) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    if(inputMat.type() == CV_8UC4 || inputMat.type() == CV_8UC3){
        cv::cvtColor(inputMat, inputMat, CV_BGR2GRAY);
    }
    cv::Mat gradientX, gradientY;
    cv::Mat absGradientX, absGradientY;

    Sobel( inputMat, gradientX, CV_8UC1, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT );
    convertScaleAbs( gradientX, absGradientX );

    Sobel( inputMat, gradientY, CV_8UC1, 0, 1, 3, 1, 0, cv::BORDER_DEFAULT );
    convertScaleAbs( gradientY, absGradientY );

    addWeighted( absGradientX, 0.5, absGradientY, 0.5, 0, outputMat );
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

/***************************************************************************
 * Input argument(s) : QImage *inputImage - Input image for the filter
 * Return type       : QImage* - Output image after Scharr edge detection
 * Functionality     : Function to apply Scharr edge detection on the
 *                     given input image and returns the processed image
 **************************************************************************/
QImage *ImageEdgeFilter::applyScharrEdgeDetector(QImage *inputImage) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    if(inputMat.type() == CV_8UC4 || inputMat.type() == CV_8UC3){
        cv::cvtColor(inputMat, inputMat, CV_BGR2GRAY);
    }
    cv::Mat gradientX, gradientY;
    cv::Mat absGradientX, absGradientY;

    // Gradient X
    Scharr( inputMat, gradientX, CV_8UC1, 1, 0, 1, 0, cv::BORDER_DEFAULT );
    convertScaleAbs( gradientX, absGradientX );

    // Gradient Y
    Scharr( inputMat, gradientY, CV_8UC1, 0, 1, 1, 0, cv::BORDER_DEFAULT );
    convertScaleAbs( gradientY, absGradientY );

    // Total Gradient (approximate)
    addWeighted( absGradientX, 0.5, absGradientY, 0.5, 0, outputMat );
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

