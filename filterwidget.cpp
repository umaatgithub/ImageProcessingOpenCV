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
    filterTypeLabel->setFixedHeight(15);

    filterTypeComboBox->addItem(QString("Bilateral"), "Bilateral");
    filterTypeComboBox->addItem(QString("Box"), "Box");
    filterTypeComboBox->addItem(QString("Gaussian"), "Gaussian");
    filterTypeComboBox->addItem(QString("Median"), "Median");
    filterTypeComboBox->setFixedHeight(20);

    filterRadiusLabel->setText(QString("Filter Radius : "));
    filterRadiusLabel->setFixedHeight(15);

    filterRadiusSpinBox->setRange(1, 31);
    filterRadiusSpinBox->setSingleStep(2);
    filterRadiusSpinBox->setFixedHeight(20);

    applyButton->setText(QString("Apply Changes"));

    layout->addWidget(filterTypeLabel, 0, 0);
    layout->addWidget(filterTypeComboBox, 1, 0);
    layout->addWidget(filterRadiusLabel, 2, 0);
    layout->addWidget(filterRadiusSpinBox, 3, 0);
    layout->addWidget(applyButton, 4, 0);

    layout->setRowMinimumHeight(0, 15);
    layout->setRowMinimumHeight(1, 20);
    layout->setRowMinimumHeight(2, 15);
    layout->setRowMinimumHeight(3, 20);
    layout->setRowStretch(4, 5);


    setLayout(layout);
}

void FilterWidget::applyButtonClicked()
{
    setOutputImage(filterImage.normalizedBoxFilter(getInputImage(), 20));
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

void FilterWidget::updateInputImage(QImage image)
{
    setInputImage(image);
}
