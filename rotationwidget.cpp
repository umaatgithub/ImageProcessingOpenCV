#include "rotationwidget.h"

RotationWidget::RotationWidget(QWidget *parent) : QWidget(parent), layout(new QGridLayout),
    rotationTypeLabel(new QLabel), rotationTypeComboBox(new QComboBox),
    rotationRadiusLabel(new QLabel), rotationRadiusSpinBox(new QSpinBox),
    applyButton(new QPushButton)
  {
    setupWidget();
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonClicked()));
  }

  void RotationWidget::setupWidget()
  {
    rotationTypeLabel->setText(QString("Rotation Type : "));
    rotationTypeLabel->setFixedHeight(15);

    rotationTypeComboBox->addItem(QString("Rotate left"), ROTATE_LEFT);
    rotationTypeComboBox->addItem(QString("Rotate right"), ROTATE_RIGHT);
    rotationTypeComboBox->setFixedHeight(20);

    rotationRadiusLabel->setText(QString("Angle : "));
    rotationRadiusLabel->setFixedHeight(15);

    rotationRadiusSpinBox->setRange(1, 255);
    rotationRadiusSpinBox->setSingleStep(1);
    rotationRadiusSpinBox->setFixedHeight(20);

    applyButton->setText(QString("Apply Changes"));

    layout->addWidget(rotationTypeLabel, 0, 0);
    layout->addWidget(rotationTypeComboBox, 1, 0);
    layout->addWidget(rotationRadiusLabel, 2, 0);
    layout->addWidget(rotationRadiusSpinBox, 3, 0);
    layout->addWidget(applyButton, 4, 0);

    layout->setRowMinimumHeight(0, 15);
    layout->setRowMinimumHeight(1, 20);
    layout->setRowMinimumHeight(2, 15);
    layout->setRowMinimumHeight(3, 20);
    layout->setRowStretch(4, 5);

    setLayout(layout);
  }

  void RotationWidget::applyButtonClicked()
  {
    if(rotationTypeComboBox->currentData() == ROTATE_LEFT){
        setOutputImage(rotationImage.applyRotateLeft(getInputImage(), rotationRadiusSpinBox->value()));
    }
    else if(rotationTypeComboBox->currentData() == ROTATE_RIGHT){
        setOutputImage(rotationImage.applyRotateRight(getInputImage(), rotationRadiusSpinBox->value()));
    }
  }

  QImage RotationWidget::getInputImage() const
  {
    return inputImage;
  }

  void RotationWidget::setInputImage(const QImage &image)
  {
    inputImage = image;
  }

  QImage RotationWidget::getOutputImage() const
  {
    return outputImage;
  }

  void RotationWidget::setOutputImage(const QImage &image)
  {
    outputImage = image;
    emit outputImageChanged(image);
  }

  void RotationWidget::updateInputImage(QImage image)
  {
    setInputImage(image);
  }

