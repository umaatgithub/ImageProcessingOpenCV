#ifndef ROTATIONWIDGET_H
#define ROTATIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <iostream>
#include "rotationimage.h"

class RotationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RotationWidget(QWidget *parent = 0);
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
    QLabel *directionLabel;
    QComboBox *directionComboBox;
    QLabel *angleLabel;
    QSpinBox *angleSpinBox;
    QPushButton *applyButton;

    enum RotationDirection{ ANTI_CLOCKWISE=0, CLOCKWISE};

    QImage inputImage;
    QImage outputImage;
    RotationImage rotationImage;
};

#endif // ROTATIONWIDGET_H
