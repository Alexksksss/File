#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#pragma once

#include <QObject>
//#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QVector>
#include <QMap>

class FileWatcher : public QObject
{
    Q_OBJECT

public:
    FileWatcher(QObject* parent = nullptr);//const QString& filePath,
    //~FileWatcher();
    void addFile(QString filePath);//
signals:
    void fileExists(qint64 size, QString file_Path);
    void fileChanged(qint64 size, QString file_Path);
    void fileRemoved(QString file_Path);

private:
    /*
    QString m_filePath;
    QFile m_file;
    qint64 m_fileSize;
    bool is_Exists;*/
    QList<QFileInfo> m_fileList;
    QMap <QString, qint64> m_fileSizes;
    QMap <QString, bool> m_isExist;

public slots:
    void checkFile();
   // void checkFirstPos();
};


#endif // FILEWATCHER_H
