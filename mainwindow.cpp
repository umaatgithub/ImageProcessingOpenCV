#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "imagesmootheningfilter.h"

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

MainWindow::~MainWindow()
{
    delete ui;
}

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

void MainWindow::on_actionUndo_triggered()
{
    imageChangeHistory->undoHistory();
}

void MainWindow::on_actionRedo_triggered()
{
    imageChangeHistory->redoHistory();
}

void MainWindow::on_actionSave_As_triggered()
{
    if(imageChangeHistory->imageExist()){
        QString filePath = QFileDialog::getSaveFileName(this, QString("Save Image"), imageChangeHistory->getImagePath(), QString("Images (*.png *.jpg *.bmp)"));
        imageChangeHistory->saveAsImage(filePath);
    }
}

void MainWindow::on_actionZoom_In_triggered()
{
    ui->centralWidget->getImageDisplayWidget()->zoomInDisplayImage();
}

void MainWindow::on_actionZoom_Out_triggered()
{
    ui->centralWidget->getImageDisplayWidget()->zoomOutDisplayImage();
}

void MainWindow::updateZoomStatus(float value)
{
    percentageZoomLabel->setText(QString("Image Zoom : ")+QString::number(value).append("%   "));

}

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

void MainWindow::on_actionCrop_triggered()
{
    ui->actionCrop->setEnabled(false);
    ui->actionRegion_Of_Interest->setEnabled(false);
    ui->actionSelect->setChecked(false);
    ui->centralWidget->getImageDisplayWidget()->cropDisplayImage();
}

void MainWindow::on_actionRegion_Of_Interest_triggered()
{
    ui->actionCrop->setEnabled(false);
    ui->actionRegion_Of_Interest->setEnabled(false);
    ui->actionSelect->setChecked(false);
    ui->centralWidget->getImageProcessingToolBoxWidget()->getFilterToolSet()->setRoiRect(ui->centralWidget->getImageDisplayWidget()->getImageDisplayLabel()->getSelectionRect());
    ui->centralWidget->getImageProcessingToolBoxWidget()->getMorphologyToolSet()->setRoiRect(ui->centralWidget->getImageDisplayWidget()->getImageDisplayLabel()->getSelectionRect());
}


void MainWindow::on_actionContrast_triggered()
{
    ui->centralWidget->getImageDisplayWidget()->autoContrastDisplayImage();
}

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

void MainWindow::connectSignalsAndSlots(){

    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage*,bool)),
            ui->centralWidget->getImageDisplayWidget(), SLOT(updateDisplayImage(QImage*, bool)));

    connect(ui->centralWidget->getImageDisplayWidget(),SIGNAL(percentageZoomChanged(float)), this, SLOT(updateZoomStatus(float)));

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

    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage*,bool)),
            ui->centralWidget->getInfoWidget(), SLOT(updateImageProperty(QImage*)));
    connect(imageChangeHistory, SIGNAL(imagePathUpdated(QString&)),
            ui->centralWidget->getInfoWidget(), SLOT(updateImagePath(QString&)));


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

    connect(ui->centralWidget->getImageDisplayWidget(), SIGNAL(imageChanged(QImage*)),
            imageChangeHistory, SLOT(updateImageHistory(QImage*)));

    connect(ui->centralWidget->getImageDisplayWidget()->getImageDisplayLabel(), SIGNAL(selectionUpdated(QRect*)),
            this, SLOT(enableCropAndROI(QRect*)));

}

