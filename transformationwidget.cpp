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
    transformationTypeLabel->setFixedHeight(25);

    transformationTypeComboBox->addItem(QString("Binary"), BINARY);
    transformationTypeComboBox->addItem(QString("Grayscale"), GRAYSCALE);
    transformationTypeComboBox->setFixedHeight(25);

    transformationRadiusLabel->setText(QString("Scale : "));
    transformationRadiusLabel->setFixedHeight(25);

    transformationRadiusSpinBox->setRange(1, 255);
    transformationRadiusSpinBox->setSingleStep(1);
    transformationRadiusSpinBox->setFixedHeight(25);

    applyButton->setText(QString("Apply Changes"));
    applyButton->setFixedHeight(25);

    layout->addWidget(transformationTypeLabel, 0, 0);
    layout->addWidget(transformationTypeComboBox, 0, 1);
    layout->addWidget(transformationRadiusLabel, 1, 0);
    layout->addWidget(transformationRadiusSpinBox, 1, 1);
    layout->addWidget(applyButton, 2, 0, 2, 2);

    layout->setRowMinimumHeight(0, 30);
    layout->setRowMinimumHeight(1, 30);

    setLayout(layout);
  }

  void TransformationWidget::applyButtonClicked()
  {
      try{
    if(transformationTypeComboBox->currentData() == BINARY){
        setOutputImage(transformationImage.applyBinaryTransformation(getInputImage(), transformationRadiusSpinBox->value()));
    }
    else if(transformationTypeComboBox->currentData() == GRAYSCALE){
        setOutputImage(transformationImage.applyGrayscaleTransformation(getInputImage()));
    }
      }
      catch(std::exception exp){
          std::cout<< exp.what();
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

  void TransformationWidget::updateInputImage(QImage &image)
  {
    setInputImage(image);
  }

