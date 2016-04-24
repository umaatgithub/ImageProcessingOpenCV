#include "infowidget.h"

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
    infoTable->setEnabled(false);
    infoTable->verticalHeader()->setVisible(false);
    infoTable->setRowCount(5);
    infoTable->setColumnCount(2);

    QTableWidgetItem *qtablewidgetitemheader = new QTableWidgetItem();
    qtablewidgetitemheader->setText("Property");
    infoTable->setHorizontalHeaderItem(0, qtablewidgetitemheader);

    QTableWidgetItem *qtablewidgetitemheader1 = new QTableWidgetItem();
    qtablewidgetitemheader1->setText("Value");
    infoTable->setHorizontalHeaderItem(1, qtablewidgetitemheader1);

    for(int i=0; i<5 ; i++){
        QTableWidgetItem *qtablewidgetitem = new QTableWidgetItem();
        qtablewidgetitem->setText(imagePropertyLabel[i]);
        infoTable->setItem(i, 0, qtablewidgetitem);
    }
//    infoTable->horizontalHeaderItem(0)->setText("Property");
//    infoTable->horizontalHeaderItem(1)->setText("Value");
//    QTableWidgetItem *qtablewidgetitem1= new QTableWidgetItem();
//    qtablewidgetitem1->setText(" Name");
//    infoTable->setItem(0, 0, qtablewidgetitem1);

//    QTableWidgetItem *qtablewidgetitem2= new QTableWidgetItem();
//    qtablewidgetitem2->setText(" Height");
//    infoTable->setItem(1, 0, qtablewidgetitem2);

//    QTableWidgetItem *qtablewidgetitem3= new QTableWidgetItem();
//    qtablewidgetitem3->setText(" Width");
//    infoTable->setItem(2, 0, qtablewidgetitem3);


//    QTableWidgetItem *qtablewidgetitem4= new QTableWidgetItem();
//    qtablewidgetitem4->setText(" Format");
//    infoTable->setItem(3, 0, qtablewidgetitem4);

//    QTableWidgetItem *qtablewidgetitem5= new QTableWidgetItem();
//    qtablewidgetitem5->setText(" Path");
//    infoTable->setItem(4, 0, qtablewidgetitem5);


    infoTable->setColumnWidth(0,width()/3.0 - 19);
    infoTable->setColumnWidth(1,width()*2.0/3.0);
    layout->addWidget(infoTable, 0, 0);

    setLayout(layout);
}

void InfoWidget::resizeEvent(QResizeEvent *event)
{
    infoTable->setColumnWidth(0,width()/3.0 - 19);
    infoTable->setColumnWidth(1,width()*2.0/3.0);
}

void InfoWidget::setImage(const QImage &value)
{
    image = value;
}

//void InfoWidget::updateInputImage(QImage image)
//{
//    setImage(image);
//}

