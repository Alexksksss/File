#include <QObject>
#include <QFileInfo>
#include <QTimer>
#include <QPair>
#include <iostream>

#include "filewatcher.h"

FileWatcher::FileWatcher()//, m_filePath(filePath), m_file(filePath), m_fileSize(-1), is_Exists(false)
{
    //std::cout << "constr  " << std::endl;
    //checkFile();
}

void FileWatcher::addFile(QString filePath)
{
    QFileInfo fileInfo(filePath);

    m_fileList.append(fileInfo);

    QString key = fileInfo.filePath();
    m_fileInfo.insert(key, QPair<qint64, bool>(fileInfo.size(), fileInfo.exists()));
}

void FileWatcher::checkFile(){
    for (int i = 0; i < m_fileList.size(); ++i){

        QFileInfo fileInfo(m_fileList[i].filePath());
        QPair<qint64, bool> fileInfoPair = m_fileInfo[m_fileList[i].filePath()];
        QString Name(fileInfo.fileName());//Имя файла для красивого вывода
        qint64 fileSize = fileInfo.size();//Размер файла
        bool existing = fileInfo.exists();//Сущестовование файла

        if (existing && !fileInfoPair.second){//Если до этого не существовал, а сейчас существует
            fileInfoPair.second = true;
            m_fileInfo[fileInfo.filePath()].second = true;
            m_fileInfo[fileInfo.filePath()].first = fileSize;
            emit fileExists(fileSize, Name);//отправка сигнала на печать, что файл теперь существует
        }

        else if(existing && fileSize != fileInfoPair.first){//Существует, размер поменялся
            m_fileInfo[fileInfo.filePath()].first = fileSize;
            emit fileChanged(fileSize, Name);//отправка сигнала на печать, что файл был изменен
        }

        else if(!existing && fileInfoPair.second){//Не существует, а до этого существовал
            m_fileInfo[fileInfo.filePath()].second = false;
            emit fileRemoved(Name);//отправка сигнала на печать, что файл удален или перемещен
        }
    }
}

/*
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
*/
