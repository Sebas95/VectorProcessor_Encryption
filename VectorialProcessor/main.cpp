#include "mainwindow.h"
#include "instructionmem.h"
#include "mux32.h"
#include "pipefetchdeco.h"
#include "controlunit.h"
#include <QApplication>
#include <stdio.h>

//int main(int argc, char *argv[])
int main()
{

    InstructionMem* memory = new InstructionMem();


    unsigned char* instr = new unsigned char[4]();
    memory->getInstruction(0,instr);
    printf("vector %c \n",instr[0]);

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

    printf("muxed %d\n", '('==40 );


    ControlUnit* control_unit = new ControlUnit();
    bool op[4];
    op[0] = true;
    op[1] = true;
    op[2] = true;
    op[3] = true;
    printf("convert %d\n", control_unit->getIntOpcode(op) );

    //return a.exec();
    return 0;
}
