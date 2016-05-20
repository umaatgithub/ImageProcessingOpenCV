#include "imagechangehistory.h"

/***************************************************************************
 * Input argument(s) : QObject *parent - Passed to base class constructor
 * Return type       : NIL
 * Functionality     : Constructor to initialize the member variables of
 *                     the class
 *
 **************************************************************************/
ImageChangeHistory::ImageChangeHistory(QObject *parent) : QObject(parent),
    imageStatus(EMPTY)
{

}

/***************************************************************************
 * Input argument(s) : const QString &path : Path of the image to be loaded
 * Return type       : void
 * Functionality     : Function to clear the history list and push the
 *                     newly added image into the list
 **************************************************************************/
void ImageChangeHistory::loadImage(const QString &path)
{
    QDir dir;
    if(dir.exists(path)){
        QImage *image = new QImage;
        image->load(path);
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

/***************************************************************************
 * Input argument(s) : const QString &path : Path where the image is to
 *                     saved
 * Return type       : void
 * Functionality     : Function to save the current image to the given path
 **************************************************************************/
void ImageChangeHistory::saveAsImage(const QString &path)
{
    if(path!=""){
        if(!imageHistoryList.empty()){
            (*itImageHistoryList)->save(path);
            setImagePath(path);
            imageStatus = SAVED;
        }
    }
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Function to undo the recent change done to the image
 **************************************************************************/
void ImageChangeHistory::undoHistory()
{
    if(!imageHistoryList.empty()){
        if(itImageHistoryList!=imageHistoryList.begin()){
            --itImageHistoryList;
            emit imageHistoryUpdated(*itImageHistoryList);
        }
    }
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Function to redo the last change undone
 **************************************************************************/
void ImageChangeHistory::redoHistory()
{
    if(!imageHistoryList.empty()){
        if(itImageHistoryList!=(--imageHistoryList.end())){
            ++itImageHistoryList;
            emit imageHistoryUpdated(*itImageHistoryList);
        }
    }
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : bool - Image saved flag
 * Functionality     : Function to check if the last change done was saved
 **************************************************************************/
bool ImageChangeHistory::previousChangesSaved()
{
    if(imageStatus == MODIFIED){
        return false;
    }
    return true;
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : bool - Image exists flad
 * Functionality     : Function to check if the the image change history is
 *                     empty or not
 **************************************************************************/
bool ImageChangeHistory::imageExist()
{
    if(imageStatus == EMPTY){
        return false;
    }
    return true;
}

/***************************************************************************
 * Input argument(s) : void
 * Return type       : void
 * Functionality     : Slot to push new image to the image history list
 **************************************************************************/
void ImageChangeHistory::updateImageHistory(QImage *image)
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

}

//Getter and setter functions definition
QString ImageChangeHistory::getImagePath() const
{
    return imagePath;
}

void ImageChangeHistory::setImagePath(const QString &value)
{
    imagePath = value;
    emit imagePathUpdated(imagePath);
}
