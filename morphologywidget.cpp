#include "morphologywidget.h"

MorphologyWidget::MorphologyWidget(QWidget *parent) : QWidget(parent), layout(new QGridLayout),
  morphologyTypeLabel(new QLabel), morphologyTypeComboBox(new QComboBox),
  morphologyRadiusLabel(new QLabel), morphologyRadiusSpinBox(new QSpinBox),
  applyButton(new QPushButton)
{
  setupWidget();
  connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonClicked()));
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

  applyButton->setText(QString("Apply Changes"));
  applyButton->setFixedHeight(25);

  layout->addWidget(morphologyTypeLabel, 0, 0);
  layout->addWidget(morphologyTypeComboBox, 0, 1);
  layout->addWidget(morphologyRadiusLabel, 1, 0);
  layout->addWidget(morphologyRadiusSpinBox, 1, 1);
  layout->addWidget(applyButton, 2, 0, 2, 2);

  layout->setRowMinimumHeight(0, 30);
  layout->setRowMinimumHeight(1, 30);

  setLayout(layout);
}

void MorphologyWidget::applyButtonClicked()
{
    try{
  if(morphologyTypeComboBox->currentData() == CLOSING){
      setOutputImage(morphologyImage.applyClosing(getInputImage(), morphologyRadiusSpinBox->value()));
  }
  else if(morphologyTypeComboBox->currentData() == DILATE){
      setOutputImage(morphologyImage.applyDilate(getInputImage(), morphologyRadiusSpinBox->value()));
  }
  else if(morphologyTypeComboBox->currentData() == ERODE){
      setOutputImage(morphologyImage.applyErode(getInputImage(), morphologyRadiusSpinBox->value()));
  }
  else if(morphologyTypeComboBox->currentData() == OPENING){
      setOutputImage(morphologyImage.applyOpening(getInputImage(), morphologyRadiusSpinBox->value()));
  }
    }
    catch(std::exception exp){
        std::cout<< exp.what();
    }
}

QImage MorphologyWidget::getInputImage() const
{
  return inputImage;
}

void MorphologyWidget::setInputImage(const QImage &image)
{
  inputImage = image;
}

QImage MorphologyWidget::getOutputImage() const
{
  return outputImage;
}

void MorphologyWidget::setOutputImage(const QImage &image)
{
  outputImage = image;
  emit outputImageChanged(image);
}

void MorphologyWidget::updateInputImage(QImage &image)
{
  setInputImage(image);
}

