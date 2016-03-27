#ifndef CENTRALGRIDLAYOUTWIDGET_H
#define CENTRALGRIDLAYOUTWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include "imagedisplaywidget.h"
#include "imageprocessingtoolboxwidget.h"

class CentralGridLayoutWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralGridLayoutWidget(QWidget *parent = 0);
    ~CentralGridLayoutWidget();
    void setupWidget();

signals:

public slots:

protected:
    QGridLayout *layout;
    ImageDisplayWidget *imageDisplayWidget;
    ImageProcessingToolBoxWidget *imageProcessingToolBoxWidget;

};

#endif // CENTRALGRIDLAYOUTWIDGET_H
