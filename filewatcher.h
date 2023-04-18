#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#pragma once

#include <QObject>
#include <QFileInfo>
#include <QList>
#include <QVector>
#include <QMap>
#include <QPair>


class FileWatcher : public QObject
{
    Q_OBJECT

public:
    static FileWatcher* Instance(); // добавлен статический метод Instance()
    //FileWatcher();
    //~FileWatcher();
    void addFile(QString filePath);//добавление файла в лсит
signals:
    void fileExists(qint64 size, QString file_Path);//сигнал существования
    void fileChanged(qint64 size, QString file_Path);//сигнал изменения
    void fileRemoved(QString file_Path);//сигнал удаления

private:
    FileWatcher();
    QList<QFileInfo> m_fileList;//список элементов типа QFileInfo
    QMap<QString, QPair<qint64, bool> >  m_fileInfo;//контейнер ключ (QString) значения(qint64, bool)

public slots:
    void checkFile();//проверка состояния файла + отправка сигналов
    void checkFirstPos();
};


#endif // FILEWATCHER_H
