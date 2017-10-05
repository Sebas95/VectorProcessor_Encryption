#ifndef ALU32B_H
#define ALU32B_H
#include <stdio.h>
#include <stdlib.h>

class ALU32b
{
public:
    ALU32b();
    unsigned char* operate(int ctrl_s, unsigned char* opa,  unsigned char* opb ,bool* z, bool* c);
};

#endif // ALU32B_H
