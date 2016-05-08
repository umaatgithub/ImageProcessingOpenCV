#include "imagedisplaywidget.h"
#include <QGridLayout>

ImageDisplayWidget::ImageDisplayWidget(QWidget *parent) : QWidget(parent),
    layout(new QGridLayout), scrollArea(new QScrollArea),
    imageDisplayLabel(new DisplayLabel), percentageZoom(0.0)
{
    //connect(this, SIGNAL(imageChanged()),this, SLOT(updateDisplayArea()));
    connect(getImageDisplayLabel(), SIGNAL(selectionUpdated(QRect&)),
            this, SLOT(updateSelectionRect(QRect&)));
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

void ImageDisplayWidget::zoomInDisplayImage()
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
}

void ImageDisplayWidget::zoomOutDisplayImage()
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
}

void ImageDisplayWidget::cropDisplayImage()
{
    if(!displayImage.isNull()){
        QtOpenCVBridge *qtOpenCVBridge = new QtOpenCVBridge;

        cv::Mat imageMat =  qtOpenCVBridge->QImage2Mat(displayImage);
        cv::Rect regionOfInterest(selectionRect.x(), selectionRect.y(), selectionRect.width(), selectionRect.height());

        cv::Mat croppedMat(imageMat, regionOfInterest);
        cv::Mat croppedOutputMat;
        croppedMat.copyTo(croppedOutputMat);
        setDisplayImage(qtOpenCVBridge->Mat2QImage(croppedOutputMat));
        getImageDisplayLabel()->disableSelection();
        emit imageChanged(getDisplayImage());
    }
}

void ImageDisplayWidget::autoContrastDisplayImage()
{
    if(!displayImage.isNull()){
        QtOpenCVBridge *qtOpenCVBridge = new QtOpenCVBridge;
        cv::Mat inputMat =  qtOpenCVBridge->QImage2Mat(displayImage);
        cv::Mat outputMat = inputMat.clone();
        if(inputMat.type() == CV_8UC4 || inputMat.type() == CV_8UC3){
            cv::Mat ycrcb;
            cvtColor(inputMat, ycrcb, CV_BGR2YCrCb);
            cv::vector<cv::Mat> channels;
            split(ycrcb, channels);
            equalizeHist(channels[0], channels[0]);
            merge(channels, ycrcb);
            cvtColor(ycrcb, outputMat, CV_YCrCb2BGR);
            setDisplayImage(qtOpenCVBridge->Mat2QImage(outputMat));
            emit imageChanged(getDisplayImage());
        }
        else if(inputMat.type() == CV_8UC1){
            equalizeHist(inputMat, outputMat);
            setDisplayImage(qtOpenCVBridge->Mat2QImage(outputMat));
            emit imageChanged(getDisplayImage());
        }
    }
}

void ImageDisplayWidget::updateDisplayArea()
{
    if(!displayImage.isNull()){
        QPixmap pixmap = QPixmap::fromImage(getDisplayImage());
        pixmap = pixmap.scaled(pixmap.width()*getPercentageZoom()/100,pixmap.height()*getPercentageZoom()/100,Qt::KeepAspectRatio);
        imageDisplayLabel->setFixedWidth(pixmap.width()+ 10);
        imageDisplayLabel->setFixedHeight(pixmap.height()+ 10);
        imageDisplayLabel->setPixmap(pixmap);
        imageDisplayLabel->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
        imageDisplayLabel->updatePercentageZoom(getPercentageZoom());
    }
}

void ImageDisplayWidget::updateDisplayImage(QImage &image, bool newImage)
{
    if(newImage==true){
        setPercentageZoom(100.0);
    }
    setDisplayImage(image);
    updateDisplayArea();
}

void ImageDisplayWidget::updateSelectionRect(QRect &rect)
{
    setSelectionRect(rect);
}

QRect ImageDisplayWidget::getSelectionRect() const
{
    return selectionRect;
}

void ImageDisplayWidget::setSelectionRect(const QRect &value)
{
    if(value.width()!=0 && value.height()!=0){
        selectionRect = value;
    }
}

DisplayLabel *ImageDisplayWidget::getImageDisplayLabel() const
{
    return imageDisplayLabel;
}

void ImageDisplayWidget::setImageDisplayLabel(DisplayLabel *value)
{
    imageDisplayLabel = value;
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
}

