#include "imagedisplaywidget.h"
#include <QGridLayout>

ImageDisplayWidget::ImageDisplayWidget(QWidget *parent) : QWidget(parent),
    layout(new QGridLayout),scrollArea(new QScrollArea),
    imageDisplayLabel(new QLabel), imageZoomSlider(new QSlider)
{
    connect(this, SIGNAL(imageChanged()),this, SLOT(updateDisplayArea()));
    setupDisplayArea();
}

ImageDisplayWidget::~ImageDisplayWidget()
{
    delete imageDisplayLabel;
    delete imageZoomSlider;
    delete scrollArea;
    delete layout;
}

void ImageDisplayWidget::setupDisplayArea()
{

    layout->addWidget(scrollArea,0,0);
    layout->setColumnStretch(0,1);
    layout->setRowStretch(0,1);

    layout->addWidget(imageZoomSlider,1,0);

    setLayout(layout);

    scrollArea->setWidget(imageDisplayLabel);
    scrollArea->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);

    imageZoomSlider->setOrientation(Qt::Horizontal);
    imageZoomSlider->setTickInterval(100);
    //imageZoomSlider->setTickPosition(50);

//    QImage imageObject;
//    imageObject.load("D:\\Photos\\2015-11-22\\009.JPG");
//    updateDisplayArea(imageObject);

}

void ImageDisplayWidget::resizeEvent(QResizeEvent *event)
{
    updateDisplayArea();
}

void ImageDisplayWidget::updateDisplayArea()
{
    if(!displayImage.isNull()){
        QPixmap pixmap = QPixmap::fromImage(displayImage);
        pixmap = pixmap.scaled(scrollArea->width(),scrollArea->height(),Qt::KeepAspectRatio);
        imageDisplayLabel->setFixedWidth(pixmap.width()-5);
        imageDisplayLabel->setFixedHeight(pixmap.height()-5);
        imageDisplayLabel->setPixmap(pixmap);
    }
}

void ImageDisplayWidget::updateDisplayImage(QImage image)
{
    setDisplayImage(image);
}

QImage ImageDisplayWidget::getDisplayImage() const
{
    return displayImage;
}

void ImageDisplayWidget::setDisplayImage(const QImage &value)
{
    displayImage = value;
    emit imageChanged();
}

