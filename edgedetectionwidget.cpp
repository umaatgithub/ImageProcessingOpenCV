#include "edgedetectionwidget.h"

EdgeDetectionWidget::EdgeDetectionWidget(QWidget *parent) : QWidget(parent), layout(new QGridLayout),
    edgeDetectorLabel(new QLabel), edgeDetectorComboBox(new QComboBox),
    filterRadiusLabel(new QLabel), filterRadiusSpinBox(new QSpinBox),
    applyButton(new QPushButton)
{
    setupWidget();
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonClicked()));
}

void EdgeDetectionWidget::setupWidget()
{
    edgeDetectorLabel->setText(QString("Edge Detector : "));
    edgeDetectorLabel->setFixedHeight(25);

    edgeDetectorComboBox->addItem(QString("Canny"), CANNY);
    edgeDetectorComboBox->addItem(QString("Scharr"), SCHARR);
    edgeDetectorComboBox->addItem(QString("Sobel"), SOBEL);
    edgeDetectorComboBox->setFixedHeight(25);

    filterRadiusLabel->setText(QString("Filter Radius : "));
    filterRadiusLabel->setFixedHeight(25);

    filterRadiusSpinBox->setRange(1, 31);
    filterRadiusSpinBox->setSingleStep(2);
    filterRadiusSpinBox->setFixedHeight(25);

    applyButton->setText(QString("Apply Changes"));
    applyButton->setFixedHeight(25);

    layout->addWidget(edgeDetectorLabel, 0, 0);
    layout->addWidget(edgeDetectorComboBox, 0, 1);
    layout->addWidget(filterRadiusLabel, 1, 0);
    layout->addWidget(filterRadiusSpinBox, 1, 1);
    layout->addWidget(applyButton, 2, 0, 2, 2);

    layout->setRowMinimumHeight(0, 30);
    layout->setRowMinimumHeight(1, 30);

    setLayout(layout);
}

void EdgeDetectionWidget::applyButtonClicked()
{
    try{
        emit statusChanged(QString(" Processing image..."), Qt::blue);
        if(!getInputImage().isNull()){
            if(edgeDetectorComboBox->currentData() == CANNY){
                setOutputImage(edgeDetectionImage.applyCannysEdgeDetector(getInputImage(), filterRadiusSpinBox->value()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(edgeDetectorComboBox->currentData() == SCHARR){
                setOutputImage(edgeDetectionImage.applyScharrEdgeDetector(getInputImage(), filterRadiusSpinBox->value()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(edgeDetectorComboBox->currentData() == SOBEL){
                setOutputImage(edgeDetectionImage.applySobelEdgeDetector(getInputImage(), filterRadiusSpinBox->value()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
        }
        else{
            emit statusChanged(QString(" Image not set."), Qt::black);
        }
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
        emit statusChanged(QString(msg), Qt::red);
    }
    catch(std::exception exp){
        std::cerr << exp.what();
        emit statusChanged(QString(" Error."), Qt::red);
    }
}

QImage EdgeDetectionWidget::getInputImage() const
{
    return inputImage;
}

void EdgeDetectionWidget::setInputImage(const QImage &image)
{
    inputImage = image;
}

QImage EdgeDetectionWidget::getOutputImage() const
{
    return outputImage;
}

void EdgeDetectionWidget::setOutputImage(const QImage &image)
{
    outputImage = image;
    emit outputImageChanged(image);
}

void EdgeDetectionWidget::updateInputImage(QImage &image)
{
    setInputImage(image);
}

