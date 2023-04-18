#include <QObject>
#include <QFileInfo>
#include <QTimer>
#include <QPair>
#include <iostream>

#include "filewatcher.h"

FileWatcher::FileWatcher()
{

}
FileWatcher* FileWatcher::Instance()
{
    static FileWatcher* instance = new FileWatcher(); // создание объекта FileWatcher, если он еще не создан
    return instance;
}


void FileWatcher::addFile(QString filePath)
{
    QFileInfo fileInfo(filePath);

    QString key = fileInfo.filePath();
    if (m_fileInfo.contains(key)) {
        // если ключ уже существует, обновляем значения
        QPair<qint64, bool>& fileInfoPair = m_fileInfo[key];
        fileInfoPair.first = fileInfo.size();
        fileInfoPair.second = fileInfo.exists();
    } else {
        // если ключ не существует, добавляем новое значение
        m_fileList.append(fileInfo);
        m_fileInfo.insert(key, QPair<qint64, bool>(fileInfo.size(), fileInfo.exists()));
    }
}

void FileWatcher::checkFile(){
    for (int i = 0; i < m_fileList.size(); i++){

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


void FileWatcher::checkFirstPos(){
    for (int i = 0; i < m_fileList.size(); i++){

        QFileInfo fileInfo(m_fileList[i].filePath());
        QPair<qint64, bool> fileInfoPair = m_fileInfo[m_fileList[i].filePath()];
        QString Name(fileInfo.fileName());//Имя файла для красивого вывода
        qint64 fileSize = fileInfo.size();//Размер файла
        bool existing = fileInfo.exists();//Сущестовование файла

        if (existing){//Изначально существует
            fileInfoPair.second = true;
            m_fileInfo[fileInfo.filePath()].second = true;
            m_fileInfo[fileInfo.filePath()].first = fileSize;
            emit fileExists(fileSize, Name);//отправка сигнала на печать, что файл существует
        }
        else if(!existing){//Не существует
            m_fileInfo[fileInfo.filePath()].second = false;
            emit fileRemoved(Name);//отправка сигнала на печать, что файл не существует
        }
    }
}

