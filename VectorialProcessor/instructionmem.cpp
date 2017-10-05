#include "instructionmem.h"

InstructionMem::InstructionMem()
{
    mem = new unsigned char[6*MEGA]();
    mem[0]='f';
    mem[1]='c';
    mem[2]='3';
    //delete[] tempBuffer;
}

unsigned char InstructionMem:: getInstruction(int dir)
{
    char vector[4];
    vector[0] = mem[dir+0];
    vector[1] = mem[dir+1];
    vector[2] = mem[dir+2];
    vector[3] = mem[dir+3];
    return *vector;
}
