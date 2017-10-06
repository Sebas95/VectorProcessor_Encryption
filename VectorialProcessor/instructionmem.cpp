#include "instructionmem.h"

InstructionMem::InstructionMem()
{
    mem = new unsigned char[6*MEGA]();
    mem[0]='f';
    mem[1]='c';
    mem[2]='3';
    //delete[] tempBuffer;
}

void InstructionMem:: getInstruction(int dir, unsigned char *instruction)
{

    instruction[0] = mem[dir+0];
    instruction[1] = mem[dir+1];
    instruction[2] = mem[dir+2];
    instruction[3] = mem[dir+3];

}
