#include <QCoreApplication>
#include <QTimer>
#include <iostream>
#include <QThread>
#include <QVector>

#include "filewatcher.h"
#include "file.h"

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    //QStringList filePathes = {"D:/Qt/test.txt", "D:/Qt/test2.txt"};

    //QVector<QString> filePathes;
    //filePathes.push_back("D:/Qt/test.txt");
    //filePathes.push_back("D:/Qt/test2.txt");

    FileWatcher* watcher = new FileWatcher();
    FileConsolePrinter* printer = new FileConsolePrinter();

    watcher->addFile("D:/Qt/test.txt");
    watcher->addFile("D:/Qt/test2.txt");
    watcher->addFile("D:/Qt/test3.txt");

    QObject::connect(watcher, &FileWatcher::fileExists, printer, &FileConsolePrinter::onFileExists);
    QObject::connect(watcher, &FileWatcher::fileChanged, printer, &FileConsolePrinter::onFileChanged);
    QObject::connect(watcher, &FileWatcher::fileRemoved, printer, &FileConsolePrinter::onFileRemoved);


    cout<<"Starting with:"<<endl;
    while(true){
       QThread::msleep(1000);
       watcher->checkFile();
    }

    //QTimer::singleShot(0, &app, SLOT(quit()));
    return app.exec();//}
}


