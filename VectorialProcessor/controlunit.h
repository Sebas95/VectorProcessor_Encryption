#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H
#include <stdio.h>

class ControlUnit
{
private:

public:
    ControlUnit();
    void obtainControl(bool* opcode,bool* data,bool* F);
    bool WE[2];
    bool WE_v;
    bool WE_s;
    int ctrl_v;
    int ctrl_s;
    bool sel_dat;
    bool instr_enable;
    bool sel_opb;
    bool sel_opA[2];

    int getIntOpcode(bool opcode[]);
};

#endif // CONTROLUNIT_H
