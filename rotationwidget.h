#ifndef ROTATIONWIDGET_H
#define ROTATIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
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

public slots:
    void updateInputImage(QImage image);
    void applyButtonClicked();

protected:
    QGridLayout *layout;
    QLabel *rotationTypeLabel;
    QComboBox *rotationTypeComboBox;
    QLabel *rotationRadiusLabel;
    QSpinBox *rotationRadiusSpinBox;
    QPushButton *applyButton;

    enum RotationType{ ROTATE_LEFT=1, ROTATE_RIGHT};

    QImage inputImage;
    QImage outputImage;
    RotationImage rotationImage;
};

#endif // ROTATIONWIDGET_H
