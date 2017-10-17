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




    int pc=0;
    bool* instruction = new bool[32]();

    bool* Data = new bool[2]();
    bool*opcode = new bool[4]();
    bool* F = new bool[1]();
    bool* Cond = new bool[2]();
    bool* ra= new bool[2]();
    bool* rb= new bool[2]();
    bool* Ra= new bool[2]();
    bool* Rb= new bool[2]();
    bool* Rc= new bool[2]();
    bool* Imm= new bool[17]();
    int* immExt = new int[1]();
    unsigned char* content_ra = new unsigned char[4](); //4 byte int
    unsigned char* content_rb = new unsigned char[4](); //4 byte int
    unsigned char* content_Ra = new unsigned char[8](); //8 byte vector
    unsigned char* content_Rb = new unsigned char[8](); //8 byte vector


    bool* Z = new bool[1]();
    bool* C = new bool[1]();
    unsigned char* muxbResult = new unsigned char[4]();
    unsigned char* muxAResult = new unsigned char[8]();
    unsigned char* aluResult32 = new unsigned char[4]();
    unsigned char* aluResult64 = new unsigned char[8]();
    unsigned char* memOut32 = new unsigned char[4]();
    unsigned char* memOut64 = new unsigned char[8]();
    unsigned char* zero = new unsigned char[8]();
    unsigned char* replicatedScalar = new unsigned char[8]();

    unsigned char* sel_dat_out = new unsigned char[4]();
    unsigned char* sel_vec_out = new unsigned char[8]();


    bool start;

};



int getSteps();
void setSteps(int s);
void *executeInstructions(void *procesador);
void* fetch(void*);
void* decode(void*);
void* execution(void*);
void* write_back(void*);



#endif // PROCESSOR_H
