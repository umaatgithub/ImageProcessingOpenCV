#include "scalewidget.h"

ScaleWidget::ScaleWidget(QWidget *parent) : QWidget(parent), layout(new QGridLayout),
    scaleTypeLabel(new QLabel), scaleTypeComboBox(new QComboBox),
    scaleRadiusLabel(new QLabel), scaleRadiusSpinBox(new QSpinBox),
    applyButton(new QPushButton)
  {
    setupWidget();
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonClicked()));
  }

void ScaleWidget::setupWidget()
  {
    scaleTypeLabel->setText(QString("Scale Type : "));
    scaleTypeLabel->setFixedHeight(25);

    scaleTypeComboBox->addItem(QString("Scale down"), SCALE_DOWN);
    scaleTypeComboBox->addItem(QString("Scale up"), SCALE_UP);
    scaleTypeComboBox->setFixedHeight(25);

    scaleRadiusLabel->setText(QString("Scale : "));
    scaleRadiusLabel->setFixedHeight(25);

    scaleRadiusSpinBox->setRange(1, 100);
    scaleRadiusSpinBox->setSingleStep(1);
    scaleRadiusSpinBox->setFixedHeight(25);
    scaleRadiusSpinBox->setSuffix(QString("%"));

    applyButton->setText(QString("Apply Changes"));
    applyButton->setFixedHeight(25);

    layout->addWidget(scaleTypeLabel, 0, 0);
    layout->addWidget(scaleTypeComboBox, 0, 1);
    layout->addWidget(scaleRadiusLabel, 1, 0);
    layout->addWidget(scaleRadiusSpinBox, 1, 1);
    layout->addWidget(applyButton, 2, 0, 2, 2);

    layout->setRowMinimumHeight(0, 30);
    layout->setRowMinimumHeight(1, 30);

    setLayout(layout);
  }

  void ScaleWidget::applyButtonClicked()
  {
      try{
    if(scaleTypeComboBox->currentData() == SCALE_DOWN){
        setOutputImage(scaleImage.applyScaleDown(getInputImage(), scaleRadiusSpinBox->value()));
    }
    else if(scaleTypeComboBox->currentData() == SCALE_UP){
        setOutputImage(scaleImage.applyScaleUp(getInputImage(), scaleRadiusSpinBox->value()));
    }
      }
      catch(std::exception exp){
          std::cout<< exp.what();
      }
  }

  QImage ScaleWidget::getInputImage() const
  {
    return inputImage;
  }

  void ScaleWidget::setInputImage(const QImage &image)
  {
    inputImage = image;
  }

  QImage ScaleWidget::getOutputImage() const
  {
    return outputImage;
  }

  void ScaleWidget::setOutputImage(const QImage &image)
  {
    outputImage = image;
    emit outputImageChanged(image);
  }

  void ScaleWidget::updateInputImage(QImage &image)
  {
    setInputImage(image);
  }

