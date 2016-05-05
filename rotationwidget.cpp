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
    rotationTypeLabel->setFixedHeight(25);

    rotationTypeComboBox->addItem(QString("Rotate left"), ROTATE_LEFT);
    rotationTypeComboBox->addItem(QString("Rotate right"), ROTATE_RIGHT);
    rotationTypeComboBox->setFixedHeight(25);

    rotationRadiusLabel->setText(QString("Angle : "));
    rotationRadiusLabel->setFixedHeight(25);

    rotationRadiusSpinBox->setRange(1, 359);
    rotationRadiusSpinBox->setSingleStep(1);
    rotationRadiusSpinBox->setFixedHeight(25);
    rotationRadiusSpinBox->setSuffix(QString("°"));

    applyButton->setText(QString("Apply Changes"));
    applyButton->setFixedHeight(25);

    layout->addWidget(rotationTypeLabel, 0, 0);
    layout->addWidget(rotationTypeComboBox, 0, 1);
    layout->addWidget(rotationRadiusLabel, 1, 0);
    layout->addWidget(rotationRadiusSpinBox, 1, 1);
    layout->addWidget(applyButton, 2, 0, 2, 2);

    layout->setRowMinimumHeight(0, 30);
    layout->setRowMinimumHeight(1, 30);

    setLayout(layout);
  }

  void RotationWidget::applyButtonClicked()
  {
      try{
    if(rotationTypeComboBox->currentData() == ROTATE_LEFT){
        setOutputImage(rotationImage.applyRotateLeft(getInputImage(), rotationRadiusSpinBox->value()));
    }
    else if(rotationTypeComboBox->currentData() == ROTATE_RIGHT){
        setOutputImage(rotationImage.applyRotateRight(getInputImage(), rotationRadiusSpinBox->value()));
    }
      }
      catch(std::exception exp){
          std::cout<< exp.what();
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

  void RotationWidget::updateInputImage(QImage &image)
  {
    setInputImage(image);
  }

