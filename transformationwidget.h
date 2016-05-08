#ifndef TRANSFORMATIONWIDGET_H
#define TRANSFORMATIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <iostream>
#include "transformationimage.h"

class TransformationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TransformationWidget(QWidget *parent = 0);
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
    void modifyWidgetOptions(int currentIndex);

protected:
    QGridLayout *layout;
    QLabel *transformationTypeLabel;
    QComboBox *transformationTypeComboBox;
    QLabel *thresholdPercentageLabel;
    QSpinBox *thresholdPercentageSpinBox;
    QPushButton *applyButton;

    enum TransformationType{ BINARY=0, GRAYSCALE, NEGATIVE};

    QImage inputImage;
    QImage outputImage;
    TransformationImage transformationImage;
};

#endif // TRANSFORMATIONWIDGET_H
