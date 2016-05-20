#include "imageprocessingtoolboxwidget.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize all the member variables
 *                     of the class and to setup the UI
 *
 **************************************************************************/
ImageProcessingToolBoxWidget::ImageProcessingToolBoxWidget(QWidget *parent) : QWidget(parent),
    layout(new QGridLayout), toolBox(new QToolBox), filterToolSet(new ImageSmootheningFilterTool(QString("Image Smoothening Filter"))),
    morphologyToolSet(new ImageMorphologyTool(QString("Morphology Operation"))), transformationToolSet(new ImageTransformationTool(QString("Image Transformation"))),
    rotationToolSet(new ImageRotationTool(QString("Image Rotation"))), scaleToolSet(new ImageScalingTool(QString("Image Scaling"))), edgeDetectionToolSet(new ImageEdgeFilterTool(QString("Edge Detection")))
{
    setupImageProcessingToolBox();
}

/***************************************************************************
 * Input argument(s) : NIL
 * Return type       : NIL
 * Functionality     : Destructor to delete all the pointer variables
 *
 **************************************************************************/
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

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Function to setup the UI for the tool box
 *
 **************************************************************************/
void ImageProcessingToolBoxWidget::setupImageProcessingToolBox()
{
    layout->addWidget(toolBox,0,0);
    layout->setColumnStretch(0,1);
    layout->setRowStretch(0,1);
    setLayout(layout);

    toolBox->addItem(rotationToolSet, QIcon(":/toolbarIcons/toolseticon"),rotationToolSet->getToolName());
    toolBox->addItem(scaleToolSet, QIcon(":/toolbarIcons/toolseticon"),scaleToolSet->getToolName());
    toolBox->addItem(filterToolSet, QIcon(":/toolbarIcons/toolseticon"),filterToolSet->getToolName());
    toolBox->addItem(transformationToolSet, QIcon(":/toolbarIcons/toolseticon"),transformationToolSet->getToolName());
    toolBox->addItem(morphologyToolSet, QIcon(":/toolbarIcons/toolseticon"),morphologyToolSet->getToolName());
    toolBox->addItem(edgeDetectionToolSet, QIcon(":/toolbarIcons/toolseticon"),edgeDetectionToolSet->getToolName());
    toolBox->layout()->setSpacing(0);
}

ImageSmootheningFilterTool *ImageProcessingToolBoxWidget::getFilterToolSet() const
{
    return filterToolSet;
}

ImageMorphologyTool *ImageProcessingToolBoxWidget::getMorphologyToolSet() const
{
    return morphologyToolSet;
}

ImageTransformationTool *ImageProcessingToolBoxWidget::getTransformationToolSet() const
{
    return transformationToolSet;
}

ImageRotationTool *ImageProcessingToolBoxWidget::getRotationToolSet() const
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

