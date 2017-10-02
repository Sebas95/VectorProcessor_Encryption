#ifndef INSTRUCTIONMEM_H
#define INSTRUCTIONMEM_H

#include <stddef.h>


class InstructionMem
{
private:
    unsigned char *mem = NULL;
public:
    char getVector(int dir);
    InstructionMem();



};

#endif // INSTRUCTIONMEM_H
