#include "centralgridlayoutwidget.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize all the member variables
 *                     of the class and to setup the UI
 *
 **************************************************************************/
CentralGridLayoutWidget::CentralGridLayoutWidget(QWidget *parent) : QWidget(parent),
    layout(new QGridLayout), imageDisplayWidget(new ImageDisplayWidget),
    imageProcessingToolBoxWidget(new ImageProcessingToolBoxWidget), infoWidget(new InfoWidget)
{
    setupWidget();
}

/***************************************************************************
 * Input argument(s) : NIL
 * Return type       : NIL
 * Functionality     : Destructor to delete all the pointer variables
 *
 **************************************************************************/
CentralGridLayoutWidget::~CentralGridLayoutWidget()
{
    delete imageProcessingToolBoxWidget;
    delete imageDisplayWidget;
    delete infoWidget;
    delete layout;
}


/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Function to setup the UI for the central widget
 *
 **************************************************************************/
void CentralGridLayoutWidget::setupWidget()
{
  layout->addWidget(imageDisplayWidget,0,0,3,2);
  layout->addWidget(imageProcessingToolBoxWidget,0,2);
  layout->addWidget(infoWidget,1,2);

  layout->setColumnMinimumWidth(0,300);
  layout->setColumnMinimumWidth(2,250);

  layout->setRowMinimumHeight(0,310);
  layout->setRowMinimumHeight(1,195);

  layout->setColumnStretch(0,1);

  setLayout(layout);
}
