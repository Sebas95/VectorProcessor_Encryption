#include "pipeexewb.h"

PipeExeWb::PipeExeWb()
{

    AluResult32 = new unsigned char[4]();
    AluResult64 = new unsigned char[8]();
    Dout32= new unsigned char[4]();
    Dout64= new unsigned char[8]();
}

