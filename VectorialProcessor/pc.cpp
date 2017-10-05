#include "pc.h"

Pc::Pc()
{
    for (int i = 0 ;  i< 32 ; i++)
        reg[i]=0;
}

void Pc::readPc(bool* pc)
{
    pc = reg;
}
