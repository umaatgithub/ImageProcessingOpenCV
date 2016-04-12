#include "imageprocessingtoolboxwidget.h"

ImageProcessingToolBoxWidget::ImageProcessingToolBoxWidget(QWidget *parent) : QWidget(parent),
    layout(new QGridLayout), toolBox(new QToolBox), filterToolSet(new FilterWidget),
    secondToolSet(new QWidget), thirdToolSet(new QWidget), fourthToolSet(new QWidget)
{
    setupImageProcessingToolBox();
}

ImageProcessingToolBoxWidget::~ImageProcessingToolBoxWidget()
{
    delete fourthToolSet;
    delete thirdToolSet;
    delete secondToolSet;
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
    toolBox->addItem(secondToolSet,QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),"Page2");
    toolBox->addItem(thirdToolSet,QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),"Page3");
    toolBox->addItem(fourthToolSet,QIcon(QString("C:\\Users\\Umamaheswaran\\Desktop\\button.png")),"Page4");
    toolBox->layout()->setSpacing(0);
}

FilterWidget *ImageProcessingToolBoxWidget::getFilterToolSet() const
{
    return filterToolSet;
}

