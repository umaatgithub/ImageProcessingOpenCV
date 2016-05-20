#ifndef IMAGESCALINGTOOL_H
#define IMAGESCALINGTOOL_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include "imageprocessingtoolwidget.h"
#include "imagescaling.h"

class ImageScalingTool : public ImageProcessingToolWidget
{
    Q_OBJECT
public:
    //Constructor and Destructor
    explicit ImageScalingTool(QString name);
    ~ImageScalingTool();

    //Function to setup the widget
    void setupWidget();

public slots:
    //Slot for apply button clicked
    void applyButtonClicked();

protected:
    //Widget layout and elements
    QGridLayout *layout;
    QLabel *scaleTypeLabel;
    QComboBox *scaleTypeComboBox;
    QLabel *scalePercentageLabel;
    QSpinBox *scalePercentageSpinBox;
    QPushButton *applyButton;

    enum ScaleType{ SCALE_DOWN=0, SCALE_UP};

    ImageScaling scaleImage;
};

#endif // IMAGESCALINGTOOL_H
