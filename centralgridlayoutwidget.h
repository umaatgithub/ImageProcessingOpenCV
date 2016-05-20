#ifndef CENTRALGRIDLAYOUTWIDGET_H
#define CENTRALGRIDLAYOUTWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include "imagedisplaywidget.h"
#include "imageprocessingtoolboxwidget.h"
#include "infowidget.h"

class CentralGridLayoutWidget : public QWidget
{
    Q_OBJECT
public:
    //Constructor and Destructor
    explicit CentralGridLayoutWidget(QWidget *parent = 0);
    ~CentralGridLayoutWidget();

    //Function to setup the widget
    void setupWidget();

    //Getter functions of widgets forming the central widget
    ImageDisplayWidget *getImageDisplayWidget() const                       { return imageDisplayWidget; }
    ImageProcessingToolBoxWidget *getImageProcessingToolBoxWidget() const   { return imageProcessingToolBoxWidget;}
    QWidget *getInfoWidget() const                                          { return infoWidget; }

protected:
    QGridLayout *layout;                                        //Widget layout
    ImageDisplayWidget *imageDisplayWidget;                     //Pointer to display widget
    ImageProcessingToolBoxWidget *imageProcessingToolBoxWidget; //Pointer to toolbox widget
    InfoWidget *infoWidget;                                     //Pointer to info widget

};

#endif // CENTRALGRIDLAYOUTWIDGET_H
