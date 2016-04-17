#include "imagechangehistory.h"

ImageChangeHistory::ImageChangeHistory(QObject *parent) : QObject(parent),
    imageStatus(EMPTY)
{

}

QString ImageChangeHistory::getImagePath() const
{
    return imagePath;
}

void ImageChangeHistory::setImagePath(const QString &value)
{
    imagePath = value;
}

void ImageChangeHistory::loadImage(const QString &path)
{
    QDir dir;
    if(dir.exists(path)){
        QImage image;
        image.load(path);
        if(!imageHistoryList.empty()){
            imageHistoryList.clear();
        }
        imageHistoryList.push_back(image);
        setImagePath(path);
        itImageHistoryList = imageHistoryList.begin();
        imageStatus = NOT_MODIFIED;
        emit imageHistoryUpdated(image, true);
    }

}

void ImageChangeHistory::saveAsImage(const QString &path)
{
    if(path!=""){
        if(!imageHistoryList.empty()){
            (*itImageHistoryList).save(path);
            setImagePath(path);
            imageStatus = SAVED;
        }
    }
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

bool ImageChangeHistory::previousChangesSaved()
{
    if(imageStatus == MODIFIED){
        return false;
    }
    return true;
}

bool ImageChangeHistory::imageExist()
{
    if(imageStatus == EMPTY){
        return false;
    }
    return true;
}

void ImageChangeHistory::updateImageHistory(QImage image)
{
    if(!imageHistoryList.empty()){
        while(itImageHistoryList!=(--imageHistoryList.end())){
            imageHistoryList.pop_back();
        }
        imageHistoryList.push_back(image);
        ++itImageHistoryList;
        imageStatus = MODIFIED;
        emit imageHistoryUpdated(image);
    }
//    imageHistoryList.push_back(image);
//    ++itImageHistoryList;
//    imageHistoryList.
//    imageQueue.push(image);
//    emit imageHistoryUpdated(image);

}

