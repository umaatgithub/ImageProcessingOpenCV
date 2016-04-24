#ifndef SCALEWIDGET_H
#define SCALEWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
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

public slots:
    void updateInputImage(QImage image);
    void applyButtonClicked();

protected:
    QGridLayout *layout;
    QLabel *scaleTypeLabel;
    QComboBox *scaleTypeComboBox;
    QLabel *scaleRadiusLabel;
    QSpinBox *scaleRadiusSpinBox;
    QPushButton *applyButton;

    enum ScaleType{ SCALE_DOWN=1, SCALE_UP};

    QImage inputImage;
    QImage outputImage;
    ScaleImage scaleImage;
};

#endif // SCALEWIDGET_H
