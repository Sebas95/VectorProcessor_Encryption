#include "processor.h"

Processor::Processor()
{

    converter =  new Int_Bin_converter();
    //___________fetch___________
    instruction_memory =new InstructionMem();
   // pc = new Pc();
    //___________deco___________
    pipe_f_d = new PipeFetchDeco();
    control_unit =  new ControlUnit();
    reg_bank_v = new RegisterBankVector();
    reg_bank_s =  new RegistersBankScalar();

    //____________exe___________
    pipe_d_e = new PipeDecoExe();
    mux_opb =  new Mux32("Mux selopb");
    mux_opA =  new Mux64("Mux selopA");
    alu32 =  new ALU32b();
    alu64 =  new ALU64();
    cond_unit =  new ControlUnit();
    data_mem =  new DataMem();
    //____________wb____________
    pipe_exe_wb = new PipeExeWb();
    mux_seldat = new Mux32("Mux seldat");

    start = false;

}

void executeInstructions()
{


    Processor* processor =  new Processor();

    pthread_t f;
    pthread_t d;
    pthread_create(&f,NULL,fetch,(void*)processor);
    usleep(1000);
    pthread_create(&d,NULL,decode,(void*)processor);

    //processor->start =true;
    pthread_exit(NULL); //last thing to do
}

void* fetch(void* processor_obj)
{
    Processor* processor =  (Processor*)processor_obj;
    //while(! processor->start){}


    int pc=0;
    bool* instruction = new bool[32]();


    pc = 0;
    processor->instruction_memory->getInstruction(pc,instruction);
    pc = pc +4;
    processor->pipe_f_d->writeReg(instruction);
    processor->converter->printBin(instruction,32);

    //usleep(1000000);
}

void* decode(void* processor_obj)
{
    Int_Bin_converter* converter =  new Int_Bin_converter();
    Processor* processor =  (Processor*)processor_obj;
    //while(!processor->start){}

    bool* Data = new bool[2]();   processor->pipe_f_d->getData(Data);
    bool*opcode = new bool[4]();  processor->pipe_f_d->getOpcode(opcode);
    bool* F = new bool[1]();      processor->pipe_f_d->getF(F);
    bool* Cond = new bool[2]();   processor->pipe_f_d->getCond(Cond);
    bool* ra= new bool[2]();      processor->pipe_f_d->getra(ra);
    bool* rb= new bool[2]();      processor->pipe_f_d->getrb(rb);
    bool* Ra= new bool[2]();      processor->pipe_f_d->getRa(Ra);
    bool* Rb= new bool[2]();      processor->pipe_f_d->getRb(Rb);
    bool* Rc= new bool[2]();      processor->pipe_f_d->getRc(Rc);
    bool* Imm= new bool[17](); processor->pipe_f_d->getImm(Imm);

    unsigned char* content_ra = new unsigned char[4](); //4 byte int
    unsigned char* content_rb = new unsigned char[4](); //4 byte int
    processor->reg_bank_s->readScalar( converter->convert(ra,2)  , content_ra );
    processor->reg_bank_s->readScalar( converter->convert(rb,2)  , content_rb );

    unsigned char* content_Ra = new unsigned char[4](); //8 byte vector
    unsigned char* content_Rb = new unsigned char[4](); //8 byte vector
    processor->reg_bank_v->readVector( converter->convert(Ra,2) , content_Ra);
    processor->reg_bank_v->readVector( converter->convert(Rb,2) , content_Rb);

    processor->control_unit->obtainControl(opcode,Data,F);

    processor->pipe_d_e->cond   =  cond;
    processor->pipe_d_e->ctrl_s =  processor->control_unit->ctrl_s;
    processor->pipe_d_e->ctrl_v =  processor->control_unit->ctrl_v;
    processor->pipe_d_e->dir_rc = Rc;
    processor->pipe_d_e->imm    = Imm;
    processor->pipe_d_e->instr_enable   =  processor->cond_uni;
    processor->pipe_d_e->Ra     =  content_Ra;
    processor->pipe_d_e->ra     =  content_ra;
    processor->pipe_d_e->Rb     = content_Rb;
    processor->pipe_d_e->rb     =  content_rb;
    processor->pipe_d_e->sel_dat=  processor->control_unit->sel_dat;
    processor->pipe_d_e->sel_opA=  processor->control_unit->sel_opA;
    processor->pipe_d_e->sel_opb=  processor->control_unit->sel_opb;
    processor->pipe_d_e->WE     = processor->control_unit->WE;
    processor->pipe_d_e->WE_s   = processor->control_unit->WE_s;
    processor->pipe_d_e->WE_v   = processor->control_unit->WE_v;




   // usleep(1000000);
}
