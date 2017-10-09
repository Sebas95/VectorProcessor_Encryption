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
    cond_unit =  new ConditionUnit();
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
    pthread_t e;
    pthread_create(&f,NULL,fetch,(void*)processor);
    usleep(1000000);
    pthread_create(&d,NULL,decode,(void*)processor);
    usleep(1000000);
    pthread_create(&e,NULL,execution,(void*)processor);

    //processor->start =true;

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
    bool* Imm= new bool[17]();    processor->pipe_f_d->getImm(Imm);
    int* immExt = new int[1]();

    unsigned char* content_ra = new unsigned char[4](); //4 byte int
    unsigned char* content_rb = new unsigned char[4](); //4 byte int
    processor->reg_bank_s->readScalar( converter->convert(ra,2)  , content_ra );
    processor->reg_bank_s->readScalar( converter->convert(rb,2)  , content_rb );

    unsigned char* content_Ra = new unsigned char[4](); //8 byte vector
    unsigned char* content_Rb = new unsigned char[4](); //8 byte vector
    processor->reg_bank_v->readVector( converter->convert(Ra,2) , content_Ra);
    processor->reg_bank_v->readVector( converter->convert(Rb,2) , content_Rb);

    processor->control_unit->obtainControl(opcode,Data,F);
    processor->pipe_d_e->cond   =  Cond;
    processor->pipe_d_e->ctrl_s =  processor->control_unit->ctrl_s;
    processor->pipe_d_e->ctrl_v =  processor->control_unit->ctrl_v;
    processor->pipe_d_e->dir_rc = converter->convert(Rc,2);
    *immExt = converter->convert(Imm,17);
    processor->pipe_d_e->imm = (unsigned char*)immExt;
    processor->pipe_d_e->instr_enable   =  processor->control_unit->instr_enable;
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



void* execution(void* processor_obj)
{
    Int_Bin_converter* converter =  new Int_Bin_converter();
    Processor* processor =  (Processor*)processor_obj;
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



    replicatedScalar[0] = processor->pipe_d_e->ra[3];
    replicatedScalar[1] = processor->pipe_d_e->ra[3];
    replicatedScalar[2] = processor->pipe_d_e->ra[3];
    replicatedScalar[3] = processor->pipe_d_e->ra[3];
    replicatedScalar[4] = processor->pipe_d_e->ra[3];
    replicatedScalar[5] = processor->pipe_d_e->ra[3];
    replicatedScalar[6] = processor->pipe_d_e->ra[3];
    replicatedScalar[7] = processor->pipe_d_e->ra[3];
    //while(! processor->start){}


    processor->pipe_d_e->dir_rc;
    processor->pipe_d_e->instr_enable;
    processor->pipe_d_e->sel_dat;

    //muxes
    muxbResult = processor->mux_opb->multiplex( processor->pipe_d_e->sel_opb, processor->pipe_d_e->rb,
                                                processor->pipe_d_e->imm);
    muxAResult = processor->mux_opA->multiplex( processor->pipe_d_e->sel_opA,replicatedScalar,
                                                processor->pipe_d_e->Ra,zero);
    //ALUs
    processor->alu32->operate(processor->pipe_d_e->ctrl_s,processor->pipe_d_e->ra,
                              muxbResult,Z,C,aluResult32);
    processor->alu64->operate(processor->pipe_d_e->ctrl_v,muxAResult,processor->pipe_d_e->Rb,aluResult64);

    //condition unit
    processor->cond_unit->write_flags(Z,processor->pipe_d_e->instr_enable);
    processor->cond_unit->eval_conditions(processor->pipe_d_e->WE,
                                          & processor->pipe_d_e->WE_s,& processor->pipe_d_e->WE_v,processor->pipe_d_e->cond);

    int AA = *(unsigned int*)aluResult32;
    int BB = *(unsigned int*)aluResult64;
    printf("%d  %d  ", AA,BB);
    //memory
    processor->data_mem->getScalar(*(int*)aluResult32,memOut32);
    processor->data_mem->getVector(*(int*)aluResult64,memOut64);
    processor->data_mem->write(processor->pipe_d_e->WE,aluResult32, processor->pipe_d_e->rb,aluResult64);

    processor->pipe_exe_wb->AluResult32 = aluResult32;
    processor->pipe_exe_wb->Dout64 = memOut64;
    processor->pipe_exe_wb->Dout32 = memOut32;
    processor->pipe_exe_wb->rc_dir = processor->pipe_d_e->dir_rc;
    processor->pipe_exe_wb->sel_dat =processor->pipe_d_e->sel_dat ;
    processor->pipe_exe_wb->we_s =processor->pipe_d_e->WE_s ;
    processor->pipe_exe_wb->we_v =processor->pipe_d_e->WE_v;

    //

    //usleep(1000000);
}
