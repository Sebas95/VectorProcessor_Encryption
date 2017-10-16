#include "pipedecoexe.h"

PipeDecoExe::PipeDecoExe()
{
    ra = new unsigned char[4]();
    rb = new unsigned char[4]();
    Ra = new unsigned char[8]();
    Rb = new unsigned char[8]();
   imm  = new unsigned char[4]();


   WE = new bool[2]();
   WE_v=false;
   WE_s=false;
   ctrl_v = 0;
   ctrl_s = 0;
   sel_dat = false;
   sel_vec = false;
   instr_enable = false;
   sel_opb = false;
   sel_opA = new bool[2]();
   cond = new bool[2]();


   dir_rc  = 0;

}

