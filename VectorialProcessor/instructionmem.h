#ifndef INSTRUCTIONMEM_H
#define INSTRUCTIONMEM_H
#include <stddef.h>
#define MEGA 1024*1024

class InstructionMem
{
private:
    unsigned char *mem = NULL;
public:

    InstructionMem();
    unsigned char getInstruction(int dir);


};

#endif // INSTRUCTIONMEM_H
