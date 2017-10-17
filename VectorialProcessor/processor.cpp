#include "processor.h"


Processor::Processor()
{

    converter =  new Int_Bin_converter();
    //___________fetch___________
    data_mem =  new DataMem();
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

    //____________wb____________
    pipe_exe_wb = new PipeExeWb();
    mux_seldat = new Mux32("Mux seldat");
    mux_sel_vec = new Mux64("mux vector sel");
    start = false;

}




int num_ciclos = 26625;
//int num_ciclos = 2;
//int num_ciclos = 28673;
bool clk = false;

int steps = 0;

int getSteps()
{
    return steps;
}

void setSteps(int s)
{
    steps = s;
}


void* executeInstructions(void* procesador)
{

    Processor* processor = (Processor*)procesador;

    for(int x = 0; x< num_ciclos*2;x++ )
    {
        if(clk == false)
        {
            clk = true;
            printf("ciclo %d \n",x/2);
            fetch(processor);
            decode(processor);
            execution(processor);
            write_back(processor);
        }
        else
        {
            clk = false;


        }

        usleep(10);

    }

    processor->data_mem->write_image();
    pthread_exit(NULL); //last thing to do
}


void* fetch(void* processor_obj)
{
    Processor* p =  (Processor*)processor_obj;


            p->instruction_memory->getInstruction(p->pc,p->instruction);
            p->pc = p->pc +4;
            p->pipe_f_d->writeReg(p->instruction);
            p->converter->printBin(p->instruction,32);


}


void* decode(void* processor_obj)
{
    Int_Bin_converter* converter =  new Int_Bin_converter();
    Processor* p =  (Processor*)processor_obj;


            p->pipe_f_d->getData(p->Data);
            p->pipe_f_d->getOpcode(p->opcode);
            p->pipe_f_d->getF(p->F);
            p->pipe_f_d->getCond(p->Cond);
            p->pipe_f_d->getra(p->ra);
            p->pipe_f_d->getrb(p->rb);
            p->pipe_f_d->getRa(p->Ra);
            p->pipe_f_d->getRb(p->Rb);
            p->pipe_f_d->getRc(p->Rc);
            p->pipe_f_d->getImm(p->Imm);

            p->reg_bank_s->readScalar( converter->convert(p->ra,2)  , p->content_ra );
            p->reg_bank_s->readScalar( converter->convert(p->rb,2)  , p->content_rb );

            p->reg_bank_v->readVector( converter->convert(p->Ra,2) , p->content_Ra);
            p->reg_bank_v->readVector( converter->convert(p->Rb,2) , p->content_Rb);

            p->control_unit->obtainControl(p->opcode,p->Data,p->F);

            p->pipe_d_e->cond   =  p->Cond;
            p->pipe_d_e->ctrl_s =  p->control_unit->ctrl_s;
            p->pipe_d_e->ctrl_v =  p->control_unit->ctrl_v;
            p->pipe_d_e->dir_rc = converter->convert(p->Rc,2);
            *(p->immExt) = converter->convert(p->Imm,17);
            p->pipe_d_e->imm = (unsigned char*)p->immExt;
            p->pipe_d_e->instr_enable   =  p->control_unit->instr_enable;

            for(int i = 0; i<8 ;  i++)
                p->pipe_d_e->Ra[i]     =  p->content_Ra[i];

            for(int i = 0; i<4 ;  i++)
                p->pipe_d_e->ra[i]     =  p->content_ra[i];

            for(int i = 0; i<8 ;  i++)
                p->pipe_d_e->Rb[i]     = p->content_Rb[i];

            p->pipe_d_e->rb[0]     =  p->content_rb[0];
            p->pipe_d_e->rb[1]     =  p->content_rb[1];
            p->pipe_d_e->rb[2]     =  p->content_rb[2];
            p->pipe_d_e->rb[3]     =  p->content_rb[3];
            p->pipe_d_e->sel_dat=  p->control_unit->sel_dat;
            p->pipe_d_e->sel_vec=  p->control_unit->sel_vec;
            p->pipe_d_e->sel_opA=  p->control_unit->sel_opA;
            p->pipe_d_e->sel_opb=  p->control_unit->sel_opb;
            p->pipe_d_e->WE     = p->control_unit->WE;
            p->pipe_d_e->WE_s   = p->control_unit->WE_s;
            p->pipe_d_e->WE_v   = p->control_unit->WE_v;




}


