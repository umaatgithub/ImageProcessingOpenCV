#ifndef MORPHOLOGYWIDGET_H
#define MORPHOLOGYWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include "morphologyimage.h"

class MorphologyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MorphologyWidget(QWidget *parent = 0);
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
    QLabel *morphologyTypeLabel;
    QComboBox *morphologyTypeComboBox;
    QLabel *morphologyRadiusLabel;
    QSpinBox *morphologyRadiusSpinBox;
    QPushButton *applyButton;

    enum MorphologyType{ CLOSING=1, DILATE, ERODE, OPENING};

    QImage inputImage;
    QImage outputImage;
    MorphologyImage morphologyImage;
};

#endif // MORPHOLOGYWIDGET_H
