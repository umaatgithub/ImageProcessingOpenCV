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
    //Constructor and Destructor
    explicit ImageTransformationTool(QString name);
    ~ImageTransformationTool();

    //Function to setup the widget
    void setupWidget();

public slots:
    //Slot for apply button clicked
    void applyButtonClicked();
    //Slot called when selection is changed in transformation type combo box
    void modifyWidgetOptions(int currentIndex);

protected:
    //Widget layout and elements
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
