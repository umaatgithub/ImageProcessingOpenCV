#include "imagerotation.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize all the member variables
 *                     of the class
 *
 **************************************************************************/
ImageRotation::ImageRotation(QObject *parent) : QObject(parent),
    qtOpenCVBridge(new QtOpenCVBridge)
{

}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image to rotate
 *                     const int &angle - Angle of rotation
 * Return type       : QImage* - Output image after anti-clockwise rotation
 * Functionality     : Function to rotate the image anti-clockwise for the given
 *                     angle on the input image and returns the rotated image
 ******************************************************************************/
QImage *ImageRotation::applyAntiClockwiseRotation(QImage* inputImage, const int &angle) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    cv::Point2f pt(inputMat.cols/2., inputMat.rows/2.);
    cv::Mat r = getRotationMatrix2D(pt, angle, 1.0);
    warpAffine(inputMat, outputMat, r, cv::Size(inputMat.cols, inputMat.rows));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}

/******************************************************************************
 * Input argument(s) : QImage *inputImage - Input image to rotate
 *                     const int &angle - Angle of rotation
 * Return type       : QImage* - Output image after clockwise rotation
 * Functionality     : Function to rotate the image clockwise for the given
 *                     angle on the input image and returns the rotated image
 ******************************************************************************/
QImage *ImageRotation::applyClockwiseRotation(QImage* inputImage, const int &angle) const
{
    cv::Mat inputMat = qtOpenCVBridge->QImage2Mat(inputImage);
    cv::Mat outputMat ;
    cv::Point2f pt(inputMat.cols/2., inputMat.rows/2.);
    cv::Mat r = getRotationMatrix2D(pt, 360-angle, 1.0);
    warpAffine(inputMat, outputMat, r, cv::Size(inputMat.cols, inputMat.rows));
    return qtOpenCVBridge->Mat2QImage(outputMat);
}
