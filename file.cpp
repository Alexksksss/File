//class StateFile{

//public:
//StateFile(Qstring );
//StateFile(){

////???
//}

//private:
//Qstring FileName;
//qint64 size;
//bool isExist;


//};


//class FileMonitor{

//public:
//FileMonitor();
//bool AddFile(Qstring FN);//статус добавления файла в наблюдатель. 0 если объект уже под наблюдением
//bool DelFile(Qstring FN);//0 если не можем удалить (если его нет изначально)


////CheckStatus();test

//private:
////FileState *objects;
////FileState **objects;

////Контейнеры
////QVector <FileState> objects;
////QSet <FileState> objects;
//};

#include "file.h"
#include <QFile>
#include <QFileInfo>

//bool FileMonitoring::is_exist(const QString& filePath)
//{
//    QFileInfo fileInfo(filePath);
//    if (!fileInfo.exists()){
//    cout<< "FileMonitoring: File does not exist";//проверка на существование файла
//    return false;
//    }
//    return true;
//}



void CheckFile::update_check()
{
    QFile file(m_file_name);
    if (file.exists()) { // файл существует
        if (file.size() != m_file_size) { // размер файла изменился
            m_file_size = file.size();
            emit file_Changed(m_fileName, m_file_size);
        }
    } else { // файл был удален
        if (m_file_size > 0) { // если файл существовал ранее
            m_file_size = 0;
            emit file_Deleted(m_fileName);
        } else { // файл был только что создан
            m_file_size = file.size();
            emit file_Created(m_fileName, m_file_size);
        }
    }
}



