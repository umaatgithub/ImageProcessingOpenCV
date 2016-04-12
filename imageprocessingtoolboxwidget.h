#ifndef IMAGEPROCESSINGTOOLBOXWIDGET_H
#define IMAGEPROCESSINGTOOLBOXWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QToolBox>
#include "filterwidget.h"

class ImageProcessingToolBoxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageProcessingToolBoxWidget(QWidget *parent = 0);
    ~ImageProcessingToolBoxWidget();
    void setupImageProcessingToolBox();

    FilterWidget *getFilterToolSet() const;

signals:

public slots:

protected:
    QGridLayout *layout;
    QToolBox *toolBox;
    FilterWidget *filterToolSet;
    QWidget *secondToolSet;
    QWidget *thirdToolSet;
    QWidget *fourthToolSet;

};

#endif // IMAGEPROCESSINGTOOLBOXWIDGET_H
