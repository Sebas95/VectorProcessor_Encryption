#include "mainwindow.h"
#include "instructionmem.h"
#include "mux32.h"
#include "pipefetchdeco.h"
#include <QApplication>
#include <stdio.h>

int main(int argc, char *argv[])
{

    InstructionMem* memory = new InstructionMem();


    memory->getVector(2);
    printf("vector %c \n", memory->getVector(0) );

    //--------------prueba mux 32----------------------------
    unsigned char* c1 = new unsigned char[4]();
    unsigned char* c2 = new unsigned char[4]();
    c1[0]='a';
    c2[0]='b';
    Mux32* mux32 = new Mux32("Mux op_a");
    printf("muxed %d\n",mux32->multiplex(false,c1,c2)[0]);

    //--------------prueba pipe fetch-deco----------------------------
    bool r[32] = {};
    r[30]=true;
    PipeFetchDeco* pipe_f_d= new PipeFetchDeco();
    pipe_f_d->writeReg(r);
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();




    //return a.exec();
    return 0;
}
