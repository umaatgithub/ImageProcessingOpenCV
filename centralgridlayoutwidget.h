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

    ImageDisplayWidget *getImageDisplayWidget() const;

    ImageProcessingToolBoxWidget *getImageProcessingToolBoxWidget() const;

    QWidget *getInfoWidget() const;

signals:

public slots:

protected:
    QGridLayout *layout;
    ImageDisplayWidget *imageDisplayWidget;
    ImageProcessingToolBoxWidget *imageProcessingToolBoxWidget;
    QWidget *infoWidget;

};

#endif // CENTRALGRIDLAYOUTWIDGET_H
