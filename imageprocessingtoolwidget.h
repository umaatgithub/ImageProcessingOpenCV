#ifndef IMAGEPROCESSINGTOOLWIDGET_H
#define IMAGEPROCESSINGTOOLWIDGET_H

#include <QWidget>

class ImageProcessingToolWidget : public QWidget
{
    Q_OBJECT
public:
    //Constructor and Destructor
    explicit ImageProcessingToolWidget(QString name, QWidget *parent = 0);
    //~ImageProcessingToolWidget();

    QImage *getInputImage() const;
    QImage *getOutputImage() const;
    QString getToolName() const;
    QRect *getRoiRect() const;

    void setInputImage(QImage *value);
    void setOutputImage(QImage *value);
    void setToolName(const QString &value);
    void setRoiRect(QRect *value);

    bool isRoiRectValid();

    //Virtual function to be implemented in derived classes to setup the widget
    virtual void setupWidget()=0;

signals:
    void outputImageChanged(QImage* image);
    void inputImageChanged(QImage* image);
    void statusChanged(QString status, QColor statusColor = Qt::blue);
    void roiRectUpdated();

public slots:
    void updateInputImage(QImage* image);
    void updateROI(QRect* rect);

protected:
    QString toolName;
    QImage *inputImage;
    QImage *outputImage;
    QRect *roiRect;
};

#endif // IMAGEPROCESSINGTOOLWIDGET_H
