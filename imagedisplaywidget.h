#ifndef IMAGEDISPLAYWIDGET_H
#define IMAGEDISPLAYWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>

class ImageDisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageDisplayWidget(QWidget *parent = 0);
    ~ImageDisplayWidget();
    void setupDisplayArea();

signals:

public slots:

protected:
    QGridLayout *layout;
    QScrollArea *scrollArea;
    QLabel *imageDisplayLabel;
};

#endif // IMAGEDISPLAYWIDGET_H
