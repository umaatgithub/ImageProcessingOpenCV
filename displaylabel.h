#ifndef DISPLAYLABEL_H
#define DISPLAYLABEL_H
#include <QLabel>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QPainter>
#include <iostream>

class DisplayLabel : public QLabel
{
    Q_OBJECT
public:
    //COnstructor and Destructor
    DisplayLabel();
    ~DisplayLabel() { delete selectionRect; }

    //Functions called form mainwindow when selection checked and unchecked
    void enableSelection();
    void disableSelection();

    //Function called from mainwindow to update percentage zoom
    void updatePercentageZoom(float value);


    //Mouse events to get selection rectangle
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    //Paint events to draw selection rectangle
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

    //Getter member functions
    int getStartX() const;
    int getStartY() const;
    int getEndX() const;
    int getEndY() const;
    bool getCropFlag() const;
    bool getRoiFlag() const;
    bool getSelectionFlag() const;
    float getPercentageZoom() const;
    QRect *getSelectionRect() const;

    //Setter member functions
    void setStartX(int value);
    void setStartY(int value);
    void setEndX(int value);
    void setEndY(int value);
    void setCropFlag(bool value);
    void setRoiFlag(bool value);
    void setSelectionFlag(bool value);
    void setPercentageZoom(float value);
    void setSelectionRect(QRect* value);

signals:
    //Signal emitted after selection is completed
    void selectionUpdated(QRect*);

protected:
    //Boolean flags to handle selection, cropping and region of interest
    bool mousePressed, mouseReleased;
    bool selectionFlag, selectionResize, cropFlag, roiFlag;

    //Selection coordinates
    int startX, startY;
    int endX, endY;

    //Percentage zoom of the display image
    float percentageZoom;

    //Selection rectangle calculated from coordinates
    QRect* selectionRect;
};

#endif // DISPLAYLABEL_H
