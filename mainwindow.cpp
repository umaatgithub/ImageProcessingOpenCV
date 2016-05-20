#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "imagesmootheningfilter.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize all the member variables
 *                     of the class and to setup the UI
 *
 **************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), imageChangeHistory(new ImageChangeHistory),
    percentageZoomLabel(new QLabel)
{
    ui->setupUi(this);
    percentageZoomLabel->setStyleSheet("QLabel { color : black; }");
    ui->statusBar->addPermanentWidget(percentageZoomLabel);

    connectSignalsAndSlots();
}

/***************************************************************************
 * Input argument(s) : NIL
 * Return type       : NIL
 * Functionality     : Destructor to delete all the pointer variables
 *
 **************************************************************************/
MainWindow::~MainWindow()
{
    delete percentageZoomLabel;
    delete imageChangeHistory;
    delete ui;
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to handle new/open tool bar action triggered.
 *                     The path of the image is got from the user by
 *                     QFileDialog and it is passed to the loadImage
 *                     function of ImageChangeHistory.
 *
 **************************************************************************/
void MainWindow::on_actionNew_triggered()
{
    if(imageChangeHistory->previousChangesSaved()){
        QString filePath = QFileDialog::getOpenFileName(this, QString("Open Image"), QString(""), QString("Images (*.png *.jpg *.bmp)"));
        imageChangeHistory->loadImage(filePath);
    }
    else{
        QMessageBox::StandardButton response;
        response = QMessageBox::question(this, QString("Image Processing"), QString("Do you want to save changes to the image?               "),
                              QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel, QMessageBox::Save);
        if(response == QMessageBox::Save){
            emit ui->actionSave_As->trigger();
        }
        else if(response == QMessageBox::Discard){
            QString filePath = QFileDialog::getOpenFileName(this, QString("Open Image"), QString(""), QString("Images (*.png *.jpg *.bmp)"));
            imageChangeHistory->loadImage(filePath);
        }
        else{
            //DO NOTHING
        }
    }
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to handle undo tool bar action triggered. It
 *                     calls the undoHistory function of ImageChangeHistory
 *                     class.
 *
 **************************************************************************/
void MainWindow::on_actionUndo_triggered()
{
    imageChangeHistory->undoHistory();
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to handle redo tool bar action triggered. It
 *                     calls the redoHistory function of ImageChangeHistory
 *                     class.
 *
 **************************************************************************/
void MainWindow::on_actionRedo_triggered()
{
    imageChangeHistory->redoHistory();
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to handle save as tool bar action triggered.
 *                     It checks if there is any image open in the display
 *                     and opens QFileDialog to get the path where the
 *                     has to be saved and finally invokes the saveAsImage
 *                     function from ImageChangeHistory
 *
 **************************************************************************/
void MainWindow::on_actionSave_As_triggered()
{
    if(imageChangeHistory->imageExist()){
        QString filePath = QFileDialog::getSaveFileName(this, QString("Save Image"), imageChangeHistory->getImagePath(), QString("Images (*.png *.jpg *.bmp)"));
        imageChangeHistory->saveAsImage(filePath);
    }
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to handle zoom in tool bar action triggered. It
 *                     calls the zoomInDisplayImage function of
 *                     ImageDisplayWidget class.
 *
 **************************************************************************/
void MainWindow::on_actionZoom_In_triggered()
{
    ui->centralWidget->getImageDisplayWidget()->zoomInDisplayImage();
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to handle zoom out tool bar action triggered. It
 *                     calls the zoomOutDisplayImage function of
 *                     ImageDisplayWidget class.
 *
 **************************************************************************/
void MainWindow::on_actionZoom_Out_triggered()
{
    ui->centralWidget->getImageDisplayWidget()->zoomOutDisplayImage();
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to handle select tool bar action triggered. It
 *                     is used to enable or disable the selection tool.
 *
 **************************************************************************/
void MainWindow::on_actionSelect_triggered(bool checked)
{
    if(checked == true){
        ui->centralWidget->getImageDisplayWidget()->getImageDisplayLabel()->enableSelection();
    }
    else{
        ui->centralWidget->getImageDisplayWidget()->getImageDisplayLabel()->disableSelection();
        ui->actionCrop->setEnabled(false);
        ui->actionRegion_Of_Interest->setEnabled(false);
    }
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to handle crop image tool bar action triggered.
 *                     It disables all the tool bar items related to
 *                     selection and calls the cropDisplayImage function
 *                     of ImageDisplayWidget class.
 *
 **************************************************************************/
void MainWindow::on_actionCrop_triggered()
{
    ui->actionCrop->setEnabled(false);
    ui->actionRegion_Of_Interest->setEnabled(false);
    ui->actionSelect->setChecked(false);
    ui->centralWidget->getImageDisplayWidget()->cropDisplayImage();
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to handle region of interest tool bar action
 *                     triggered. It disables all the tool bar items related
 *                     to selection and sets the ROI rect of the tool boxes.
 *
 **************************************************************************/
void MainWindow::on_actionRegion_Of_Interest_triggered()
{
    ui->actionCrop->setEnabled(false);
    ui->actionRegion_Of_Interest->setEnabled(false);
    ui->actionSelect->setChecked(false);
    ui->centralWidget->getImageProcessingToolBoxWidget()->getFilterToolSet()->
            setRoiRect(ui->centralWidget->getImageDisplayWidget()->getImageDisplayLabel()->getSelectionRect());
    ui->centralWidget->getImageProcessingToolBoxWidget()->getMorphologyToolSet()->
            setRoiRect(ui->centralWidget->getImageDisplayWidget()->getImageDisplayLabel()->getSelectionRect());
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to handle auto contrast tool bar action
 *                     triggered. It calls the autoContrastDisplayImage
 *                     function of ImageDisplayWidget class.
 *
 **************************************************************************/
void MainWindow::on_actionContrast_triggered()
{
    ui->centralWidget->getImageDisplayWidget()->autoContrastDisplayImage();
}

/***************************************************************************
 * Input argument(s) : float value - Value of zoom to be set in status bar
 * Return type       : void
 * Functionality     : Slot to update image zoom value in status bar
 *
 **************************************************************************/
void MainWindow::updateZoomStatus(float value)
{
    percentageZoomLabel->setText(QString("Image Zoom : ")+QString::number(value).append("%   "));

}

/***************************************************************************
 * Input argument(s) : QRect *selectionRect - Region selected by the user
 * Return type       : void
 * Functionality     : Slot to enable crop and roi in tool bar when the
 *                     region selected by the user satisfies few conditions
 *
 **************************************************************************/
void MainWindow::enableCropAndROI(QRect *selectionRect)
{
    if(selectionRect->width()!=0 && selectionRect->height()!=0){
        ui->actionCrop->setEnabled(true);
        ui->actionRegion_Of_Interest->setEnabled(true);
    }
    else{
        ui->actionCrop->setEnabled(false);
        ui->actionRegion_Of_Interest->setEnabled(false);
    }
}

/***************************************************************************
 * Input argument(s) : QString status - Status message to be displayed
 *                     QColor statusColor - Colour to be set for the
 *                     displayed message
 * Return type       : void
 * Functionality     : Slot to display temporary messages in status bar
 *
 **************************************************************************/
void MainWindow::updateStatusBar(QString status, QColor statusColor)
{
    QPalette statusBarPalette;
    statusBarPalette.setColor( QPalette::WindowText, statusColor );
    ui->statusBar->setPalette(statusBarPalette);
    if(statusColor == Qt::blue){
        ui->statusBar->showMessage(status);
    }
    else{
        ui->statusBar->showMessage(status, 5000);
    }
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Function to connect all the signals and slots.
 *
 **************************************************************************/
void MainWindow::connectSignalsAndSlots(){

    //Update display image when image history is updated
    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage*,bool)),
            ui->centralWidget->getImageDisplayWidget(), SLOT(updateDisplayImage(QImage*, bool)));

    //Update zoom value in status bar when percentage zoom is chaged
    connect(ui->centralWidget->getImageDisplayWidget(),SIGNAL(percentageZoomChanged(float)), this, SLOT(updateZoomStatus(float)));

    //Display the status of the image when it is being processed
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getFilterToolSet(), SIGNAL(statusChanged(QString, QColor)),
            this, SLOT(updateStatusBar(QString, QColor)));
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getMorphologyToolSet(), SIGNAL(statusChanged(QString, QColor)),
            this, SLOT(updateStatusBar(QString, QColor)));
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getTransformationToolSet(), SIGNAL(statusChanged(QString, QColor)),
            this, SLOT(updateStatusBar(QString, QColor)));
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getRotationToolSet(), SIGNAL(statusChanged(QString, QColor)),
            this, SLOT(updateStatusBar(QString, QColor)));
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getScaleToolSet(), SIGNAL(statusChanged(QString, QColor)),
            this, SLOT(updateStatusBar(QString, QColor)));
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getEdgeDetectionToolSet(), SIGNAL(statusChanged(QString, QColor)),
            this, SLOT(updateStatusBar(QString, QColor)));


    //Update input image of the toolsets when image history is updated
    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage*,bool)),
            ui->centralWidget->getImageProcessingToolBoxWidget()->getFilterToolSet(), SLOT(updateInputImage(QImage*)));
    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage*,bool)),
            ui->centralWidget->getImageProcessingToolBoxWidget()->getMorphologyToolSet(), SLOT(updateInputImage(QImage*)));
    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage*,bool)),
            ui->centralWidget->getImageProcessingToolBoxWidget()->getTransformationToolSet(), SLOT(updateInputImage(QImage*)));
    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage*,bool)),
            ui->centralWidget->getImageProcessingToolBoxWidget()->getRotationToolSet(), SLOT(updateInputImage(QImage*)));
    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage*,bool)),
            ui->centralWidget->getImageProcessingToolBoxWidget()->getScaleToolSet(), SLOT(updateInputImage(QImage*)));
    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage*,bool)),
            ui->centralWidget->getImageProcessingToolBoxWidget()->getEdgeDetectionToolSet(), SLOT(updateInputImage(QImage*)));

    //Update information widget when image history is update
    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage*,bool)),
            ui->centralWidget->getInfoWidget(), SLOT(updateImageProperty(QImage*)));
    connect(imageChangeHistory, SIGNAL(imagePathUpdated(QString&)),
            ui->centralWidget->getInfoWidget(), SLOT(updateImagePath(QString&)));

    //Update image history after image is processed by the toolset
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getFilterToolSet(), SIGNAL(outputImageChanged(QImage*)),
            imageChangeHistory, SLOT(updateImageHistory(QImage*)));
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getMorphologyToolSet(), SIGNAL(outputImageChanged(QImage*)),
            imageChangeHistory, SLOT(updateImageHistory(QImage*)));
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getTransformationToolSet(), SIGNAL(outputImageChanged(QImage*)),
            imageChangeHistory, SLOT(updateImageHistory(QImage*)));
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getRotationToolSet(), SIGNAL(outputImageChanged(QImage*)),
            imageChangeHistory, SLOT(updateImageHistory(QImage*)));
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getScaleToolSet(), SIGNAL(outputImageChanged(QImage*)),
            imageChangeHistory, SLOT(updateImageHistory(QImage*)));
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getEdgeDetectionToolSet(), SIGNAL(outputImageChanged(QImage*)),
            imageChangeHistory, SLOT(updateImageHistory(QImage*)));

    //Update image history when image is cropped
    connect(ui->centralWidget->getImageDisplayWidget(), SIGNAL(imageChanged(QImage*)),
            imageChangeHistory, SLOT(updateImageHistory(QImage*)));

    //Enable crop and roi if the region is selected
    connect(ui->centralWidget->getImageDisplayWidget()->getImageDisplayLabel(), SIGNAL(selectionUpdated(QRect*)),
            this, SLOT(enableCropAndROI(QRect*)));

}

