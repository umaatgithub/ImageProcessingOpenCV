#include "imagechangehistory.h"

ImageChangeHistory::ImageChangeHistory(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(pathChanged(QString)), this, SLOT(setInitialImage(QString)));
}

QString ImageChangeHistory::getImagePath() const
{
    return imagePath;
}

void ImageChangeHistory::setImagePath(const QString &value)
{
    imagePath = value;
    emit pathChanged(value);
}

void ImageChangeHistory::undoHistory()
{
    if(!imageHistoryList.empty()){
        if(itImageHistoryList!=imageHistoryList.begin()){
            --itImageHistoryList;
            emit imageHistoryUpdated(*itImageHistoryList);
        }
    }
}

void ImageChangeHistory::redoHistory()
{
    if(!imageHistoryList.empty()){
        if(itImageHistoryList!=(--imageHistoryList.end())){
            ++itImageHistoryList;
            emit imageHistoryUpdated(*itImageHistoryList);
        }
    }
}

void ImageChangeHistory::setInitialImage(QString path)
{
    QImage image;
    image.load(path);
    if(!imageHistoryList.empty()){
        imageHistoryList.clear();
    }
    imageHistoryList.push_back(image);
    itImageHistoryList = imageHistoryList.begin();
//    while(!imageQueue.empty()){
//        imageQueue.pop();
//    }
//    imageQueue.push(image);
    emit imageHistoryUpdated(image);

}

void ImageChangeHistory::updateImageHistory(QImage image)
{
    if(!imageHistoryList.empty()){
        while(itImageHistoryList!=(--imageHistoryList.end())){
            imageHistoryList.pop_back();
        }
        imageHistoryList.push_back(image);
        ++itImageHistoryList;
        emit imageHistoryUpdated(image);
    }
//    imageHistoryList.push_back(image);
//    ++itImageHistoryList;
//    imageHistoryList.
//    imageQueue.push(image);
//    emit imageHistoryUpdated(image);

}

