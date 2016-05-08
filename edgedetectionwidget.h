#ifndef EDGEDETECTIONWIDGET_H
#define EDGEDETECTIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <iostream>
#include "edgedetectionimage.h"

class EdgeDetectionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EdgeDetectionWidget(QWidget *parent = 0);
    void setupWidget();

    void setInputImage(const QImage &image);
    QImage getInputImage() const;

    QImage getOutputImage() const;
    void setOutputImage(const QImage &image);

signals:
    void outputImageChanged(QImage image);
    void statusChanged(QString status, QColor statusColor = Qt::blue);

public slots:
    void updateInputImage(QImage &image);
    void applyButtonClicked();

protected:
    QGridLayout *layout;
    QLabel *edgeDetectorLabel;
    QComboBox *edgeDetectorComboBox;
    QLabel *filterRadiusLabel;
    QSpinBox *filterRadiusSpinBox;
    QPushButton *applyButton;

    enum FilterType{ CANNY=0, SCHARR, SOBEL};

    QImage inputImage;
    QImage outputImage;
    EdgeDetectionImage edgeDetectionImage;

};

#endif // EDGEDETECTIONWIDGET_H
