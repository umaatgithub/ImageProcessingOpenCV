#include "imagetransformation.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize all the member variables
 *                     of the class
 *
 **************************************************************************/
ImageTransformation::ImageTransformation(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image to binarize
 *                     const int &percentage - Percentage threshold
 * Return type       : QImage* - Output image after binarizing
 * Functionality     : Function to binarize the input image for the given
 *                     percentage threshold and returns the processed image
 ******************************************************************************/
QImage *ImageTransformation::applyBinaryTransformation(QImage *inputImage, const int &percentage) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    cv::threshold(inputMat, outputMat, (percentage/100.0)*255, 255, cv::THRESH_BINARY);
    return qtOpenCVBridge->Mat2QImage(outputMat);
}


/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image to transform
 * Return type       : QImage* - Output image after binarizing
 * Functionality     : Function to transform the input image to grayscale
 *                     and returns the processed image
 ******************************************************************************/
QImage *ImageTransformation::applyGrayscaleTransformation(QImage *inputImage) const
{
    if(inputImage->format()==QImage::Format_Indexed8 || inputImage->format()==QImage::Format_Grayscale8){
        return inputImage;
    }
    else if(inputImage->format()==QImage::Format_RGB32){
        cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
        cv::Mat outputMat ;
        cv::cvtColor(inputMat, outputMat, CV_BGR2GRAY);
        return qtOpenCVBridge->Mat2QImage(outputMat);
    }
    throw "Format not supported.";
}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image to transform
 *                     const int &percentage - Percentage threshold
 * Return type       : QImage* - Output image after negative transformation
 * Functionality     : Function to apply negative transformation on the input
 *                     image for the given percentage threshold and returns
 *                     the processed image
 ******************************************************************************/
QImage *ImageTransformation::applyNegativeTransformation(QImage *inputImage, const int &percentage) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    cv::threshold(inputMat, outputMat, (percentage/100.0)*255, 255, cv::THRESH_BINARY_INV);
    return qtOpenCVBridge->Mat2QImage(outputMat);
}
