#include "centralgridlayoutwidget.h"

CentralGridLayoutWidget::CentralGridLayoutWidget(QWidget *parent) : QWidget(parent),
    layout(new QGridLayout), imageDisplayWidget(new ImageDisplayWidget),
    imageProcessingToolBoxWidget(new ImageProcessingToolBoxWidget), infoWidget(new InfoWidget)
{
    setupWidget();
}

CentralGridLayoutWidget::~CentralGridLayoutWidget()
{
    delete imageProcessingToolBoxWidget;
    delete imageDisplayWidget;
    delete infoWidget;
    delete layout;
}

void CentralGridLayoutWidget::setupWidget()
{
  layout->addWidget(imageDisplayWidget,0,0,3,2);
  layout->addWidget(imageProcessingToolBoxWidget,0,2);
  layout->addWidget(infoWidget,1,2);

  layout->setColumnMinimumWidth(0,300);
  layout->setColumnMinimumWidth(2,250);

  layout->setRowMinimumHeight(0,270);
  layout->setRowMinimumHeight(1,200);

  layout->setColumnStretch(0,1);

  setLayout(layout);
}

ImageDisplayWidget *CentralGridLayoutWidget::getImageDisplayWidget() const
{
    return imageDisplayWidget;
}

ImageProcessingToolBoxWidget *CentralGridLayoutWidget::getImageProcessingToolBoxWidget() const
{
    return imageProcessingToolBoxWidget;
}

QWidget *CentralGridLayoutWidget::getInfoWidget() const
{
    return infoWidget;
}
