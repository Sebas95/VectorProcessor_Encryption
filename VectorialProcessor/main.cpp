#include "mainwindow.h"
#include "instructionmem.h"
#include "mux32.h"
#include "pipefetchdeco.h"
#include <QApplication>
#include <stdio.h>

//int main(int argc, char *argv[])
int main()
{

    InstructionMem* memory = new InstructionMem();



    printf("vector %c \n", memory->getInstruction(0) );

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

    unsigned char* ra = new unsigned char[4]();
    unsigned char* rb = new unsigned char[4]();
    *(int*)ra = 35;
    *(int*)rb = 1;
    int res = *(int*)ra >> *(int*)rb;
    printf("muxed %d\n",res );


    //return a.exec();
    return 0;
}
