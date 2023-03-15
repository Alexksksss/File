class StateFile{

public:
StateFile(Qstring );
StateFile(){

//???
}

private:
Qstring FileName;
qint64 size;
bool isExist;


};


class FileMonitor{

public:
FileMonitor();
bool AddFile(Qstring FN);//статус добавления файла в наблюдатель. 0 если объект уже под наблюдением
bool DelFile(Qstring FN);//0 если не можем удалить (если его нет изначально)


//CheckStatus();

private:
//FileState *objects;
//FileState **objects;

//Контейнеры
//QVector <FileState> objects;
//QSet <FileState> objects;
};
