#ifndef IMAGEROTATIONTOOL_H
#define IMAGEROTATIONTOOL_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include "imageprocessingtoolwidget.h"
#include "imagerotation.h"

class ImageRotationTool : public ImageProcessingToolWidget
{
    Q_OBJECT
public:
    //Constructor and Destructor
    explicit ImageRotationTool(QString name);
    ~ImageRotationTool();

    //Function to setup the widget
    void setupWidget();

public slots:
    //Slot for apply button clicked
    void applyButtonClicked();

protected:
    //Widget layout and elements
    QGridLayout *layout;
    QLabel *directionLabel;
    QComboBox *directionComboBox;
    QLabel *angleLabel;
    QSpinBox *angleSpinBox;
    QPushButton *applyButton;


    enum RotationDirection{ ANTI_CLOCKWISE=0, CLOCKWISE};


    ImageRotation rotationImage;
};

#endif // IMAGEROTATIONTOOL_H
