#ifndef INSTRUCTIONMEM_H
#define INSTRUCTIONMEM_H
#include <stddef.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>



class InstructionMem
{
private:
    bool* mem;
    void init_mem(const char *filename);
    int size = 0;
public:

    InstructionMem();
    void getInstruction(int dir, bool *instruction);


};

#endif // INSTRUCTIONMEM_H
