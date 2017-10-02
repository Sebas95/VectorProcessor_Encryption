#include "instructionmem.h"

InstructionMem::InstructionMem()
{
    mem = new unsigned char[1024]();
    mem[0]='f';
    mem[1]='c';
    mem[2]='3';
    //delete[] tempBuffer;
}

char InstructionMem:: getVector(int dir)
{
    char vector[8];
    vector[0] = mem[dir+0];
    vector[1] = mem[dir+1];
    vector[2] = mem[dir+2];
    vector[3] = mem[dir+3];
    vector[4] = mem[dir+4];
    vector[5] = mem[dir+5];
    vector[6] = mem[dir+6];
    vector[7] = mem[dir+7];
    return *vector;
}
