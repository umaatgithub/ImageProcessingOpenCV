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
    //Constructor and Destructor
    explicit ImageProcessingToolBoxWidget(QWidget *parent = 0);
    ~ImageProcessingToolBoxWidget();

    //Function to setup the toolbox
    void setupImageProcessingToolBox();

    ImageSmootheningFilterTool *getFilterToolSet() const;
    ImageMorphologyTool *getMorphologyToolSet() const;
    ImageTransformationTool *getTransformationToolSet() const;
    ImageRotationTool *getRotationToolSet() const;
    ImageScalingTool *getScaleToolSet() const;
    ImageEdgeFilterTool *getEdgeDetectionToolSet() const;

protected:
    QGridLayout *layout;
    QToolBox *toolBox;
    ImageSmootheningFilterTool *filterToolSet;
    ImageMorphologyTool *morphologyToolSet;
    ImageTransformationTool *transformationToolSet;
    ImageRotationTool *rotationToolSet;
    ImageScalingTool *scaleToolSet;
    ImageEdgeFilterTool *edgeDetectionToolSet;

};

#endif // IMAGEPROCESSINGTOOLBOXWIDGET_H
