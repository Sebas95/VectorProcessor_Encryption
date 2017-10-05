#ifndef PIPEDECOEXE_H
#define PIPEDECOEXE_H


class PipeDecoExe
{


public:
    PipeDecoExe();
    bool WE[2];
    bool WE_v;
    bool WE_s;
    bool ctrl_v;
    bool ctrl_s;
    bool sel_opa;
    bool sel_opb;
    bool sel_opA[2];
    unsigned char* ra[4];
    unsigned char* rb[4];
    unsigned char* Ra[8];
    unsigned char* Rb[8];
    unsigned char* imm[4];
    int dir_rc;

};

#endif // PIPEDECOEXE_H
