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
    QCoreApplication app(argc, argv);//создание объекта приложения Qt
    //QStringList filePathes = {"D:/Qt/test.txt", "D:/Qt/test2.txt"};

    //QVector<QString> filePathes;
    //filePathes.push_back("D:/Qt/test.txt");
    //filePathes.push_back("D:/Qt/test2.txt");

    FileWatcher* watcher = new FileWatcher();//создание наблюдателя
    FileConsolePrinter* printer = new FileConsolePrinter();//создание принтера

    watcher->addFile("D:/Qt/test.txt");//добавление файлов в наблюдатель
    watcher->addFile("D:/Qt/test2.txt");
    watcher->addFile("D:/Qt/test3.txt");

    //связь сигналов и слотов
    QObject::connect(watcher, &FileWatcher::fileExists, printer, &FileConsolePrinter::onFileExists);
    QObject::connect(watcher, &FileWatcher::fileChanged, printer, &FileConsolePrinter::onFileChanged);
    QObject::connect(watcher, &FileWatcher::fileRemoved, printer, &FileConsolePrinter::onFileRemoved);


    cout<<"Starting with:"<<endl;
    while(true){//бесконечный цикл с проверкой состояния файла каждую секунду
       QThread::msleep(1000);
       watcher->checkFile();
    }

    //QTimer::singleShot(0, &app, SLOT(quit()));
    return app.exec();
}


/* TODO
 * изначальная проверка на несуществоание??
 * доработка цикла
 * singleton
*/
