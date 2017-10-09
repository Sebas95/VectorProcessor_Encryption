#ifndef PIPEEXEWB_H
#define PIPEEXEWB_H


class PipeExeWb
{
public:
    PipeExeWb();
    bool we_v;
    bool we_s;
    bool sel_dat;
    unsigned char* AluResult32;
    unsigned char* Dout32;
    unsigned char* Dout64;
    int rc_dir;
};

#endif // PIPEEXEWB_H
