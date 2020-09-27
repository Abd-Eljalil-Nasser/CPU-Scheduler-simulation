#include "mainwindow.h"
#include <QApplication>
#include<list>
#include<process.h>
#include<node.h>
#include<process.h>
using namespace std;
int number ;
QString algorithm;
process * proc;
list<Node> output;
int TimeSclice;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
