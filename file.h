#ifndef FILE_H
#define FILE_H

#pragma once

#include <QObject>

class FileConsolePrinter : public QObject
{
    Q_OBJECT

public:
    FileConsolePrinter(QObject* parent = nullptr);

public slots:
    void onFileExists(qint64 size, QString filePath);
    void onFileChanged(qint64 size, QString filePath);
    void onFileRemoved(QString filePath);

};

#endif // FILE_H
