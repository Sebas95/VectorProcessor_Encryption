#ifndef ALU32B_H
#define ALU32B_H
#include <stdio.h>
#include <stdlib.h>

class ALU32b
{
public:
    ALU32b();
    void operate(int ctrl_s, unsigned char* opa,  unsigned char* opb ,bool* z, bool* c,unsigned char* result);
};

#endif // ALU32B_H
