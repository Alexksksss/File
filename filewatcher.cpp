#include <QObject>
#include <QFileInfo>
#include <QTimer>
#include <iostream>

#include "filewatcher.h"

FileWatcher::FileWatcher(const QString& filePath, QObject* parent) : QObject(parent), m_filePath(filePath), m_file(filePath), m_fileSize(-1), is_Exists(false)
{
    //std::cout << "constr  " << std::endl;
    //checkFile();
}

FileWatcher::~FileWatcher()
{
    if (m_file.isOpen()) {
        m_file.close();
    }
}

void FileWatcher::checkFile(){
    QFileInfo fileInfo(m_filePath);
    QString Name(fileInfo.fileName());
    qint64 fileSize = fileInfo.size();

    bool existing = fileInfo.exists();

    if (existing && !is_Exists){
        m_fileSize = fileSize;
        is_Exists = !is_Exists;
        emit fileExists(fileSize, Name);
    }

    else if(existing && fileSize != m_fileSize){
        m_fileSize = fileSize;
        emit fileChanged(fileSize, Name);
    }

    else if(!existing && is_Exists){
        is_Exists = ! is_Exists;
        emit fileRemoved(Name);
    }
}

void FileWatcher::checkFirstPos(){
    QFileInfo fileInfo(m_filePath);
    QString Name(fileInfo.fileName());
    qint64 fileSize = fileInfo.size();

    bool existing = fileInfo.exists();
    if (existing){
        m_fileSize = fileSize;
        emit fileExists(fileSize, Name);
    }
    else {
        emit fileRemoved(Name);
    }
}
