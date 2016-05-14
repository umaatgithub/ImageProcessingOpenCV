#include "imagescalingtool.h"

ImageScalingTool::ImageScalingTool(QString name): ImageProcessingToolWidget(name), layout(new QGridLayout),
    scaleTypeLabel(new QLabel), scaleTypeComboBox(new QComboBox),
    scalePercentageLabel(new QLabel), scalePercentageSpinBox(new QSpinBox),
    applyButton(new QPushButton)
  {
    setupWidget();
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonClicked()));
  }

void ImageScalingTool::setupWidget()
{
    scaleTypeLabel->setText(QString("Scale Type : "));
    scaleTypeLabel->setFixedHeight(25);

    scaleTypeComboBox->addItem(QString("Scale down"), SCALE_DOWN);
    scaleTypeComboBox->addItem(QString("Scale up"), SCALE_UP);
    scaleTypeComboBox->setFixedHeight(25);

    scalePercentageLabel->setText(QString("Scale Percentage: "));
    scalePercentageLabel->setFixedHeight(25);

    scalePercentageSpinBox->setRange(1, 100);
    scalePercentageSpinBox->setSingleStep(1);
    scalePercentageSpinBox->setFixedHeight(25);
    scalePercentageSpinBox->setSuffix(QString("%"));

    applyButton->setText(QString("Apply Changes"));
    applyButton->setFixedHeight(25);

    layout->addWidget(scaleTypeLabel, 0, 0);
    layout->addWidget(scaleTypeComboBox, 0, 1);
    layout->addWidget(scalePercentageLabel, 1, 0);
    layout->addWidget(scalePercentageSpinBox, 1, 1);
    layout->addWidget(applyButton, 2, 0, 2, 2);

    layout->setRowMinimumHeight(0, 30);
    layout->setRowMinimumHeight(1, 30);

    setLayout(layout);
}

void ImageScalingTool::applyButtonClicked()
{
    try{
        emit statusChanged(QString(" Processing image..."), Qt::blue);
        if(!getInputImage()->isNull()){
            if(scaleTypeComboBox->currentData() == SCALE_DOWN){
                setOutputImage(scaleImage.applyScaleDown(getInputImage(), scalePercentageSpinBox->value()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(scaleTypeComboBox->currentData() == SCALE_UP){
                setOutputImage(scaleImage.applyScaleUp(getInputImage(), scalePercentageSpinBox->value()));
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
