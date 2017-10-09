#ifndef PIPEDECOEXE_H
#define PIPEDECOEXE_H


class PipeDecoExe
{


public:
    PipeDecoExe();
    bool* WE;
    bool WE_v;
    bool WE_s;
    int ctrl_v;
    int ctrl_s;
    bool sel_dat;
    bool instr_enable;
    bool sel_opb;
    bool* sel_opA;
    bool* cond;

    unsigned char* ra;
    unsigned char* rb;
    unsigned char* Ra;
    unsigned char* Rb;
    unsigned char* imm;
    int dir_rc;

};

#endif // PIPEDECOEXE_H
