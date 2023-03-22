#ifndef FILEWATCHER_H
#define FILEWATCHER_H


#pragma once

#include <QObject>
#include <QFile>
#include <QFileInfo>

class FileWatcher : public QObject
{
    Q_OBJECT

public:
    explicit FileWatcher(const QString& filePath, QObject* parent = nullptr);// чтобы не было конвертирования в конструкторе
    ~FileWatcher();
signals:
    void fileExists(qint64 size);
    void fileChanged(qint64 size);
    void fileRemoved();

private:
    QString m_filePath;
    QFile m_file;
    qint64 m_fileSize;

public slots:
    void checkFile();
};


#endif // FILEWATCHER_H
