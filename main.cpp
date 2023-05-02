#include <QCoreApplication>
#include <QTimer>
#include <iostream>
#include <QThread>

#include "filewatcher.h"
#include "file.h"

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);//создание объекта приложения Qt

    FileWatcher* watcher = FileWatcher::Instance();//создание наблюдателя с использованием Singleton
    FileConsolePrinter* printer = new FileConsolePrinter();//создание принтера

    watcher->addFile("D:/Qt/test.txt");//добавление файлов в наблюдатель
    watcher->addFile("D:/Qt/test2.txt");
    watcher->addFile("D:/Qt/test3.txt");

    watcher->addFile("D:/Qt/test.txt");//добавление файлов в наблюдатель
    watcher->addFile("D:/Qt/test2.txt");
    watcher->addFile("D:/Qt/test3.txt");
    //связь сигналов и слотов
    QObject::connect(watcher, &FileWatcher::fileExists, printer, &FileConsolePrinter::onFileExists);
    QObject::connect(watcher, &FileWatcher::fileChanged, printer, &FileConsolePrinter::onFileChanged);
    QObject::connect(watcher, &FileWatcher::fileRemoved, printer, &FileConsolePrinter::onFileRemoved);


    cout<<"Starting with:"<<endl;
    watcher->showCurrentState();
    cout<<"Changes:"<<endl;
    while(true){//бесконечный цикл с проверкой состояния файла каждую секунду
       QThread::msleep(1000);
       watcher->checkFile();
    }
    return app.exec();
}
