#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();

//    FilterImage filterImage;
//    filterImage.executeFilter();

    return a.exec();
}
