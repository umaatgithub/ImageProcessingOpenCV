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
    DisplayLabel();

    void enableSelection();
    void disableSelection();
    void updatePercentageZoom(float value);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *event);
     void resizeEvent(QResizeEvent *event);

    int getStartX() const;
    void setStartX(int value);

    int getStartY() const;
    void setStartY(int value);

    int getEndX() const;
    void setEndX(int value);

    int getEndY() const;
    void setEndY(int value);

    bool getCropFlag() const;
    void setCropFlag(bool value);

    bool getRoiFlag() const;
    void setRoiFlag(bool value);

    bool getSelectionFlag() const;
    void setSelectionFlag(bool value);

    float getPercentageZoom() const;
    void setPercentageZoom(float value);

    QRect getSelectionRect() const;
    void setSelectionRect(const QRect &value);

signals:
    void selectionUpdated(QRect&);

public slots:


protected:
    bool mousePressed, mouseReleased;
    bool selectionFlag, selectionResize, cropFlag, roiFlag;
    int startX, startY;
    int endX, endY;
    float percentageZoom;
    QRect selectionRect;
};

#endif // DISPLAYLABEL_H
