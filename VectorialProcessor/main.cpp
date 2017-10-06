#include "mainwindow.h"
#include "instructionmem.h"
#include "mux32.h"
#include "pipefetchdeco.h"
#include "controlunit.h"
#include <QApplication>
#include <QImage>
#include <stdio.h>
#include <string>
#include <datamem.h>


char* ReadFile(const char *filename)
{
   char *buffer = NULL;
   int string_size, read_size;
   FILE *handler = fopen(filename, "r");
   if (handler)
   {
       // Seek the last byte of the file
       fseek(handler, 0, SEEK_END);
       // Offset from the first to the last byte, or in other words, filesize
       string_size = ftell(handler);
       // go back to the start of the file
       rewind(handler);

       // Allocate a string that can hold it all
       buffer = (char*) malloc(sizeof(char) * (string_size + 1) );

       // Read it all in one operation
       read_size = fread(buffer, sizeof(char), string_size, handler);

       // fread doesn't set it so put a \0 in the last position
       // and buffer is now officially a string
       buffer[string_size] = '\0';
       printf("The size of the image is %d \n",string_size);
       if (string_size != read_size)
       {
           //printf("%s \n","Error");
           // Something went wrong, throw away the memory and set
           // the buffer to NULL
           free(buffer);
           buffer = NULL;
       }

       // Always remember to close the file.
       fclose(handler);
    }

    return buffer;
}

//int main(int argc, char *argv[])
int main()
{

    InstructionMem* memory = new InstructionMem();
    DataMem* data_mem = new DataMem();
    unsigned char* sc =new unsigned char[4]();
    data_mem->getScalar(65532,sc);
    printf("%c\n", sc[3]);

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


