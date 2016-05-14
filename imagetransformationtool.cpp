#include "imagetransformationtool.h"

ImageTransformationTool::ImageTransformationTool(QString name): ImageProcessingToolWidget(name), layout(new QGridLayout),
    transformationTypeLabel(new QLabel), transformationTypeComboBox(new QComboBox),
    thresholdPercentageLabel(new QLabel), thresholdPercentageSpinBox(new QSpinBox),
    applyButton(new QPushButton)
  {
    setupWidget();
    connect(transformationTypeComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(modifyWidgetOptions(int)));
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonClicked()));
  }

void ImageTransformationTool::setupWidget()
{
    transformationTypeLabel->setText(QString("Transformation Type : "));
    transformationTypeLabel->setFixedHeight(25);

    transformationTypeComboBox->addItem(QString("Binary"), BINARY);
    transformationTypeComboBox->addItem(QString("Grayscale"), GRAYSCALE);
    transformationTypeComboBox->addItem(QString("Negative"), NEGATIVE);
    transformationTypeComboBox->setFixedHeight(25);

    thresholdPercentageLabel->setText(QString("Threshold Percentage : "));
    thresholdPercentageLabel->setFixedHeight(25);

    thresholdPercentageSpinBox->setRange(1, 255);
    thresholdPercentageSpinBox->setSingleStep(1);
    thresholdPercentageSpinBox->setFixedHeight(25);
    thresholdPercentageSpinBox->setSuffix(QString("%"));

    applyButton->setText(QString("Apply Changes"));
    applyButton->setFixedHeight(25);

    layout->addWidget(transformationTypeLabel, 0, 0);
    layout->addWidget(transformationTypeComboBox, 0, 1);
    layout->addWidget(thresholdPercentageLabel, 1, 0);
    layout->addWidget(thresholdPercentageSpinBox, 1, 1);
    layout->addWidget(applyButton, 2, 0, 2, 2);

    layout->setRowMinimumHeight(0, 30);
    layout->setRowMinimumHeight(1, 30);

    setLayout(layout);
}

void ImageTransformationTool::applyButtonClicked()
{
    try{
        emit statusChanged(QString(" Processing image..."), Qt::blue);
        if(!getInputImage()->isNull()){
            if(transformationTypeComboBox->currentData() == BINARY){
                setOutputImage(transformationImage.applyBinaryTransformation(getInputImage(), thresholdPercentageSpinBox->value()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(transformationTypeComboBox->currentData() == GRAYSCALE){
                setOutputImage(transformationImage.applyGrayscaleTransformation(getInputImage()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(transformationTypeComboBox->currentData() == NEGATIVE){
                setOutputImage(transformationImage.applyNegativeTransformation(getInputImage(), thresholdPercentageSpinBox->value()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
        }
        else{
            emit statusChanged(QString(" Image not set."), Qt::black);
        }
    }
    catch (const char* msg) {
        emit statusChanged(QString(msg), Qt::red);
    }
    catch(std::exception exp){
        emit statusChanged(QString(" Error."), Qt::red);
    }
}

void ImageTransformationTool::modifyWidgetOptions(int currentIndex)
{
    if(currentIndex == BINARY || currentIndex == NEGATIVE){
        thresholdPercentageSpinBox->setEnabled(true);
    }
    else if(currentIndex == GRAYSCALE){
        thresholdPercentageSpinBox->setEnabled(false);
    }
}
