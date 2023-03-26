#include <QCoreApplication>
#include <QTimer>
#include <iostream>
#include <QThread>

#include "filewatcher.h"
#include "file.h"

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    FileWatcher watcher("D:/Qt/test.txt");

    FileConsolePrinter printer;

    QObject::connect(&watcher, &FileWatcher::fileExists, &printer, &FileConsolePrinter::onFileExists);
    QObject::connect(&watcher, &FileWatcher::fileChanged, &printer, &FileConsolePrinter::onFileChanged);
    QObject::connect(&watcher, &FileWatcher::fileRemoved, &printer, &FileConsolePrinter::onFileRemoved);

    while(true){
       QThread::msleep(1000);
       watcher.checkFile();
    }

    //QTimer::singleShot(0, &app, SLOT(quit()));
    return app.exec();//}
}


//добавить Вектор?
