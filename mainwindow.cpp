#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this,
         QString("Open Image"), QString(""), QString("Images (*.png *.jpg *.bmp)"));
    ui->centralWidget->imageDisplayWidget->setImageFullPath(filePath);
}
