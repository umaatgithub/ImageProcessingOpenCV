#include "displaylabel.h"

DisplayLabel::DisplayLabel():mousePressed(false), mouseReleased(true),
    selectionFlag(false), selectionResize(false), cropFlag(false), roiFlag(false)
{

}

void DisplayLabel::enableSelection()
{
    this->setCursor(Qt::CrossCursor);
    setSelectionFlag(true);
}

void DisplayLabel::disableSelection()
{
    this->setCursor(Qt::ArrowCursor);

    selectionRect.setX(0);
    selectionRect.setY(0);
    selectionRect.setWidth(0);
    selectionRect.setHeight(0);
    update();
    setSelectionFlag(false);
}

void DisplayLabel::mousePressEvent(QMouseEvent *event)
{
    if(selectionFlag == true){
        mousePressed = true;
        mouseReleased = false;
        std::cout << "Mouse pressed : ";
        std::cout << event->x();
        setStartX(event->x());
        std::cout << event->y() << std::endl;
        setStartY(event->y());
        selectionRect.setX(getStartX()*100/getPercentageZoom());
        selectionRect.setY(getStartY()*100/getPercentageZoom());
    }
}

void DisplayLabel::mouseMoveEvent(QMouseEvent *event)
{
    if(mousePressed == true){
        std::cout << "Mouse move : ";
        std::cout << event->x();
        setEndX(event->x());
        std::cout << event->y() << std::endl;
        setEndY(event->y());
        update();
    }
}

void DisplayLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if(selectionFlag == true){
        mouseReleased = true;
        std::cout << "Mouse released : ";
        std::cout << event->x();
        setEndX(event->x());
        std::cout << event->y() << std::endl;
        setEndY(event->y());
        selectionRect.setWidth((endX-startX)*100/getPercentageZoom());
        selectionRect.setHeight((endY-startY)*100/getPercentageZoom());
        update();
        emit selectionUpdated(selectionRect);
    }
}

void DisplayLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    if(selectionResize == true){
        QPainter paint(this);
        QPen pen; pen.setStyle(Qt::DashDotLine);
        paint.setPen(pen);
        QBrush brush(QColor(255, 255, 255, 100));
        paint.setBrush(brush);
        //paint.brush().setColor(QColor::fromRgba(125, 125, 125, 125));
        paint.drawRect(selectionRect.x()*percentageZoom/100, selectionRect.y()*percentageZoom/100,
                       selectionRect.width()*percentageZoom/100, selectionRect.height()*percentageZoom/100);
        selectionResize = false;
    }
    else if(selectionFlag == true){
        QPainter paint(this);
        QPen pen; pen.setStyle(Qt::DashDotLine);
        paint.setPen(pen);
        QBrush brush(QColor(255, 255, 255, 100));
        paint.setBrush(brush);
        paint.drawRect(startX, startY, endX-startX, endY-startY);
        if(mouseReleased == true){
            mousePressed = false;
        }
    }
}

void DisplayLabel::resizeEvent(QResizeEvent *event)
{
    QLabel::resizeEvent(event);
    if(selectionFlag == true){
        selectionResize = true;
        update();
    }
}

int DisplayLabel::getStartX() const
{
    return startX;
}

void DisplayLabel::setStartX(int value)
{
    if(value < 5){
        startX = 5;
    }
    else if(value > (width()-5)){
        startX = width()-5;
    }
    else{
        startX = value;
    }
}

int DisplayLabel::getStartY() const
{
    return startY;
}

void DisplayLabel::setStartY(int value)
{
    if(value < 5){
        startY = 5;
    }
    else if(value > (height()-5)){
        startY = height()-5;
    }
    else{
        startY = value;
    }
}

int DisplayLabel::getEndX() const
{
    return endX;
}

void DisplayLabel::setEndX(int value)
{
    if(value < 5){
        endX = 5;
    }
    else if(value > (width()-5)){
        endX = width()-5;
    }
    else{
        endX = value;
    }
}

int DisplayLabel::getEndY() const
{
    return endY;
}

void DisplayLabel::setEndY(int value)
{
    if(value < 5){
        endY = 5;
    }
    else if(value > (height()-5)){
        endY = height()-5;
    }
    else{
        endY = value;
    }
}

bool DisplayLabel::getCropFlag() const
{
    return cropFlag;
}

void DisplayLabel::setCropFlag(bool value)
{
    cropFlag = value;
}

bool DisplayLabel::getRoiFlag() const
{
    return roiFlag;
}

void DisplayLabel::setRoiFlag(bool value)
{
    roiFlag = value;
}

bool DisplayLabel::getSelectionFlag() const
{
    return selectionFlag;
}

void DisplayLabel::setSelectionFlag(bool value)
{
    selectionFlag = value;
}

float DisplayLabel::getPercentageZoom() const
{
    return percentageZoom;
}

void DisplayLabel::setPercentageZoom(float value)
{
    percentageZoom = value;
}

QRect DisplayLabel::getSelectionRect() const
{
    return selectionRect;
}

void DisplayLabel::setSelectionRect(const QRect &value)
{
    selectionRect = value;
}

void DisplayLabel::updatePercentageZoom(float value)
{
    setPercentageZoom(value);
}

