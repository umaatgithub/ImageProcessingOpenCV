#ifndef IMAGEPROCESSINGTOOLWIDGET_H
#define IMAGEPROCESSINGTOOLWIDGET_H

#include <QWidget>

class ImageProcessingToolWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageProcessingToolWidget(QString name, QWidget *parent = 0);

    QImage *getInputImage() const;
    void setInputImage(QImage *value);

    QImage *getOutputImage() const;
    void setOutputImage(QImage *value);

    virtual void setupWidget()=0;

    QString getToolName() const;
    void setToolName(const QString &value);

    QRect *getRoiRect() const;
    void setRoiRect(QRect *value);

    bool isRoiRectValid();

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
