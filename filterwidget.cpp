#include "filterwidget.h"

FilterWidget::FilterWidget(QWidget *parent) : QWidget(parent), layout(new QGridLayout),
    filterTypeLabel(new QLabel), filterTypeComboBox(new QComboBox),
    filterRadiusLabel(new QLabel), filterRadiusSpinBox(new QSpinBox),
    applyButton(new QPushButton)
{
    setupWidget();
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonClicked()));
}

void FilterWidget::setupWidget()
{
    filterTypeLabel->setText(QString("Filter Type : "));
    filterTypeLabel->setFixedHeight(25);

    filterTypeComboBox->addItem(QString("Bilateral"), BILATERAL);
    filterTypeComboBox->addItem(QString("Box"), BOX);
    filterTypeComboBox->addItem(QString("Gaussian"), GAUSSIAN);
    filterTypeComboBox->addItem(QString("Median"), MEDIAN);
    filterTypeComboBox->setFixedHeight(25);

    filterRadiusLabel->setText(QString("Filter Radius : "));
    filterRadiusLabel->setFixedHeight(25);

    filterRadiusSpinBox->setRange(1, 31);
    filterRadiusSpinBox->setSingleStep(2);
    filterRadiusSpinBox->setFixedHeight(25);

    applyButton->setText(QString("Apply Changes"));
    applyButton->setFixedHeight(25);

    layout->addWidget(filterTypeLabel, 0, 0);
    layout->addWidget(filterTypeComboBox, 0, 1);
    layout->addWidget(filterRadiusLabel, 1, 0);
    layout->addWidget(filterRadiusSpinBox, 1, 1);
    layout->addWidget(applyButton, 2, 0, 2, 2);

    layout->setRowMinimumHeight(0, 30);
    layout->setRowMinimumHeight(1, 30);
//    layout->setRowMinimumHeight(2, 15);
//    layout->setRowMinimumHeight(3, 20);
//    layout->setRowStretch(4, 5);


    setLayout(layout);
}

void FilterWidget::applyButtonClicked()
{
    try{
    if(filterTypeComboBox->currentData() == BILATERAL){
        setOutputImage(filterImage.applyBilateralFilter(getInputImage(), filterRadiusSpinBox->value()));
    }
    else if(filterTypeComboBox->currentData() == BOX){
        setOutputImage(filterImage.applyNormalizedBoxFilter(getInputImage(), filterRadiusSpinBox->value()));
    }
    else if(filterTypeComboBox->currentData() == GAUSSIAN){
        setOutputImage(filterImage.applyGaussianFilter(getInputImage(), filterRadiusSpinBox->value()));
    }
    else if(filterTypeComboBox->currentData() == MEDIAN){
        setOutputImage(filterImage.applyMedianFilter(getInputImage(), filterRadiusSpinBox->value()));
    }
    }
    catch (const char* msg) {
         std::cerr << msg << std::endl;
       }
    catch(std::exception exp){
        std::cout<< exp.what();
    }
}

QImage FilterWidget::getInputImage() const
{
    return inputImage;
}

void FilterWidget::setInputImage(const QImage &image)
{
    inputImage = image;
}

QImage FilterWidget::getOutputImage() const
{
    return outputImage;
}

void FilterWidget::setOutputImage(const QImage &image)
{
    outputImage = image;
    emit outputImageChanged(image);
}

void FilterWidget::updateInputImage(QImage &image)
{
    setInputImage(image);
}
