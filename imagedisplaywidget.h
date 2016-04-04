#ifndef IMAGEDISPLAYWIDGET_H
#define IMAGEDISPLAYWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QResizeEvent>

class ImageDisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageDisplayWidget(QWidget *parent = 0);
    ~ImageDisplayWidget();
    void setupDisplayArea();
    void resizeEvent(QResizeEvent * event);

    QString getImageFullPath() const;
    void setImageFullPath(const QString &value);

    QImage getDisplayImage() const;
    void setDisplayImage(const QImage &value);

signals:
    void imageChanged(QImage image);
    void pathChanged(QString path);

public slots:
    void updateDisplayArea(QImage image);
    void updateDisplayImage(QString path);

protected:
    QGridLayout *layout;
    QScrollArea *scrollArea;
    QLabel *imageDisplayLabel;
    QImage displayImage;
    QString imageFullPath;
};

#endif // IMAGEDISPLAYWIDGET_H
