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
    void getInstruction(int dir, unsigned char *instruction);


};

#endif // INSTRUCTIONMEM_H
