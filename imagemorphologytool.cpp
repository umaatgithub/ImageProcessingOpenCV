#include "imagemorphologytool.h"

MorphologyWidget::MorphologyWidget(QString name):ImageProcessingToolWidget(name), layout(new QGridLayout),
    morphologyTypeLabel(new QLabel), morphologyTypeComboBox(new QComboBox),
    morphologyRadiusLabel(new QLabel), morphologyRadiusSpinBox(new QSpinBox), roiLabel(new QLabel), roiCheckBox(new QCheckBox),
    applyButton(new QPushButton)
{
    setupWidget();
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonClicked()));
    connect(this, SIGNAL(roiRectUpdated()), this, SLOT(updateCheckBox()));
    connect(this, SIGNAL(inputImageChanged(QImage*)), this, SLOT(updateCheckBox()));
}

void MorphologyWidget::setupWidget()
{
    morphologyTypeLabel->setText(QString("Morphology Type : "));
    morphologyTypeLabel->setFixedHeight(25);

    morphologyTypeComboBox->addItem(QString("Closing"), CLOSING);
    morphologyTypeComboBox->addItem(QString("Dilate"), DILATE);
    morphologyTypeComboBox->addItem(QString("Erode"), ERODE);
    morphologyTypeComboBox->addItem(QString("Opening"), OPENING);
    morphologyTypeComboBox->setFixedHeight(25);

    morphologyRadiusLabel->setText(QString("Structuring Element Radius : "));
    morphologyRadiusLabel->setFixedHeight(25);

    morphologyRadiusSpinBox->setRange(2, 40);
    morphologyRadiusSpinBox->setSingleStep(1);
    morphologyRadiusSpinBox->setFixedHeight(25);

    roiLabel->setText(QString("Region Of Interest : "));
    roiLabel->setFixedHeight(25);

    roiCheckBox->setChecked(false);
    roiCheckBox->setEnabled(false);
    roiCheckBox->setFixedHeight(25);

    applyButton->setText(QString("Apply Changes"));
    applyButton->setFixedHeight(25);

    layout->addWidget(morphologyTypeLabel, 0, 0);
    layout->addWidget(morphologyTypeComboBox, 0, 1);
    layout->addWidget(morphologyRadiusLabel, 1, 0);
    layout->addWidget(morphologyRadiusSpinBox, 1, 1);
    layout->addWidget(roiLabel, 2, 0);
    layout->addWidget(roiCheckBox, 2, 1);
    layout->addWidget(applyButton, 3, 0, 2, 2);

    layout->setRowMinimumHeight(0, 30);
    layout->setRowMinimumHeight(1, 30);

    setLayout(layout);
}

void MorphologyWidget::applyButtonClicked()
{
    try{
        emit statusChanged(QString(" Processing image..."), Qt::blue);
        if(!getInputImage()->isNull()){
            if(morphologyTypeComboBox->currentData() == CLOSING){
                setOutputImage(morphologyImage.applyClosing(getInputImage(),
                                                            morphologyRadiusSpinBox->value(),
                                                            roiCheckBox->isChecked(),
                                                            getRoiRect()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(morphologyTypeComboBox->currentData() == DILATE){
                setOutputImage(morphologyImage.applyDilate(getInputImage(),
                                                           morphologyRadiusSpinBox->value(),
                                                           roiCheckBox->isChecked(),
                                                           getRoiRect()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(morphologyTypeComboBox->currentData() == ERODE){
                setOutputImage(morphologyImage.applyErode(getInputImage(),
                                                          morphologyRadiusSpinBox->value(),
                                                          roiCheckBox->isChecked(),
                                                          getRoiRect()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(morphologyTypeComboBox->currentData() == OPENING){
                setOutputImage(morphologyImage.applyOpening(getInputImage(),
                                                            morphologyRadiusSpinBox->value(),
                                                            roiCheckBox->isChecked(),
                                                            getRoiRect()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
        }
        else{
            emit statusChanged(QString(" Image not set."), Qt::black);
        }
    }
    catch (const char* msg) {
        //std::cerr << msg << std::endl;
        emit statusChanged(QString(msg), Qt::red);
    }
    catch(std::exception exp){
        //std::cerr << exp.what();
        emit statusChanged(QString(" Error."), Qt::red);
    }
}

void MorphologyWidget::updateCheckBox()
{
    if(!getRoiRect()->isNull() && isRoiRectValid()){
        roiCheckBox->setEnabled(true);
    }
    else{
        roiCheckBox->setEnabled(false);
        roiCheckBox->setChecked(false);
    }
}
