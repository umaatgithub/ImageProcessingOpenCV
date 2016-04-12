#ifndef IMAGEDISPLAYWIDGET_H
#define IMAGEDISPLAYWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QSlider>
#include <QResizeEvent>

class ImageDisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageDisplayWidget(QWidget *parent = 0);
    ~ImageDisplayWidget();
    void setupDisplayArea();
    void resizeEvent(QResizeEvent * event);

    QImage getDisplayImage() const;
    void setDisplayImage(const QImage &value);

signals:
    void imageChanged();


public slots:
    void updateDisplayArea();
    void updateDisplayImage(QImage image);

protected:
    QGridLayout *layout;
    QScrollArea *scrollArea;
    QLabel *imageDisplayLabel;
    QSlider *imageZoomSlider;
    QImage displayImage;
};

#endif // IMAGEDISPLAYWIDGET_H
