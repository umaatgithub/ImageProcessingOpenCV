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

class MorphologyWidget : public ImageProcessingToolWidget
{
    Q_OBJECT
public:
    explicit MorphologyWidget(QString name);
    void setupWidget();

public slots:
    void applyButtonClicked();
    void updateCheckBox();

protected:
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
