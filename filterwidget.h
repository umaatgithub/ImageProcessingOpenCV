#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <iostream>
#include "filterimage.h"

class FilterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FilterWidget(QWidget *parent = 0);
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
    QLabel *filterTypeLabel;
    QComboBox *filterTypeComboBox;
    QLabel *filterRadiusLabel;
    QSpinBox *filterRadiusSpinBox;
    QPushButton *applyButton;

    enum FilterType{ BILATERAL=0, BOX, GAUSSIAN, MEDIAN};

    QImage inputImage;
    QImage outputImage;
    FilterImage filterImage;
};

#endif // FILTERWIDGET_H
