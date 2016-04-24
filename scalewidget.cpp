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
    scaleTypeLabel->setFixedHeight(15);

    scaleTypeComboBox->addItem(QString("Scale down"), SCALE_DOWN);
    scaleTypeComboBox->addItem(QString("Scale up"), SCALE_UP);
    scaleTypeComboBox->setFixedHeight(20);

    scaleRadiusLabel->setText(QString("Scale : "));
    scaleRadiusLabel->setFixedHeight(15);

    scaleRadiusSpinBox->setRange(1, 100);
    scaleRadiusSpinBox->setSingleStep(1);
    scaleRadiusSpinBox->setFixedHeight(20);

    applyButton->setText(QString("Apply Changes"));

    layout->addWidget(scaleTypeLabel, 0, 0);
    layout->addWidget(scaleTypeComboBox, 1, 0);
    layout->addWidget(scaleRadiusLabel, 2, 0);
    layout->addWidget(scaleRadiusSpinBox, 3, 0);
    layout->addWidget(applyButton, 4, 0);

    layout->setRowMinimumHeight(0, 15);
    layout->setRowMinimumHeight(1, 20);
    layout->setRowMinimumHeight(2, 15);
    layout->setRowMinimumHeight(3, 20);
    layout->setRowStretch(4, 5);

    setLayout(layout);
  }

  void ScaleWidget::applyButtonClicked()
  {
    if(scaleTypeComboBox->currentData() == SCALE_DOWN){
        setOutputImage(scaleImage.applyScaleDown(getInputImage(), scaleRadiusSpinBox->value()));
    }
    else if(scaleTypeComboBox->currentData() == SCALE_UP){
        setOutputImage(scaleImage.applyScaleUp(getInputImage(), scaleRadiusSpinBox->value()));
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

  void ScaleWidget::updateInputImage(QImage image)
  {
    setInputImage(image);
  }

