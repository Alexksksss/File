#include <QObject>
#include <QFileInfo>
#include <QTimer>
#include <iostream>
#include "filewatcher.h"

FileWatcher::FileWatcher(const QString& filePath, QObject* parent) : QObject(parent), m_filePath(filePath), m_file(filePath), m_fileSize(-1)
{
    //std::cout << "constr  " << std::endl;
    checkFile();
}

FileWatcher::~FileWatcher()
{
    if (m_file.isOpen()) {
        m_file.close();
    }
}

void FileWatcher::checkFile()
{
    //std::cout << "in check  " << std::endl;
    QFileInfo fileInfo(m_filePath);

    if (!fileInfo.exists()) {
        if (m_file.isOpen()) {
            m_file.close();
        }
        //std::cout << "in check remove  " << std::endl;
        emit fileRemoved();
        return;
    }

    qint64 fileSize = fileInfo.size();

    if (m_fileSize != fileSize) {
            m_fileSize = fileSize;
            //std::cout << "in check change " << std::endl;
            emit fileChanged(fileSize);
    }
    else {
        m_fileSize = fileSize;
        //std::cout << "in check exists" << std::endl;
       //emit fileExists(fileSize);
    }
}
