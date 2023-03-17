#ifndef FILE_H
#define FILE_H

#pragma once

#include <QObject>
#include <QDebug>

class FileConsolePrinter : public QObject
{
    Q_OBJECT

public:
    explicit FileConsolePrinter(QObject* parent = nullptr);

public slots:
    void onFileExists(qint64 size);
    void onFileChanged(qint64 size);
    void onFileRemoved();
};


#endif // FILE_H
