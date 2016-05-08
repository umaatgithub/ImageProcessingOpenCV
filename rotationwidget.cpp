#include "rotationwidget.h"

RotationWidget::RotationWidget(QWidget *parent) : QWidget(parent), layout(new QGridLayout),
    directionLabel(new QLabel), directionComboBox(new QComboBox),
    angleLabel(new QLabel), angleSpinBox(new QSpinBox),
    applyButton(new QPushButton)
  {
    setupWidget();
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonClicked()));
  }

void RotationWidget::setupWidget()
{
    directionLabel->setText(QString("Direction : "));
    directionLabel->setFixedHeight(25);

    directionComboBox->addItem(QString("Anti-clockwise"), ANTI_CLOCKWISE);
    directionComboBox->addItem(QString("Clockwise"), CLOCKWISE);
    directionComboBox->setFixedHeight(25);

    angleLabel->setText(QString("Angle : "));
    angleLabel->setFixedHeight(25);

    angleSpinBox->setRange(1, 359);
    angleSpinBox->setSingleStep(1);
    angleSpinBox->setFixedHeight(25);
    angleSpinBox->setSuffix(QString("°"));

    applyButton->setText(QString("Apply Changes"));
    applyButton->setFixedHeight(25);

    layout->addWidget(directionLabel, 0, 0);
    layout->addWidget(directionComboBox, 0, 1);
    layout->addWidget(angleLabel, 1, 0);
    layout->addWidget(angleSpinBox, 1, 1);
    layout->addWidget(applyButton, 2, 0, 2, 2);

    layout->setRowMinimumHeight(0, 30);
    layout->setRowMinimumHeight(1, 30);

    setLayout(layout);
}

void RotationWidget::applyButtonClicked()
{
    try{
        emit statusChanged(QString(" Processing image..."), Qt::blue);
        if(!getInputImage().isNull()){
            if(directionComboBox->currentData() == ANTI_CLOCKWISE){
                setOutputImage(rotationImage.applyAntiClockwiseRotation(getInputImage(), angleSpinBox->value()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(directionComboBox->currentData() == CLOCKWISE){
                setOutputImage(rotationImage.applyClockwiseRotation(getInputImage(), angleSpinBox->value()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
        }
        else{
            emit statusChanged(QString(" Image not set."), Qt::black);
        }
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
        emit statusChanged(QString(msg), Qt::red);
    }
    catch(std::exception exp){
        std::cerr << exp.what();
        emit statusChanged(QString(" Error."), Qt::red);
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

