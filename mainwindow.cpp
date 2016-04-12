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

    connect(ui->centralWidget->getImageProcessingToolBoxWidget()->getFilterToolSet(), SIGNAL(outputImageChanged(QImage)),
            imageChangeHistory, SLOT(updateImageHistory(QImage)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, QString("Open Image"), QString(""), QString("Images (*.png *.jpg *.bmp)"));
    imageChangeHistory->setImagePath(filePath);
}

void MainWindow::on_actionUndo_triggered()
{
    imageChangeHistory->undoHistory();
}

void MainWindow::on_actionRedo_triggered()
{
    imageChangeHistory->redoHistory();
}
