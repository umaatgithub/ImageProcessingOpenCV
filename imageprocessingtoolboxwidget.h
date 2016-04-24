#ifndef IMAGEPROCESSINGTOOLBOXWIDGET_H
#define IMAGEPROCESSINGTOOLBOXWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QToolBox>
#include "filterwidget.h"
#include "morphologywidget.h"
#include "transformationwidget.h"
#include "rotationwidget.h"
#include "scalewidget.h"

class ImageProcessingToolBoxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageProcessingToolBoxWidget(QWidget *parent = 0);
    ~ImageProcessingToolBoxWidget();
    void setupImageProcessingToolBox();

    FilterWidget *getFilterToolSet() const;
    MorphologyWidget *getMorphologyToolSet() const;
    TransformationWidget *getTransformationToolSet() const;
    RotationWidget *getRotationToolSet() const;
    ScaleWidget *getScaleToolSet() const;

signals:

public slots:

protected:
    QGridLayout *layout;
    QToolBox *toolBox;
    FilterWidget *filterToolSet;
    MorphologyWidget *morphologyToolSet;
    TransformationWidget *transformationToolSet;
    RotationWidget *rotationToolSet;
    ScaleWidget *scaleToolSet;

};

#endif // IMAGEPROCESSINGTOOLBOXWIDGET_H
