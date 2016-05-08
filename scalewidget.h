#ifndef SCALEWIDGET_H
#define SCALEWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <iostream>
#include "scaleimage.h"

class ScaleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScaleWidget(QWidget *parent = 0);
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
    QLabel *scaleTypeLabel;
    QComboBox *scaleTypeComboBox;
    QLabel *scalePercentageLabel;
    QSpinBox *scalePercentageSpinBox;
    QPushButton *applyButton;

    enum ScaleType{ SCALE_DOWN=0, SCALE_UP};

    QImage inputImage;
    QImage outputImage;
    ScaleImage scaleImage;
};

#endif // SCALEWIDGET_H
