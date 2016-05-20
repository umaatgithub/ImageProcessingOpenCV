#ifndef IMAGESMOOTHENINGFILTERTOOL_H
#define IMAGESMOOTHENINGFILTERTOOL_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include "imageprocessingtoolwidget.h"
#include "imagesmootheningfilter.h"

class ImageSmootheningFilterTool : public ImageProcessingToolWidget
{
    Q_OBJECT
public:
    //Constructor and Destructor
    explicit ImageSmootheningFilterTool(QString name);
    ~ImageSmootheningFilterTool();

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
    QLabel *filterTypeLabel;
    QComboBox *filterTypeComboBox;
    QLabel *filterRadiusLabel;
    QSpinBox *filterRadiusSpinBox;
    QLabel *roiLabel;
    QCheckBox *roiCheckBox;
    QPushButton *applyButton;

    enum FilterType{ BILATERAL=0, BOX, GAUSSIAN, MEDIAN};

    ImageSmootheningFilter filterImage;
};

#endif // IMAGESMOOTHENINGFILTERTOOL_H
