#include "mux32.h"

Mux32::Mux32(string name)
{
    this->name = name;
}

unsigned char* Mux32::multiplex(bool select,unsigned char chan0[4], unsigned char chan1[4])
{
    if(!select)
    {
        return chan0;
    }
    else
    {
        return chan1;

    }
}

