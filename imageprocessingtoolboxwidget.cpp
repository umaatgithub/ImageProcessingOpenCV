#include "imageprocessingtoolboxwidget.h"

ImageProcessingToolBoxWidget::ImageProcessingToolBoxWidget(QWidget *parent) : QWidget(parent),
    layout(new QGridLayout), toolBox(new QToolBox), filterToolSet(new FilterWidget),
    morphologyToolSet(new MorphologyWidget), transformationToolSet(new TransformationWidget), fourthToolSet(new QWidget)
{
    setupImageProcessingToolBox();
}

ImageProcessingToolBoxWidget::~ImageProcessingToolBoxWidget()
{
    delete fourthToolSet;
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

    toolBox->addItem(filterToolSet,QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),"Filter Image");
    toolBox->addItem(morphologyToolSet,QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),"Mathematical Morphology");
    toolBox->addItem(transformationToolSet,QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),"Transformation");
    toolBox->addItem(fourthToolSet,QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),"Page4");
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

TransformationWidget *ImageProcessingToolBoxWidget::getTransformationToolSet() const
{
    return transformationToolSet;
}

