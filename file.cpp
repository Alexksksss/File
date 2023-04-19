#include <QFileInfo>
#include <QObject>
#include <iostream>

#include "file.h"

using namespace std;


FileConsolePrinter::FileConsolePrinter()
{
    //cout<<"constr FCP";
}

void FileConsolePrinter::onFileExists(qint64 size, QString filePath)
{
    cout << "File " << filePath.toStdString() <<" exists or appeared, size =  " << size << endl;
}

void FileConsolePrinter::onFileChanged(qint64 size, QString filePath)
{
    cout << "File " << filePath.toStdString() << " changed, size = " << size << endl;
}

void FileConsolePrinter::onFileRemoved(QString filePath)
{
    cout << "File " << filePath.toStdString() << " removed or deleted" << endl;
}
