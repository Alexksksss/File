#include <QObject>
#include <QFileInfo>
#include <QTimer>
#include <iostream>

#include "filewatcher.h"

FileWatcher::FileWatcher( QObject* parent) : QObject(parent)//, m_filePath(filePath), m_file(filePath), m_fileSize(-1), is_Exists(false)
{
    //std::cout << "constr  " << std::endl;
    //checkFile();
}

/*FileWatcher::~FileWatcher()
{
    if (m_file.isOpen()) {
        m_file.close();
    }
}*/

//
void FileWatcher::addFile(QString filePath)
{
    QFileInfo fileInfo(filePath);

    m_fileList.append(fileInfo);
    m_fileSizes[fileInfo.filePath()] = fileInfo.size();
    m_isExist[fileInfo.filePath()] = fileInfo.exists();

}

void FileWatcher::checkFile(){
    for (int i = 0; i < m_fileList.size(); i++){
        QFileInfo fileInfo(m_fileList[i].filePath());
        QString Name(fileInfo.fileName());//Имя файла для красивовго вывода
        qint64 fileSize = fileInfo.size();//Размер файла
        bool existing = fileInfo.exists();//Сущестовование файла

        if (existing && !m_isExist[Name]){//Если до этого не существовал, а сейчас существует
            m_fileSizes[Name] = fileSize;
            m_isExist[Name] = !m_isExist[Name];
            emit fileExists(fileSize, Name);//отправка сигнала на печать, что файл теперь существует
        }

        else if(existing && fileSize != m_fileSizes[Name]){//Существует, размер поменялся
            m_fileSizes[Name] = fileSize;
            emit fileChanged(fileSize, Name);//отправка сигнала на печать, что файл был изменен
        }

        else if(!existing && m_isExist[Name]){//Не существует, а до этого существовал
            m_isExist[Name] = ! m_isExist[Name];
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
