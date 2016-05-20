#include "imagerotationtool.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize all the member variables
 *                     of the class and to setup the UI
 *
 **************************************************************************/
ImageRotationTool::ImageRotationTool(QString name): ImageProcessingToolWidget(name), layout(new QGridLayout),
    directionLabel(new QLabel), directionComboBox(new QComboBox),
    angleLabel(new QLabel), angleSpinBox(new QSpinBox),
    applyButton(new QPushButton)
  {
    setupWidget();
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonClicked()));
}

/***************************************************************************
 * Input argument(s) : NIL
 * Return type       : NIL
 * Functionality     : Destructor to delete all the pointer variables
 *
 **************************************************************************/
ImageRotationTool::~ImageRotationTool()
{
    delete applyButton;
    delete angleSpinBox;
    delete angleLabel;
    delete directionComboBox;
    delete directionLabel;
    delete layout;
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Function to setup the UI for the rotation tool
 *
 **************************************************************************/
void ImageRotationTool::setupWidget()
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

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to handle apply button click. It calls the
 *                     rotation function corresponding to the user
 *                     selection
 *
 **************************************************************************/
void ImageRotationTool::applyButtonClicked()
{
    try{
        emit statusChanged(QString(" Processing image..."), Qt::blue);
        if(!getInputImage()->isNull()){
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
        emit statusChanged(QString(msg), Qt::red);
    }
    catch(std::exception exp){
        emit statusChanged(QString(" Error."), Qt::red);
    }
}

//QImage *RotationWidget::getOutputImage() const
//{
//    return outputImage;
//}

//void RotationWidget::setOutputImage(QImage *value)
//{
//    outputImage = value;
//    emit outputImageChanged(value);
//}

//QImage *RotationWidget::getInputImage() const
//{
//    return inputImage;
//}

//void RotationWidget::setInputImage(QImage *value)
//{
//    inputImage = value;
//}

//QImage RotationWidget::getInputImage() const
//{
//    return inputImage;
//}

//void RotationWidget::setInputImage(const QImage &image)
//{
//    inputImage = image;
//}

//QImage RotationWidget::getOutputImage() const
//{
//    return outputImage;
//}

//void RotationWidget::setOutputImage(const QImage &image)
//{
//    outputImage = image;
//    emit outputImageChanged(image);
//}



