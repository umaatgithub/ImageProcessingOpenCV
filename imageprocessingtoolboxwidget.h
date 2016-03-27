#ifndef IMAGEPROCESSINGTOOLBOXWIDGET_H
#define IMAGEPROCESSINGTOOLBOXWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QToolBox>

class ImageProcessingToolBoxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageProcessingToolBoxWidget(QWidget *parent = 0);
    ~ImageProcessingToolBoxWidget();
    void setupImageProcessingToolBox();

signals:

public slots:

protected:
    QGridLayout *layout;
    QToolBox *toolBox;
    QWidget *firstToolSet;
    QWidget *secondToolSet;
    QWidget *thirdToolSet;
    QWidget *fourthToolSet;

};

#endif // IMAGEPROCESSINGTOOLBOXWIDGET_H
