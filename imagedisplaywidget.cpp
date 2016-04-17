#include "imagedisplaywidget.h"
#include <QGridLayout>

ImageDisplayWidget::ImageDisplayWidget(QWidget *parent) : QWidget(parent),
    layout(new QGridLayout),scrollArea(new QScrollArea),
    imageDisplayLabel(new QLabel),  percentageZoom(0.0)
{
    connect(this, SIGNAL(imageChanged()),this, SLOT(updateDisplayArea()));
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

}

float ImageDisplayWidget::zoomInDisplayImage()
{
    float currentZoom = getPercentageZoom();
    if(currentZoom >= 12.5 && currentZoom < 200){
        setPercentageZoom(currentZoom*2);
        updateDisplayArea();
    }
    else if(currentZoom >= 200){
        setPercentageZoom(currentZoom+100);
        updateDisplayArea();
    }
    return getPercentageZoom();


}

float ImageDisplayWidget::zoomOutDisplayImage()
{
    float currentZoom = getPercentageZoom();
    if(currentZoom > 12.5 && currentZoom <= 200){
        setPercentageZoom(currentZoom/2);
        updateDisplayArea();
    }
    else if(currentZoom > 200){
        setPercentageZoom(currentZoom-100);
        updateDisplayArea();
    }
    return getPercentageZoom();
}

//void ImageDisplayWidget::resizeEvent(QResizeEvent *event)
//{
    //updateDisplayArea();
//}

void ImageDisplayWidget::updateDisplayArea()
{
    if(!displayImage.isNull()){
        QPixmap pixmap = QPixmap::fromImage(displayImage);
        pixmap = pixmap.scaled(pixmap.width()*getPercentageZoom()/100,pixmap.height()*getPercentageZoom()/100,Qt::KeepAspectRatio);
        imageDisplayLabel->setFixedWidth(pixmap.width()+ 10);
        imageDisplayLabel->setFixedHeight(pixmap.height()+ 10);
        imageDisplayLabel->setPixmap(pixmap);
        imageDisplayLabel->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
    }
}

void ImageDisplayWidget::updateDisplayImage(QImage image, bool newImage)
{
    if(newImage==true){
        setPercentageZoom(100.0);
    }
    setDisplayImage(image);
}

float ImageDisplayWidget::getPercentageZoom() const
{
    return percentageZoom;
}

void ImageDisplayWidget::setPercentageZoom(float value)
{
    percentageZoom = value;
    emit percentageZoomChanged(value);
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

