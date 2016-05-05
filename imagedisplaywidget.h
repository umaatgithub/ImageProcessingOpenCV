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
    //void resizeEvent(QResizeEvent * event);
    float zoomInDisplayImage();
    float zoomOutDisplayImage();

    QImage getDisplayImage() const;
    void setDisplayImage(const QImage &value);

    float getPercentageZoom() const;
    void setPercentageZoom(float value);

signals:
    void imageChanged();
    void percentageZoomChanged(float value);

public slots:
    void updateDisplayArea();
    void updateDisplayImage(QImage &image, bool newImage);

protected:
    QGridLayout *layout;
    QScrollArea *scrollArea;
    QLabel *imageDisplayLabel;
    QImage displayImage;
    float percentageZoom;
};

#endif // IMAGEDISPLAYWIDGET_H
