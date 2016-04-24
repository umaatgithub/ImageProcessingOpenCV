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
    void setupWidget();

    void resizeEvent(QResizeEvent* event);

    void setImage(const QImage &value);

signals:

public slots:
    //void updateImage(QImage image);

protected:
    QGridLayout *layout;
    QTableWidget *infoTable;
    QImage image;
    std::vector<QString> imagePropertyLabel;
    enum ImagePropertyIndex{ NAME=0, HEIGHT, WIDTH, FORMAT, PATH};
};

#endif // INFOWIDGET_H
