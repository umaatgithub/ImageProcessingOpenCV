#ifndef IMAGEEDGEFILTERTOOL_H
#define IMAGEEDGEFILTERTOOL_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include "imageprocessingtoolwidget.h"
#include "imageedgefilter.h"

class ImageEdgeFilterTool : public ImageProcessingToolWidget
{
    Q_OBJECT
public:
    //Constructor and Destructor
    explicit ImageEdgeFilterTool(QString name);
    ~ImageEdgeFilterTool();

    //Function to setup the widget
    void setupWidget();

public slots:
    //Slot for apply button clicked
    void applyButtonClicked();

protected:
    //Widget layout and elements
    QGridLayout *layout;
    QLabel *edgeDetectorLabel;
    QComboBox *edgeDetectorComboBox;
    QLabel *filterRadiusLabel;
    QSpinBox *filterRadiusSpinBox;
    QPushButton *applyButton;

    enum FilterType{ CANNY=0, SCHARR, SOBEL};

    ImageEdgeFilter edgeDetectionImage;

};

#endif // IMAGEEDGEFILTERTOOL_H
