#include <QFile>
#include <QFileInfo>
#include <QObject>
#include <QDebug>
#include <iostream>
#include "file.h"
using namespace std;


FileConsolePrinter::FileConsolePrinter(QObject* parent): QObject(parent)
{
    //cout<<"constr FCP";

}

void FileConsolePrinter::onFileExists(qint64 size)
{
    cout << "File exists, size =  "<<size << endl;
}

void FileConsolePrinter::onFileChanged(qint64 size)
{
    cout << "File changed, size = "<<size << endl;
}

void FileConsolePrinter::onFileRemoved()
{
    cout << "File removed or deleted" << endl;

}


