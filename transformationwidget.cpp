#include "transformationwidget.h"

TransformationWidget::TransformationWidget(QWidget *parent) : QWidget(parent), layout(new QGridLayout),
    transformationTypeLabel(new QLabel), transformationTypeComboBox(new QComboBox),
    transformationRadiusLabel(new QLabel), transformationRadiusSpinBox(new QSpinBox),
    applyButton(new QPushButton)
  {
    setupWidget();
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonClicked()));
  }

  void TransformationWidget::setupWidget()
  {
    transformationTypeLabel->setText(QString("Transformation Type : "));
    transformationTypeLabel->setFixedHeight(15);

    transformationTypeComboBox->addItem(QString("Binary"), BINARY);
    transformationTypeComboBox->addItem(QString("Grayscale"), GRAYSCALE);
    transformationTypeComboBox->setFixedHeight(20);

    transformationRadiusLabel->setText(QString("Scale : "));
    transformationRadiusLabel->setFixedHeight(15);

    transformationRadiusSpinBox->setRange(1, 255);
    transformationRadiusSpinBox->setSingleStep(1);
    transformationRadiusSpinBox->setFixedHeight(20);

    applyButton->setText(QString("Apply Changes"));

    layout->addWidget(transformationTypeLabel, 0, 0);
    layout->addWidget(transformationTypeComboBox, 1, 0);
    layout->addWidget(transformationRadiusLabel, 2, 0);
    layout->addWidget(transformationRadiusSpinBox, 3, 0);
    layout->addWidget(applyButton, 4, 0);

    layout->setRowMinimumHeight(0, 15);
    layout->setRowMinimumHeight(1, 20);
    layout->setRowMinimumHeight(2, 15);
    layout->setRowMinimumHeight(3, 20);
    layout->setRowStretch(4, 5);

    setLayout(layout);
  }

  void TransformationWidget::applyButtonClicked()
  {
    if(transformationTypeComboBox->currentData() == BINARY){
        setOutputImage(transformationImage.applyBinaryTransformation(getInputImage(), transformationRadiusSpinBox->value()));
    }
    else if(transformationTypeComboBox->currentData() == GRAYSCALE){
        setOutputImage(transformationImage.applyGrayscaleTransformation(getInputImage()));
    }
  }

  QImage TransformationWidget::getInputImage() const
  {
    return inputImage;
  }

  void TransformationWidget::setInputImage(const QImage &image)
  {
    inputImage = image;
  }

  QImage TransformationWidget::getOutputImage() const
  {
    return outputImage;
  }

  void TransformationWidget::setOutputImage(const QImage &image)
  {
    outputImage = image;
    emit outputImageChanged(image);
  }

  void TransformationWidget::updateInputImage(QImage image)
  {
    setInputImage(image);
  }
