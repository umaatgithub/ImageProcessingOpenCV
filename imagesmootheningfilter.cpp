#include "imagesmootheningfilter.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize all the member variables
 *                     of the class
 *
 **************************************************************************/
ImageSmootheningFilter::ImageSmootheningFilter(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image for the filter
 *                     const int &radius - Radius of structuring element
 *                     const bool &roiFlag - Flag to enable region of interest
 *                     QRect *roiRect - Region of  interest rectangle
 * Return type       : QImage* - Output image after box filtering
 * Functionality     : Function to apply normalized box filter on the
 *                     given input image and returns the processed image
 ******************************************************************************/
QImage *ImageSmootheningFilter::applyNormalizedBoxFilter(QImage *inputImage, const int &radius, const bool &roiFlag, QRect *roiRect) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        blur( croppedInputMat, croppedOutputMat, cv::Size(radius, radius), cv::Point(-1,-1));
    }
    else{
        blur( inputMat, outputMat, cv::Size(radius, radius), cv::Point(-1,-1));
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image for the filter
 *                     const int &radius - Radius of structuring element
 *                     const bool &roiFlag - Flag to enable region of interest
 *                     QRect *roiRect - Region of  interest rectangle
 * Return type       : QImage* - Output image after gaussian filtering
 * Functionality     : Function to apply gaussian filter on the given
 *                     input image and returns the processed image
 ******************************************************************************/
QImage *ImageSmootheningFilter::applyGaussianFilter(QImage *inputImage, const int &radius, const bool &roiFlag, QRect *roiRect) const
{
    cv::Mat inputMat =  qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        GaussianBlur( croppedInputMat, croppedOutputMat, cv::Size(radius, radius), 0, 0);
    }
    else{
        GaussianBlur( inputMat, outputMat, cv::Size(radius, radius), 0, 0);
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image for the filter
 *                     const int &radius - Radius of structuring element
 *                     const bool &roiFlag - Flag to enable region of interest
 *                     QRect *roiRect - Region of  interest rectangle
 * Return type       : QImage* - Output image after median filtering
 * Functionality     : Function to apply median filter on the given
 *                     input image and returns the processed image
 ******************************************************************************/
QImage *ImageSmootheningFilter::applyMedianFilter(QImage *inputImage, const int &radius, const bool &roiFlag, QRect *roiRect) const
{
    cv::Mat inputMat =  qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        medianBlur(croppedInputMat, croppedOutputMat, radius);
    }
    else{
        medianBlur(inputMat, outputMat, radius);
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image for the filter
 *                     const int &radius - Radius of structuring element
 *                     const bool &roiFlag - Flag to enable region of interest
 *                     QRect *roiRect - Region of  interest rectangle
 * Return type       : QImage* - Output image after bilateral filtering
 * Functionality     : Function to apply bilateral filter on the given
 *                     input image and returns the processed image
 ******************************************************************************/
QImage *ImageSmootheningFilter::applyBilateralFilter(QImage *inputImage, const int &radius, const bool &roiFlag, QRect *roiRect) const
{
    cv::Mat inputMat =  qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        bilateralFilter(croppedInputMat, croppedOutputMat, radius, radius*2.0, radius/2.0);
    }
    else{
        bilateralFilter(inputMat, outputMat, radius, radius*2.0, radius/2.0);
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}
