#ifndef FILE_H
#define FILE_H

#pragma once

#include <QObject>

class FileConsolePrinter : public QObject
{
    Q_OBJECT

public:
    FileConsolePrinter();//конструктор

public slots:
    void onFileExists(qint64 size, QString filePath);//вывод существания файла
    void onFileChanged(qint64 size, QString filePath);//вывод изменения размера файла
    void onFileRemoved(QString filePath);//вывод удаления файла

};

#endif // FILE_H
