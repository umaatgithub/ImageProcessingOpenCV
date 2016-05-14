#ifndef IMAGETRANSFORMATIONTOOL_H
#define IMAGETRANSFORMATIONTOOL_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include "imageprocessingtoolwidget.h"
#include "imagetransformation.h"

class ImageTransformationTool : public ImageProcessingToolWidget
{
    Q_OBJECT
public:
    explicit ImageTransformationTool(QString name);
    void setupWidget();

public slots:
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

    ImageTransformation transformationImage;
};

#endif // IMAGETRANSFORMATIONTOOL_H
