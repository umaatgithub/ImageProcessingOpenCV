#ifndef IMAGEPROCESSINGTOOLBOXWIDGET_H
#define IMAGEPROCESSINGTOOLBOXWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QToolBox>
#include "imagesmootheningfiltertool.h"
#include "imagemorphologytool.h"
#include "imagetransformationtool.h"
#include "imagerotationtool.h"
#include "imagescalingtool.h"
#include "imageedgefiltertool.h"

class ImageProcessingToolBoxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageProcessingToolBoxWidget(QWidget *parent = 0);
    ~ImageProcessingToolBoxWidget();
    void setupImageProcessingToolBox();

    FilterWidget *getFilterToolSet() const;
    MorphologyWidget *getMorphologyToolSet() const;
    ImageTransformationTool *getTransformationToolSet() const;
    RotationWidget *getRotationToolSet() const;
    ImageScalingTool *getScaleToolSet() const;
    ImageEdgeFilterTool *getEdgeDetectionToolSet() const;

protected:
    QGridLayout *layout;
    QToolBox *toolBox;
    FilterWidget *filterToolSet;
    MorphologyWidget *morphologyToolSet;
    ImageTransformationTool *transformationToolSet;
    RotationWidget *rotationToolSet;
    ImageScalingTool *scaleToolSet;
    ImageEdgeFilterTool *edgeDetectionToolSet;

};

#endif // IMAGEPROCESSINGTOOLBOXWIDGET_H
