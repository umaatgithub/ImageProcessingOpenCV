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
    //Constructor and Destructor
    explicit ImageDisplayWidget(QWidget *parent = 0);
    ~ImageDisplayWidget();

    void setupDisplayArea();                    //Function to setup the display area
    void zoomInDisplayImage();
    void zoomOutDisplayImage();
    void cropDisplayImage();
    void autoContrastDisplayImage();

    float getPercentageZoom() const;
    void setPercentageZoom(float value);

    DisplayLabel *getImageDisplayLabel() const;
    void setImageDisplayLabel(DisplayLabel *value);

    QImage *getDisplayImage() const;
    void setDisplayImage(QImage *value);

signals:
    void imageChanged(QImage*);
    void percentageZoomChanged(float);

public slots:
    void updateDisplayArea();
    void updateDisplayImage(QImage* image, bool newImage);

protected:
    QGridLayout *layout;
    QScrollArea *scrollArea;
    DisplayLabel *imageDisplayLabel;
    QImage *displayImage;\
    float percentageZoom;

};

#endif // IMAGEDISPLAYWIDGET_H
