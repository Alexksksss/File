#ifndef FILE_H
#define FILE_H



//#include <QObject>
//#include <QVector>
//#include <QFileInfo>
//#include <QFileSystemWatcher>

////пока без вектора. Только проверка на существование и изменение размера одного!! файла


#include <QObject>
#include <QString>
#include <QFileInfo>


class CheckFile : public QObject
{
    Q_OBJECT
public:
    CheckFile(const QString& filename);
    CheckFile(const QString& filename): m_fileName(filename), m_size(0), m_is_exist(false){}//конструктор
    void update_check();//общая проверка

public slots:
    void print_Created(const QString& filename, qint64 size);//в другой класс?
    void print_Changed(const QString& filename, qint64 size);
    void print_Deleted(const QString& filename, qint64 size);

signals:
    void file_Created(const QString& filename, qint64 size);//создан
    void file_Changed(const QString& filename, qint64 size);//редактирован
    void file_Deleted(const QString& filename);//Если файл удалили


private:
    QString m_fileName;//имя файла
    qint64 m_size; //размер файла
    bool m_is_exist; //существование файла


};


#endif // FILE_H