void* execution(void* processor_obj)
{
    Processor* p =  (Processor*)processor_obj;


            for (int i = 0; i< 8 ; i++)   p->replicatedScalar[i] = p->pipe_d_e->ra[0]; //es little endian
            p->muxbResult = p->mux_opb->multiplex( p->pipe_d_e->sel_opb, p->pipe_d_e->rb, p->pipe_d_e->imm);
            p->muxAResult = p->mux_opA->multiplex( p->pipe_d_e->sel_opA,p->replicatedScalar, p->pipe_d_e->Ra,p->zero);
            //ALUs
            p->alu32->operate(p->pipe_d_e->ctrl_s,p->pipe_d_e->ra,p->muxbResult,p->Z,p->C,p->aluResult32);

            p->alu64->operate(p->pipe_d_e->ctrl_v,p->muxAResult,p->pipe_d_e->Rb,p->aluResult64);

            //condition unit
            p->cond_unit->write_flags(p->Z,p->pipe_d_e->instr_enable);
            p->cond_unit->eval_conditions(p->pipe_d_e->WE, & p->pipe_d_e->WE_s,& p->pipe_d_e->WE_v,p->pipe_d_e->cond);
                //memory
            p->data_mem->getScalar(*(int*)p->aluResult32,p->memOut32);
            p->data_mem->getVector(*(int*)p->aluResult32,p->memOut64);

            p->data_mem->write(p->pipe_d_e->WE,p->aluResult32, p->pipe_d_e->rb,p->aluResult64);

            p->pipe_exe_wb->AluResult32[0] = p->aluResult32[0];
            p->pipe_exe_wb->AluResult32[1] = p->aluResult32[1];
            p->pipe_exe_wb->AluResult32[2] = p->aluResult32[2];
            p->pipe_exe_wb->AluResult32[3] = p->aluResult32[3];

            for (int i = 0; i< 8 ; i++)    p->pipe_exe_wb->Dout64[i] = p->memOut64[i];

            for (int i = 0; i< 8 ; i++)    p->pipe_exe_wb->AluResult64[i] = p->aluResult64[i];

            for (int i = 0; i< 4 ; i++)    p->pipe_exe_wb->Dout32[i] = p->memOut32[i];

            p->pipe_exe_wb->rc_dir = p->pipe_d_e->dir_rc;
            p->pipe_exe_wb->sel_dat =p->pipe_d_e->sel_dat ;
            p->pipe_exe_wb->sel_vec =p->pipe_d_e->sel_vec ;
            p->pipe_exe_wb->we_s =p->pipe_d_e->WE_s ;
            p->pipe_exe_wb->we_v =p->pipe_d_e->WE_v;

}




void* write_back(void*processor_obj)
{
    Processor* p =  (Processor*)processor_obj;


            p->sel_dat_out = p->mux_seldat->multiplex( p->pipe_exe_wb->sel_dat, p->pipe_exe_wb->AluResult32,p->pipe_exe_wb->Dout32 );
            p->sel_vec_out = p->mux_sel_vec->multiplex2chan(p->pipe_exe_wb->sel_vec, p->pipe_exe_wb->Dout64,p->pipe_exe_wb->AluResult64);
            //escritura al banco escalar
            p->reg_bank_s->writeScalar(p->pipe_exe_wb->rc_dir,p->sel_dat_out,p->pipe_exe_wb->we_s);
            //escritura al banco vectorial
            p->reg_bank_v->writeVector(p->pipe_exe_wb->rc_dir,p->sel_vec_out,  p->pipe_exe_wb->we_v);


}
