#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#pragma once

#include <QObject>
//#include <QFile>
#include <QFileInfo>

class FileWatcher : public QObject
{
    Q_OBJECT

public:
    FileWatcher(const QString& filePath, QObject* parent = nullptr);
    ~FileWatcher();
signals:
    void fileExists(qint64 size, QString file_Path);
    void fileChanged(qint64 size, QString file_Path);
    void fileRemoved(QString file_Path);

private:
    QString m_filePath;
    QFile m_file;
    qint64 m_fileSize;

public slots:
    void checkFile();
};


#endif // FILEWATCHER_H
