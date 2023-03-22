//#include <iostream>

//using namespace std;

//int main()
//{
//    cout << "Hello World! its test222" << endl;
//    return 0;
//}

//void main(){
//FileMonitor monitor;
//monitor.AddFile('a.txt');
//monitor.AddFile('b.txt');
//monitor.AddFile('c.txt');
//monitor.AddFile('d.txt');


//while(doCheckObj){

//monitor.CheckStatus();

//}
//}


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
       QThread::msleep(5000);
       watcher.checkFile();
    }

    //QTimer::singleShot(0, &app, SLOT(quit()));
    return app.exec();//}
}
