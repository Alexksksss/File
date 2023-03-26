//#include <QFile>
#include <QFileInfo>
#include <QObject>
//#include <QDebug>
#include <iostream>

#include "file.h"

using namespace std;


FileConsolePrinter::FileConsolePrinter(QObject* parent): QObject(parent)
{
    //cout<<"constr FCP";
//    QString Path = "D:/QT/test.txt";

//    QString Name = Path.right(Path.lastIndexOf('/'));
//    QString Name2 = Name.sliced(Name.indexOf('/'));
//    cout<<Path.lastIndexOf('/')<<endl;//5
//    cout<<Name.toStdString()<<endl;
//    cout<<Name2.toStdString();


}


void FileConsolePrinter::onFileExists(qint64 size, QString filePath)
{
    cout << "File " << filePath.toStdString() <<" exists, size =  " << size << endl;
}

void FileConsolePrinter::onFileChanged(qint64 size, QString filePath)
{
    cout << "File " << filePath.toStdString() << " changed, size = " << size << endl;
}

void FileConsolePrinter::onFileRemoved(QString filePath)
{
    cout << "File " << filePath.toStdString() << " removed or deleted" << endl;
}


