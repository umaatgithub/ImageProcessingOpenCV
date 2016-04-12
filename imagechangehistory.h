#ifndef IMAGECHANGEHISTORY_H
#define IMAGECHANGEHISTORY_H

#include <QObject>
#include <QImage>
#include <queue>
#include <list>
#include <map>

class ImageChangeHistory : public QObject
{
    Q_OBJECT
public:
    explicit ImageChangeHistory(QObject *parent = 0);

    QString getImagePath() const;
    void setImagePath(const QString &value);
    void undoHistory();
    void redoHistory();

signals:
    void pathChanged(QString path);
    void imageHistoryUpdated(QImage image);

public slots:
    void setInitialImage(QString path);
    void updateImageHistory(QImage image);

protected:
    std::queue<QImage> imageQueue;
    std::list<QImage> imageHistoryList;
    std::list<QImage>::iterator itImageHistoryList;
    QString imagePath;
};

#endif // IMAGECHANGEHISTORY_H
