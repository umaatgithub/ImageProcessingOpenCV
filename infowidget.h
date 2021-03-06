#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QImage>
#include <vector>

class InfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InfoWidget(QWidget *parent = 0);
    ~InfoWidget();

    //Function to setup the widget
    void setupWidget();

    void resizeEvent(QResizeEvent *);

public slots:
    void updateImageProperty(QImage* image);
    void updateImagePath(QString &path);

protected:
    QGridLayout *layout;
    QTableWidget *infoTable;
    std::vector<QString> imagePropertyLabel;
    enum ImagePropertyIndex{ NAME=0, HEIGHT, WIDTH, FORMAT, PATH};
};

#endif // INFOWIDGET_H
