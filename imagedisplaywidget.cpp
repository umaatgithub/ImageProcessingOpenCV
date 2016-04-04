#include "imagedisplaywidget.h"
#include <QGridLayout>

ImageDisplayWidget::ImageDisplayWidget(QWidget *parent) : QWidget(parent),
    layout(new QGridLayout),scrollArea(new QScrollArea),
    imageDisplayLabel(new QLabel)
{
    connect(this, SIGNAL(pathChanged(QString)),this, SLOT(updateDisplayImage(QString)));
    connect(this, SIGNAL(imageChanged(QImage)),this, SLOT(updateDisplayArea(QImage)));
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

//    QImage imageObject;
//    imageObject.load("D:\\Photos\\2015-11-22\\009.JPG");
//    updateDisplayArea(imageObject);

}

void ImageDisplayWidget::resizeEvent(QResizeEvent *event)
{
    updateDisplayArea(displayImage);
    //update();
}

void ImageDisplayWidget::updateDisplayArea(QImage image)
{
    if(!image.isNull()){
        displayImage = image;
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(scrollArea->width(),scrollArea->height(),Qt::KeepAspectRatio);
        imageDisplayLabel->setFixedWidth(pixmap.width()-5);
        imageDisplayLabel->setFixedHeight(pixmap.height()-5);
        imageDisplayLabel->setPixmap(pixmap);
    }
}

void ImageDisplayWidget::updateDisplayImage(QString path)
{
    QImage image;
    image.load(path);
    setDisplayImage(image);
}

QImage ImageDisplayWidget::getDisplayImage() const
{
    return displayImage;
}

void ImageDisplayWidget::setDisplayImage(const QImage &value)
{
    displayImage = value;
    emit imageChanged(value);
}

QString ImageDisplayWidget::getImageFullPath() const
{
    return imageFullPath;
}

void ImageDisplayWidget::setImageFullPath(const QString &value)
{
    imageFullPath = value;
    emit pathChanged(value);
}

