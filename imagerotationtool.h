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

class RotationWidget : public ImageProcessingToolWidget
{
    Q_OBJECT
public:
    explicit RotationWidget(QString name);

    void setupWidget();

public slots:
    void applyButtonClicked();

protected:
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
