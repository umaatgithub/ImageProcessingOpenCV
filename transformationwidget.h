#ifndef TRANSFORMATIONWIDGET_H
#define TRANSFORMATIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
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

public slots:
    void updateInputImage(QImage image);
    void applyButtonClicked();

protected:
    QGridLayout *layout;
    QLabel *transformationTypeLabel;
    QComboBox *transformationTypeComboBox;
    QLabel *transformationRadiusLabel;
    QSpinBox *transformationRadiusSpinBox;
    QPushButton *applyButton;

    enum TransformationType{ BINARY=1, GRAYSCALE, ROTATE_LEFT, ROTATE_RIGHT, SCALE_DOWN, SCALE_UP};

    QImage inputImage;
    QImage outputImage;
    TransformationImage transformationImage;
};

#endif // TRANSFORMATIONWIDGET_H
