#include "centralgridlayoutwidget.h"

CentralGridLayoutWidget::CentralGridLayoutWidget(QWidget *parent) : QWidget(parent),
    layout(new QGridLayout), imageDisplayWidget(new ImageDisplayWidget),
    imageProcessingToolBoxWidget(new ImageProcessingToolBoxWidget)
{
    setupWidget();
}

CentralGridLayoutWidget::~CentralGridLayoutWidget()
{
    delete imageProcessingToolBoxWidget;
    delete imageDisplayWidget;
    delete layout;
}

void CentralGridLayoutWidget::setupWidget()
{
  layout->addWidget(imageDisplayWidget,0,0,1,2);
  layout->addWidget(imageProcessingToolBoxWidget,0,2);

  layout->setColumnMinimumWidth(0,300);
  layout->setColumnMinimumWidth(2,300);

  layout->setRowMinimumHeight(0,300);

  layout->setColumnStretch(0,1);

  setLayout(layout);
}
