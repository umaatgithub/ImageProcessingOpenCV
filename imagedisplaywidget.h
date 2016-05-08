#ifndef IMAGEDISPLAYWIDGET_H
#define IMAGEDISPLAYWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QSlider>
#include <QResizeEvent>
#include "displaylabel.h"
#include "qtopencvbridge.h"

class ImageDisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageDisplayWidget(QWidget *parent = 0);
    ~ImageDisplayWidget();
    void setupDisplayArea();
    void zoomInDisplayImage();
    void zoomOutDisplayImage();
    void cropDisplayImage();
    void autoContrastDisplayImage();

    QImage getDisplayImage() const;
    void setDisplayImage(const QImage &value);

    float getPercentageZoom() const;
    void setPercentageZoom(float value);

    DisplayLabel *getImageDisplayLabel() const;
    void setImageDisplayLabel(DisplayLabel *value);

    QRect getSelectionRect() const;
    void setSelectionRect(const QRect &value);

signals:
    void imageChanged(QImage);
    void percentageZoomChanged(float);

public slots:
    void updateDisplayArea();
    void updateDisplayImage(QImage &image, bool newImage);
    void updateSelectionRect(QRect& rect);

protected:
    QGridLayout *layout;
    QScrollArea *scrollArea;
    DisplayLabel *imageDisplayLabel;
    QImage displayImage;
    float percentageZoom;
    QRect selectionRect;
};

#endif // IMAGEDISPLAYWIDGET_H
