#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "alu32b.h"
#include "alu64.h"
#include "controlunit.h"
#include "conditionunit.h"
#include "datamem.h"
#include "instructionmem.h"
#include "mux32.h"
#include "mux64.h"
#include "pc.h"
#include "pipedecoexe.h"
#include "pipeexewb.h"
#include "pipefetchdeco.h"
#include "registerbankvector.h"
#include "registersbankscalar.h"
#include "int_bin_converter.h"
#include <pthread.h>
#include <unistd.h>



class Processor
{
private:

public:
    Processor();
    Int_Bin_converter* converter;
    //___________fetch___________
    InstructionMem* instruction_memory;
    //Pc* pc ;
    //___________deco___________
    PipeFetchDeco* pipe_f_d;
    ControlUnit* control_unit;
    RegisterBankVector* reg_bank_v;
    RegistersBankScalar* reg_bank_s;

    //____________exe___________
    PipeDecoExe* pipe_d_e;
    Mux32* mux_opb;
    Mux64* mux_opA;
    ALU32b* alu32;
    ALU64* alu64;
    ConditionUnit* cond_unit;
    DataMem* data_mem;
    //____________wb____________
    PipeExeWb* pipe_exe_wb;
    Mux32* mux_seldat;
    Mux64*mux_sel_vec;

    bool start;

};

void *executeInstructions(void *unused);
void* fetch(void*);
void* decode(void*);
void* execution(void*);
void* write_back(void*);



#endif // PROCESSOR_H
