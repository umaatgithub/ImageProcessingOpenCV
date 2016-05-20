#include "imageedgefiltertool.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize all the member variables
 *                     of the class, setup the UI
 *
 **************************************************************************/
ImageEdgeFilterTool::ImageEdgeFilterTool(QString name): ImageProcessingToolWidget(name), layout(new QGridLayout),
    edgeDetectorLabel(new QLabel), edgeDetectorComboBox(new QComboBox),
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
ImageEdgeFilterTool::~ImageEdgeFilterTool()
{
    delete applyButton;
    delete edgeDetectorComboBox;
    delete edgeDetectorLabel;
    delete layout;
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Function to setup the UI for the edge filter tool
 *
 **************************************************************************/
void ImageEdgeFilterTool::setupWidget()
{
    edgeDetectorLabel->setText(QString("Edge Detector : "));
    edgeDetectorLabel->setFixedHeight(25);

    edgeDetectorComboBox->addItem(QString("Canny"), CANNY);
    edgeDetectorComboBox->addItem(QString("Scharr"), SCHARR);
    edgeDetectorComboBox->addItem(QString("Sobel"), SOBEL);
    edgeDetectorComboBox->setFixedHeight(25);

    applyButton->setText(QString("Apply Changes"));
    applyButton->setFixedHeight(25);

    layout->addWidget(edgeDetectorLabel, 0, 0);
    layout->addWidget(edgeDetectorComboBox, 0, 1);
    layout->addWidget(applyButton, 2, 0, 2, 3);

    layout->setRowMinimumHeight(0, 30);
    layout->setRowMinimumHeight(1, 30);

    setLayout(layout);
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to handle apply button click. It calls the
 *                     edge filter function corresponding to the user
 *                     selection
 *
 **************************************************************************/
void ImageEdgeFilterTool::applyButtonClicked()
{
    try{
        emit statusChanged(QString(" Processing image..."), Qt::blue);
        if(!getInputImage()->isNull()){
            if(edgeDetectorComboBox->currentData() == CANNY){
                setOutputImage(edgeDetectionImage.applyCannysEdgeDetector(getInputImage()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(edgeDetectorComboBox->currentData() == SCHARR){
                setOutputImage(edgeDetectionImage.applyScharrEdgeDetector(getInputImage()));
                emit statusChanged(QString(" Done."), Qt::green);
            }
            else if(edgeDetectorComboBox->currentData() == SOBEL){
                setOutputImage(edgeDetectionImage.applySobelEdgeDetector(getInputImage()));
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
