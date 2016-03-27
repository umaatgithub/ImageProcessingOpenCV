#include "imagedisplaywidget.h"
#include <QGridLayout>

ImageDisplayWidget::ImageDisplayWidget(QWidget *parent) : QWidget(parent),
    layout(new QGridLayout),scrollArea(new QScrollArea),
    imageDisplayLabel(new QLabel)
{
    setupDisplayArea();
}

ImageDisplayWidget::~ImageDisplayWidget()
{
    delete imageDisplayLabel;
    delete scrollArea;
    delete layout;
}

void ImageDisplayWidget::setupDisplayArea()
{

    layout->addWidget(scrollArea,0,0);
    layout->setColumnStretch(0,1);
    layout->setRowStretch(0,1);
    setLayout(layout);

    scrollArea->setWidget(imageDisplayLabel);
    scrollArea->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);

    QImage imageObject;
    imageObject.load("D:\\Photos\\2015-11-22\\019.JPG");
    imageDisplayLabel->setMinimumWidth(scrollArea->width());
    imageDisplayLabel->setMinimumHeight(scrollArea->height());
    imageDisplayLabel->setPixmap(QPixmap::fromImage(imageObject).scaled(scrollArea->width(),scrollArea->height(),Qt::KeepAspectRatio));

}

