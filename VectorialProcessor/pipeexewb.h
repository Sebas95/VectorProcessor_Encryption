#ifndef PIPEEXEWB_H
#define PIPEEXEWB_H


class PipeExeWb
{
public:
    PipeExeWb();
    bool we_v;
    bool we_s;
    bool sel_dat;
    unsigned char* AluResult32[4];
    unsigned char* Dout32[4];
    unsigned char* AluResult64[8];
    bool rc_dir[2];
};

#endif // PIPEEXEWB_H
