#include "imagescaling.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize all the member variables
 *                     of the class
 *
 **************************************************************************/
ImageScaling::ImageScaling(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image to scale down
 *                     const int &percentage - Percentage of scale down
 * Return type       : QImage* - Output image after scale down
 * Functionality     : Function to scale down the input image for the given
 *                     percentage and returns the scaled down image
 ******************************************************************************/
QImage *ImageScaling::applyScaleDown(QImage *inputImage, const int &percentage)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    resize(inputMat, outputMat, cv::Size(inputMat.cols-round(inputMat.cols*(percentage/100.)), inputMat.rows-round(inputMat.rows*(percentage/100.))));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image to scale up
 *                     const int &percentage - Percentage of scale up
 * Return type       : QImage* - Output image after scale up
 * Functionality     : Function to scale up the input image for the given
 *                     percentage and returns the scaled up image
 ******************************************************************************/
QImage *ImageScaling::applyScaleUp(QImage *inputImage, const int &percentage)
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    resize(inputMat, outputMat, cv::Size(inputMat.cols+round(inputMat.cols*(percentage/100.)), inputMat.rows+round(inputMat.rows*(percentage/100.))));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}
