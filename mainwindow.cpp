#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "filterimage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), imageChangeHistory(new ImageChangeHistory)
{
    ui->setupUi(this);
    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage)),
            ui->centralWidget->getImageDisplayWidget(), SLOT(updateDisplayImage(QImage)));

    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage)),
            ui->centralWidget->getImageProcessingToolBoxWidget()->getFilterToolSet(), SLOT(updateInputImage(QImage)));
    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage)),
            ui->centralWidget->getImageProcessingToolBoxWidget()->getMorphologyToolSet(), SLOT(updateInputImage(QImage)));
    connect(imageChangeHistory, SIGNAL(imageHistoryUpdated(QImage)),
            ui->centralWidget->getImageProcessingToolBoxWidget()->getTransformationToolSet(), SLOT(updateInputImage(QImage)));


    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getFilterToolSet(), SIGNAL(outputImageChanged(QImage)),
            imageChangeHistory, SLOT(updateImageHistory(QImage)));
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getMorphologyToolSet(), SIGNAL(outputImageChanged(QImage)),
            imageChangeHistory, SLOT(updateImageHistory(QImage)));
    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getTransformationToolSet(), SIGNAL(outputImageChanged(QImage)),
            imageChangeHistory, SLOT(updateImageHistory(QImage)));

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
        response = QMessageBox::question(this, QString("Image Processing"), QString("Do you want to save changes to the image?"),
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
