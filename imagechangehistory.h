#ifndef IMAGECHANGEHISTORY_H
#define IMAGECHANGEHISTORY_H

#include <QObject>
#include <QImage>
#include <QDir>
#include <list>
#include <QDebug>


class ImageChangeHistory : public QObject
{
    Q_OBJECT
public:
    explicit ImageChangeHistory(QObject *parent = 0);

    QString getImagePath() const;
    void setImagePath(const QString &value);
    void loadImage(const QString &path);
    void saveAsImage(const QString &path);
    void undoHistory();
    void redoHistory();
    bool previousChangesSaved();
    bool imageExist();

signals:
    void imageHistoryUpdated(QImage image);

public slots:
    void updateImageHistory(QImage image);

protected:
    std::list<QImage> imageHistoryList;
    std::list<QImage>::iterator itImageHistoryList;
    QString imagePath;
    enum ImageStatus{EMPTY=0, NOT_MODIFIED, MODIFIED, SAVED};
    ImageStatus imageStatus;
};

#endif // IMAGECHANGEHISTORY_H
