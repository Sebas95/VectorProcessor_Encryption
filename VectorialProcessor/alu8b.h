#ifndef ALU8B_H
#define ALU8B_H
#include <stdio.h>
#include <stdlib.h>


class ALU8b
{
public:
    ALU8b();
    void operate(int ctrl, unsigned char opa,  unsigned char opb, unsigned char* result);
};

#endif // ALU8B_H
