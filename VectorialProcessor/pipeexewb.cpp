#include "pipeexewb.h"

PipeExeWb::PipeExeWb()
{

    AluResult32 = new unsigned char[4]();
    AluResult64 = new unsigned char[8]();
    Dout32= new unsigned char[4]();
    Dout64= new unsigned char[8]();


    we_v = false;
    we_s = false;
    sel_dat =false;
    sel_vec = false;

    rc_dir = 0;
}

