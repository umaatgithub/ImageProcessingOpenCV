#include "infowidget.h"
#include <iostream>

InfoWidget::InfoWidget(QWidget *parent) : QWidget(parent), layout(new QGridLayout),
    infoTable(new QTableWidget)
{
    imagePropertyLabel.resize(5);
    imagePropertyLabel[NAME] = QString(" Name");
    imagePropertyLabel[HEIGHT] = QString(" Height");
    imagePropertyLabel[WIDTH] = QString(" Width");
    imagePropertyLabel[FORMAT] = QString(" Format");
    imagePropertyLabel[PATH] = QString(" Path");

    setupWidget();
}

void InfoWidget::setupWidget()
{
    infoTable->verticalHeader()->setVisible(false);
    infoTable->setRowCount(5);
    infoTable->setColumnCount(2);
    infoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QTableWidgetItem *propertyColumnHeader = new QTableWidgetItem();
    propertyColumnHeader->setText("Property");
    infoTable->setHorizontalHeaderItem(0, propertyColumnHeader);

    QTableWidgetItem *valueColumnHeader = new QTableWidgetItem();
    valueColumnHeader->setText("Value");
    infoTable->setHorizontalHeaderItem(1, valueColumnHeader);

    for(int i=0; i<5 ; i++){
        QTableWidgetItem *qtablewidgetitem = new QTableWidgetItem();
        qtablewidgetitem->setText(imagePropertyLabel[i]);
        infoTable->setItem(i, 0, qtablewidgetitem);

        qtablewidgetitem = new QTableWidgetItem();
        qtablewidgetitem->setText("");
        infoTable->setItem(i, 1, qtablewidgetitem);
    }

    infoTable->setColumnWidth(0,width()/3.0 - 19);
    infoTable->setColumnWidth(1,width()*2.0/3.0);
    layout->addWidget(infoTable, 0, 0);

    setLayout(layout);
}

void InfoWidget::resizeEvent(QResizeEvent * /* event */)
{
    infoTable->setColumnWidth(0,width()/3.0 - 19);
    infoTable->setColumnWidth(1,width()*2.0/3.0);
}

void InfoWidget::updateImageProperty(QImage &image)
{
    infoTable->item(HEIGHT, 1)->setText(QString::number(image.height()));
    infoTable->item(WIDTH, 1)->setText(QString::number(image.width()));
    if(image.format()==QImage::Format_RGB32){
        infoTable->item(FORMAT,1)->setText(QString("RGB32"));
    }
    else if(image.format()==QImage::Format_Indexed8){
        infoTable->item(FORMAT,1)->setText(QString("Indexed8"));
    }
    else if(image.format()==QImage::Format_Grayscale8){
        infoTable->item(FORMAT,1)->setText(QString("Grayscale8"));
    }
    else if(image.format()==QImage::Format_RGB888){
        infoTable->item(FORMAT,1)->setText(QString("RGB888"));
    }
    else{
        infoTable->item(FORMAT,1)->setText(QString("Not supported"));;
    }

}

void InfoWidget::updateImagePath(QString &path)
{
    QString name = path;
    QString folderPath = path;
    int backslashIndex = path.lastIndexOf('/');

    infoTable->item(NAME, 1)->setText(name.remove(0, backslashIndex+1));
    infoTable->item(NAME, 1)->setToolTip(name);

    infoTable->item(PATH, 1)->setText(folderPath.remove(backslashIndex, name.length()+1));
    infoTable->item(PATH, 1)->setToolTip(folderPath);
}

