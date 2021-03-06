#ifndef DATAMEM_H
#define DATAMEM_H
#include <stddef.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "parser.h"

using namespace std;
class DataMem
{

private:
    unsigned char *mem = NULL;
    int size=0;
    void init_mem(const char *filename);
    int reservedSpaceForVars = 16;
    int string_size=0;
public:
    DataMem();
    void getVector(int dir, unsigned char* vector);
    void getScalar(int dir, unsigned char* vector);
    void write(bool* WE, unsigned char* direction, unsigned char* Din32, unsigned char* Din64);
    void write_image();
};

#endif // DATAMEM_H
