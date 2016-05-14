#include "imageprocessingtoolwidget.h"

ImageProcessingToolWidget::ImageProcessingToolWidget(QString name, QWidget *parent) : QWidget(parent),
    toolName(name), inputImage(new QImage), outputImage(new QImage), roiRect(new QRect)
{

}

QImage *ImageProcessingToolWidget::getInputImage() const
{
    return inputImage;
}

void ImageProcessingToolWidget::setInputImage(QImage *value)
{
    inputImage = value;
    emit inputImageChanged(value);
}

QImage *ImageProcessingToolWidget::getOutputImage() const
{
    return outputImage;
}

void ImageProcessingToolWidget::setOutputImage(QImage *value)
{
    outputImage = value;
    emit outputImageChanged(value);
}

void ImageProcessingToolWidget::updateInputImage(QImage *image)
{
    setInputImage(image);
}

void ImageProcessingToolWidget::updateROI(QRect *rect)
{
    setRoiRect(rect);
}

QRect *ImageProcessingToolWidget::getRoiRect() const
{
    return roiRect;
}

void ImageProcessingToolWidget::setRoiRect(QRect *value)
{
    if(value->width()!=0 && value->height()!=0){
        roiRect = value;
        emit roiRectUpdated();
    }
}

bool ImageProcessingToolWidget::isRoiRectValid()
{
    int imageWidth = getInputImage()->width();
    int imageHeight = getInputImage()->height();
    int rectX = getRoiRect()->x();
    int rectY = getRoiRect()->y();
    int rectWidth = getRoiRect()->width();
    int rectHeight = getRoiRect()->height();
    if(rectX>imageWidth || rectY>imageHeight){
        return false;
    }
    if(rectWidth-rectX>=0 && rectWidth-rectX > imageWidth-rectX){
        return false;
    }
    else if(rectWidth-rectX<0 && rectX-rectWidth > rectX){
        return false;
    }
    if(rectHeight-rectY>=0 && rectHeight-rectY > imageHeight-rectY){
        return false;
    }
    else if(rectHeight-rectY<0 && rectY-rectHeight > rectY){
        return false;
    }
    return true;
}

QString ImageProcessingToolWidget::getToolName() const
{
    return toolName;
}

void ImageProcessingToolWidget::setToolName(const QString &value)
{
    toolName = value;
}
