#include "imagesmootheningfiltertool.h"

FilterWidget::FilterWidget(QString name): ImageProcessingToolWidget(name), layout(new QGridLayout),
    filterTypeLabel(new QLabel), filterTypeComboBox(new QComboBox),
    filterRadiusLabel(new QLabel), filterRadiusSpinBox(new QSpinBox), roiLabel(new QLabel), roiCheckBox(new QCheckBox),
    applyButton(new QPushButton)
{
    setupWidget();
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyButtonClicked()));
    connect(this, SIGNAL(roiRectUpdated()), this, SLOT(updateCheckBox()));
    connect(this, SIGNAL(inputImageChanged(QImage*)), this, SLOT(updateCheckBox()));
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

    roiLabel->setText(QString("Region Of Interest : "));
    roiLabel->setFixedHeight(25);

    roiCheckBox->setChecked(false);
    roiCheckBox->setEnabled(false);
    roiCheckBox->setFixedHeight(25);


    applyButton->setText(QString("Apply Changes"));
    applyButton->setFixedHeight(25);

    layout->addWidget(filterTypeLabel, 0, 0);
    layout->addWidget(filterTypeComboBox, 0, 1);
    layout->addWidget(filterRadiusLabel, 1, 0);
    layout->addWidget(filterRadiusSpinBox, 1, 1);
    layout->addWidget(roiLabel, 2, 0);
    layout->addWidget(roiCheckBox, 2, 1);
    layout->addWidget(applyButton, 3, 0, 2, 2);

    layout->setRowMinimumHeight(0, 30);
    layout->setRowMinimumHeight(1, 30);

    setLayout(layout);
}

void FilterWidget::applyButtonClicked()
{
    try{
        emit statusChanged(QString(" Processing image..."), Qt::blue);
        if(!getInputImage()->isNull()){
            if(filterTypeComboBox->currentData() == BILATERAL){
                setOutputImage(filterImage.applyBilateralFilter(getInputImage(),
                                                                filterRadiusSpinBox->value(),
                                                                roiCheckBox->isChecked(),
                                                                getRoiRect()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(filterTypeComboBox->currentData() == BOX){
                setOutputImage(filterImage.applyNormalizedBoxFilter(getInputImage(),
                                                                    filterRadiusSpinBox->value(),
                                                                    roiCheckBox->isChecked(),
                                                                    getRoiRect()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(filterTypeComboBox->currentData() == GAUSSIAN){
                setOutputImage(filterImage.applyGaussianFilter(getInputImage(),
                                                               filterRadiusSpinBox->value(),
                                                               roiCheckBox->isChecked(),
                                                               getRoiRect()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(filterTypeComboBox->currentData() == MEDIAN){
                setOutputImage(filterImage.applyMedianFilter(getInputImage(),
                                                             filterRadiusSpinBox->value(),
                                                             roiCheckBox->isChecked(),
                                                             getRoiRect()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
        }
        else{
            emit statusChanged(QString(" Image not set."), Qt::black);
        }
    }
    catch (const char* msg) {
        //std::cerr << msg << std::endl;
        emit statusChanged(QString(msg), Qt::red);
    }
    catch(std::exception exp){
        //std::cerr << exp.what();
        emit statusChanged(QString(" Error."), Qt::red);
    }
}

void FilterWidget::updateCheckBox()
{
    if(!getRoiRect()->isNull() && isRoiRectValid()){
        roiCheckBox->setEnabled(true);
    }
    else{
        roiCheckBox->setEnabled(false);
        roiCheckBox->setChecked(false);
    }
}
