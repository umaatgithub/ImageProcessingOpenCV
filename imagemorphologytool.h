#ifndef IMAGEMORPHOLOGYTOOL_H
#define IMAGEMORPHOLOGYTOOL_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include "imageprocessingtoolwidget.h"
#include "imagemorphology.h"

class ImageMorphologyTool : public ImageProcessingToolWidget
{
    Q_OBJECT
public:
    //Constructor and Destructor
    explicit ImageMorphologyTool(QString name);
    ~ImageMorphologyTool();

    //Function to setup the widget
    void setupWidget();

public slots:
    //Slot for apply button clicked
    void applyButtonClicked();
    //Slot for updating ROI check box when region is updated
    void updateCheckBox();

protected:
    //Widget layout and elements
    QGridLayout *layout;
    QLabel *morphologyTypeLabel;
    QComboBox *morphologyTypeComboBox;
    QLabel *morphologyRadiusLabel;
    QSpinBox *morphologyRadiusSpinBox;
    QLabel *roiLabel;
    QCheckBox *roiCheckBox;
    QPushButton *applyButton;

    enum MorphologyType{ CLOSING=0, DILATE, ERODE, OPENING};

    ImageMorphology morphologyImage;
};

#endif // IMAGEMORPHOLOGYTOOL_H
