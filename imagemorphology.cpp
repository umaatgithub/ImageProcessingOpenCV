#include "imagemorphology.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize all the member variables
 *                     of the class
 *
 **************************************************************************/
ImageMorphology::ImageMorphology(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image for the operation
 *                     const int &radius - Radius of structuring element
 *                     const bool &roiFlag - Flag to enable region of interest
 *                     QRect *roiRect - Region of  interest rectangle
 * Return type       : QImage* - Output image after erosion
 * Functionality     : Function to apply erode morphology operation on the
 *                     given input image and returns the processed image
 *****************************************************************************/
QImage *ImageMorphology::applyErode(QImage *inputImage, const int &radius, const bool &roiFlag, QRect *roiRect) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        erode( croppedInputMat, croppedOutputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    else{
        erode( inputMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image for the operation
 *                     const int &radius - Radius of structuring element
 *                     const bool &roiFlag - Flag to enable region of interest
 *                     QRect *roiRect - Region of  interest rectangle
 * Return type       : QImage* - Output image after dilation
 * Functionality     : Function to apply dilate morphology operation on the
 *                     given input image and returns the processed image
 *****************************************************************************/
QImage *ImageMorphology::applyDilate(QImage *inputImage, const int &radius, const bool &roiFlag, QRect *roiRect) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        dilate( croppedInputMat, croppedOutputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    else{
        dilate( inputMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image for the operation
 *                     const int &radius - Radius of structuring element
 *                     const bool &roiFlag - Flag to enable region of interest
 *                     QRect *roiRect - Region of  interest rectangle
 * Return type       : QImage* - Output image after opening
 * Functionality     : Function to apply opening morphology operation on the
 *                     given input image and returns the processed image
 *****************************************************************************/
QImage *ImageMorphology::applyOpening(QImage *inputImage, const int &radius, const bool &roiFlag, QRect *roiRect) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat tempMat = inputMat.clone();
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedTempMat(tempMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        erode( croppedInputMat, croppedTempMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
        dilate( croppedTempMat, croppedOutputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    else{
        erode( inputMat, tempMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
        dilate( tempMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image for the operation
 *                     const int &radius - Radius of structuring element
 *                     const bool &roiFlag - Flag to enable region of interest
 *                     QRect *roiRect - Region of  interest rectangle
 * Return type       : QImage* - Output image after closing
 * Functionality     : Function to apply closing morphology operation on the
 *                     given input image and returns the processed image
 *****************************************************************************/
QImage *ImageMorphology::applyClosing(QImage *inputImage, const int &radius, const bool &roiFlag, QRect *roiRect) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat tempMat = inputMat.clone();
    cv::Mat outputMat = inputMat.clone();
    if(roiFlag == true){
        cv::Rect regionOfInterest(roiRect->x(), roiRect->y(), roiRect->width(), roiRect->height());
        cv::Mat croppedInputMat(inputMat, regionOfInterest);
        cv::Mat croppedTempMat(tempMat, regionOfInterest);
        cv::Mat croppedOutputMat(outputMat, regionOfInterest);
        dilate( croppedInputMat, croppedTempMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
        erode( croppedTempMat, croppedOutputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    else{
        dilate( inputMat, tempMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
        erode( tempMat, outputMat, getStructuringElement(cv::MORPH_RECT, cv::Size(radius, radius)));
    }
    return qtOpenCVBridge->Mat2QImage(outputMat);
}
