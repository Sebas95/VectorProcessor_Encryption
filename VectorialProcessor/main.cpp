#include "mainwindow.h"
#include "instructionmem.h"
#include <QApplication>
#include <stdio.h>

int main(int argc, char *argv[])
{

    InstructionMem* memory = new InstructionMem();


    memory->getVector(2);
    printf("vector %c \n", memory->getVector(0) );


    QApplication a(argc, argv);
    MainWindow w;
    w.show();




    return a.exec();
}
