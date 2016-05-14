#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include "imageprocessingtoolwidget.h"
#include "imagesmootheningfilter.h"

class FilterWidget : public ImageProcessingToolWidget
{
    Q_OBJECT
public:
    explicit FilterWidget(QString name);
    void setupWidget();

public slots:
    void applyButtonClicked();
    void updateCheckBox();

protected:
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

#endif // FILTERWIDGET_H
