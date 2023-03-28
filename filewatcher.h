#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#pragma once

#include <QObject>
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
    void addFile(QString filePath);//добавление файла в лсит
signals:
    void fileExists(qint64 size, QString file_Path);//сигнал существования
    void fileChanged(qint64 size, QString file_Path);//сигнал изменения
    void fileRemoved(QString file_Path);//сигнал удаления

private:
    /*
    QString m_filePath;
    QFile m_file;
    qint64 m_fileSize;
    bool is_Exists;*/
    QList<QFileInfo> m_fileList;//список элементов типа QFileInfo
    QMap <QString, qint64> m_fileSizes;//контейнер ключ (QString) значение(qint64)
    QMap <QString, bool> m_isExist;//контейнер ключ (QString) значение(bool)

public slots:
    void checkFile();//проверка состояния файла + отправка сигналов
   // void checkFirstPos();
};


#endif // FILEWATCHER_H
