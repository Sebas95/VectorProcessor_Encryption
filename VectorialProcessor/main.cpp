#include <QApplication>
#include <QImage>
#include <stdio.h>
#include <string>
#include <datamem.h>
#include <pthread.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;

    Processor* processor =  new Processor();

    w.setProcessor(processor);
    w.show();

    return a.exec();

}







