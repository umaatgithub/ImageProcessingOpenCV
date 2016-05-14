#include "imageprocessingtoolboxwidget.h"

ImageProcessingToolBoxWidget::ImageProcessingToolBoxWidget(QWidget *parent) : QWidget(parent),
    layout(new QGridLayout), toolBox(new QToolBox), filterToolSet(new FilterWidget(QString("Image Smoothening Filter"))),
    morphologyToolSet(new MorphologyWidget(QString("Morphology Operation"))), transformationToolSet(new ImageTransformationTool(QString("Image Transformation"))),
    rotationToolSet(new RotationWidget(QString("Image Rotation"))), scaleToolSet(new ImageScalingTool(QString("Image Scaling"))), edgeDetectionToolSet(new ImageEdgeFilterTool(QString("Edge Detection")))
{
    setupImageProcessingToolBox();
}

ImageProcessingToolBoxWidget::~ImageProcessingToolBoxWidget()
{
    delete edgeDetectionToolSet;
    delete scaleToolSet;
    delete rotationToolSet;
    delete transformationToolSet;
    delete morphologyToolSet;
    delete filterToolSet;
    delete toolBox;
    delete layout;
}

void ImageProcessingToolBoxWidget::setupImageProcessingToolBox()
{
    layout->addWidget(toolBox,0,0);
    layout->setColumnStretch(0,1);
    layout->setRowStretch(0,1);
    setLayout(layout);

    toolBox->addItem(rotationToolSet, QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),rotationToolSet->getToolName());
    toolBox->addItem(scaleToolSet, QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),"Image Scaling");
    toolBox->addItem(filterToolSet, QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),"Image Smoothing Filter");
    toolBox->addItem(transformationToolSet, QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),"Image Transformation");
    toolBox->addItem(morphologyToolSet, QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),"Morphology Operation");
    toolBox->addItem(edgeDetectionToolSet, QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),"Edge Detection");
    toolBox->layout()->setSpacing(0);
}

FilterWidget *ImageProcessingToolBoxWidget::getFilterToolSet() const
{
    return filterToolSet;
}

MorphologyWidget *ImageProcessingToolBoxWidget::getMorphologyToolSet() const
{
    return morphologyToolSet;
}

ImageTransformationTool *ImageProcessingToolBoxWidget::getTransformationToolSet() const
{
    return transformationToolSet;
}

RotationWidget *ImageProcessingToolBoxWidget::getRotationToolSet() const
{
    return rotationToolSet;
}

ImageScalingTool *ImageProcessingToolBoxWidget::getScaleToolSet() const
{
    return scaleToolSet;
}

ImageEdgeFilterTool *ImageProcessingToolBoxWidget::getEdgeDetectionToolSet() const
{
    return edgeDetectionToolSet;
}

