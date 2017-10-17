#include "processor.h"
#include "signals.h"

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


void* executeInstructions(void* unused)
{

    Processor* processor =  new Processor();

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
    Processor* processor =  (Processor*)processor_obj;


            processor->instruction_memory->getInstruction(pc,instruction);
            pc = pc +4;
            processor->pipe_f_d->writeReg(instruction);
            processor->converter->printBin(instruction,32);


}


void* decode(void* processor_obj)
{
    Int_Bin_converter* converter =  new Int_Bin_converter();
    Processor* p =  (Processor*)processor_obj;


            p->pipe_f_d->getData(Data);
            p->pipe_f_d->getOpcode(opcode);
            p->pipe_f_d->getF(F);
            p->pipe_f_d->getCond(Cond);
            p->pipe_f_d->getra(ra);
            p->pipe_f_d->getrb(rb);
            p->pipe_f_d->getRa(Ra);
            p->pipe_f_d->getRb(Rb);
            p->pipe_f_d->getRc(Rc);
            p->pipe_f_d->getImm(Imm);

            p->reg_bank_s->readScalar( converter->convert(ra,2)  , content_ra );
            p->reg_bank_s->readScalar( converter->convert(rb,2)  , content_rb );

            p->reg_bank_v->readVector( converter->convert(Ra,2) , content_Ra);
            p->reg_bank_v->readVector( converter->convert(Rb,2) , content_Rb);

            p->control_unit->obtainControl(opcode,Data,F);

            p->pipe_d_e->cond   =  Cond;
            p->pipe_d_e->ctrl_s =  p->control_unit->ctrl_s;
            p->pipe_d_e->ctrl_v =  p->control_unit->ctrl_v;
            p->pipe_d_e->dir_rc = converter->convert(Rc,2);
            *immExt = converter->convert(Imm,17);
            p->pipe_d_e->imm = (unsigned char*)immExt;
            p->pipe_d_e->instr_enable   =  p->control_unit->instr_enable;

            for(int i = 0; i<8 ;  i++)
                p->pipe_d_e->Ra[i]     =  content_Ra[i];

            for(int i = 0; i<4 ;  i++)
                p->pipe_d_e->ra[i]     =  content_ra[i];

            for(int i = 0; i<8 ;  i++)
                p->pipe_d_e->Rb[i]     = content_Rb[i];

            p->pipe_d_e->rb[0]     =  content_rb[0];
            p->pipe_d_e->rb[1]     =  content_rb[1];
            p->pipe_d_e->rb[2]     =  content_rb[2];
            p->pipe_d_e->rb[3]     =  content_rb[3];
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


            for (int i = 0; i< 8 ; i++)   replicatedScalar[i] = p->pipe_d_e->ra[0]; //es little endian
            muxbResult = p->mux_opb->multiplex( p->pipe_d_e->sel_opb, p->pipe_d_e->rb, p->pipe_d_e->imm);
            muxAResult = p->mux_opA->multiplex( p->pipe_d_e->sel_opA,replicatedScalar, p->pipe_d_e->Ra,zero);
            //ALUs
            p->alu32->operate(p->pipe_d_e->ctrl_s,p->pipe_d_e->ra,muxbResult,Z,C,aluResult32);

            p->alu64->operate(p->pipe_d_e->ctrl_v,muxAResult,p->pipe_d_e->Rb,aluResult64);

            //condition unit
            p->cond_unit->write_flags(Z,p->pipe_d_e->instr_enable);
            p->cond_unit->eval_conditions(p->pipe_d_e->WE, & p->pipe_d_e->WE_s,& p->pipe_d_e->WE_v,p->pipe_d_e->cond);
                //memory
            p->data_mem->getScalar(*(int*)aluResult32,memOut32);
            p->data_mem->getVector(*(int*)aluResult32,memOut64);

            p->data_mem->write(p->pipe_d_e->WE,aluResult32, p->pipe_d_e->rb,aluResult64);

            p->pipe_exe_wb->AluResult32[0] = aluResult32[0];
            p->pipe_exe_wb->AluResult32[1] = aluResult32[1];
            p->pipe_exe_wb->AluResult32[2] = aluResult32[2];
            p->pipe_exe_wb->AluResult32[3] = aluResult32[3];

            for (int i = 0; i< 8 ; i++)    p->pipe_exe_wb->Dout64[i] = memOut64[i];

            for (int i = 0; i< 8 ; i++)    p->pipe_exe_wb->AluResult64[i] = aluResult64[i];

            for (int i = 0; i< 4 ; i++)    p->pipe_exe_wb->Dout32[i] = memOut32[i];

            p->pipe_exe_wb->rc_dir = p->pipe_d_e->dir_rc;
            p->pipe_exe_wb->sel_dat =p->pipe_d_e->sel_dat ;
            p->pipe_exe_wb->sel_vec =p->pipe_d_e->sel_vec ;
            p->pipe_exe_wb->we_s =p->pipe_d_e->WE_s ;
            p->pipe_exe_wb->we_v =p->pipe_d_e->WE_v;

}




void* write_back(void*processor_obj)
{
    Processor* p =  (Processor*)processor_obj;


            sel_dat_out = p->mux_seldat->multiplex( p->pipe_exe_wb->sel_dat, p->pipe_exe_wb->AluResult32,p->pipe_exe_wb->Dout32 );
            sel_vec_out = p->mux_sel_vec->multiplex2chan(p->pipe_exe_wb->sel_vec, p->pipe_exe_wb->Dout64,p->pipe_exe_wb->AluResult64);
            //escritura al banco escalar
            p->reg_bank_s->writeScalar(p->pipe_exe_wb->rc_dir,sel_dat_out,p->pipe_exe_wb->we_s);
            //escritura al banco vectorial
            p->reg_bank_v->writeVector(p->pipe_exe_wb->rc_dir,sel_vec_out,  p->pipe_exe_wb->we_v);


}
