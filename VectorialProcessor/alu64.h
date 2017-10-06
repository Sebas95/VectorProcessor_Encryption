#ifndef ALU64_H
#define ALU64_H
#include <stdio.h>
#include <stdlib.h>
#include "alu8b.h"

class ALU64
{

private:
    ALU8b* alu0;
    ALU8b* alu1;
    ALU8b* alu2;
    ALU8b* alu3;
    ALU8b* alu4;
    ALU8b* alu5;
    ALU8b* alu6;
    ALU8b* alu7;
public:
    ALU64();
    void operate(int ctrl_v, unsigned char* opa,  unsigned char* opb ,unsigned char* result);
};

#endif // ALU64_H
