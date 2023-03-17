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


#include "filewatcher.h"
#include "file.h"

using namespace std;
int main(int argc, char *argv[])
{
    //while(true){
    QCoreApplication app(argc, argv);

    FileWatcher watcher("D:/Qt/test.txt");

    FileConsolePrinter printer;

    QObject::connect(&watcher, &FileWatcher::fileExists, &printer, &FileConsolePrinter::onFileExists);
    QObject::connect(&watcher, &FileWatcher::fileChanged, &printer, &FileConsolePrinter::onFileChanged);
    QObject::connect(&watcher, &FileWatcher::fileRemoved, &printer, &FileConsolePrinter::onFileRemoved);

    QTimer::singleShot(0, &app, SLOT(quit()));
    return app.exec();//}
}
