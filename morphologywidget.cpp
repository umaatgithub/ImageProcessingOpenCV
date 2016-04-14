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
  morphologyTypeLabel->setFixedHeight(15);

  morphologyTypeComboBox->addItem(QString("Closing"), CLOSING);
  morphologyTypeComboBox->addItem(QString("Dilate"), DILATE);
  morphologyTypeComboBox->addItem(QString("Erode"), ERODE);
  morphologyTypeComboBox->addItem(QString("Opening"), OPENING);
  morphologyTypeComboBox->setFixedHeight(20);

  morphologyRadiusLabel->setText(QString("Structuring Element Radius : "));
  morphologyRadiusLabel->setFixedHeight(15);

  morphologyRadiusSpinBox->setRange(2, 40);
  morphologyRadiusSpinBox->setSingleStep(1);
  morphologyRadiusSpinBox->setFixedHeight(20);

  applyButton->setText(QString("Apply Changes"));

  layout->addWidget(morphologyTypeLabel, 0, 0);
  layout->addWidget(morphologyTypeComboBox, 1, 0);
  layout->addWidget(morphologyRadiusLabel, 2, 0);
  layout->addWidget(morphologyRadiusSpinBox, 3, 0);
  layout->addWidget(applyButton, 4, 0);

  layout->setRowMinimumHeight(0, 15);
  layout->setRowMinimumHeight(1, 20);
  layout->setRowMinimumHeight(2, 15);
  layout->setRowMinimumHeight(3, 20);
  layout->setRowStretch(4, 5);


  setLayout(layout);
}

void MorphologyWidget::applyButtonClicked()
{
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

void MorphologyWidget::updateInputImage(QImage image)
{
  setInputImage(image);
}

