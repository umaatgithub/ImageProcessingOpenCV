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
    //Constructor and Destructor
    explicit ImageChangeHistory(QObject *parent = 0);
    ~ImageChangeHistory(){}

    void loadImage(const QString &path);        //Push new image into the list
    void saveAsImage(const QString &path);      //Save current image
    void undoHistory();                         //Undo last change
    void redoHistory();                         //Redo last change undone
    bool previousChangesSaved();                //Check if previous change is saved
    bool imageExist();                          //Check if image exists

    //Getting and setting path of the image
    QString getImagePath() const;
    void setImagePath(const QString &value);

signals:
    void imageHistoryUpdated(QImage* image, bool newImage=false);
    void imagePathUpdated(QString &path);

public slots:
    void updateImageHistory(QImage* image);

protected:
    std::list<QImage*> imageHistoryList;
    std::list<QImage*>::iterator itImageHistoryList;
    QString imagePath;
    enum ImageStatus{EMPTY=0, NOT_MODIFIED, MODIFIED, SAVED};
    ImageStatus imageStatus;
};

#endif // IMAGECHANGEHISTORY_H
