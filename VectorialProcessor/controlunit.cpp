#include "controlunit.h"

ControlUnit::ControlUnit()
{
     WE = new bool[2]();
     sel_opA = new bool[2]();

}

void ControlUnit::obtainControl(bool* opcode,bool* data,bool* F)
{


    WE[0] = false;
    WE[1] = false;
    int input = getIntOpcode(opcode);

    switch ( input )
    {

        case 0: //ldv
            ctrl_v = 0; //x
            ctrl_s = 0;
            sel_opA[0] = false; //x
            sel_opA[1] = false; //x
            break;

        case 1: //strv
            WE[1] = true; //write vector
            ctrl_v = 0;
            ctrl_s = 0;
            sel_opA[0] = false; //opA = 0
            sel_opA[1] = true;
            break;

        case 2://lds
            ctrl_v = 0; //x
            ctrl_s = 0; //suma
            sel_opA[0] = false; //x
            sel_opA[1] = false;//x
            break;

        case 3://strs
            WE[0]=true; //write scalae
            ctrl_v = 0; // x
            ctrl_s = 0;
            sel_opA[0]=true;// x
            sel_opA[1]=true;// x
            break;

        case 4:// add
            ctrl_v = 0;
            ctrl_s = 0;
            break;

        case 5://sub
            ctrl_v = 1;
            ctrl_s = 1;
            break;

        case 6://mult
            ctrl_v = 2;
            ctrl_s = 2;
            break;

        case 7://and
            ctrl_v = 3 ;
            ctrl_s = 3;
            break;

        case 8://or
            ctrl_v = 4;
            ctrl_s = 4;
            break;

        case 9://xor
            ctrl_v = 5;
            ctrl_s = 5;
            break;

        case 10://shr
            ctrl_v = 6;
            ctrl_s = 6;
            break;

        case 11://shl
            ctrl_v = 7;
            ctrl_s = 7;
            break;

        case 12://shrc
            ctrl_v = 8;
            ctrl_s = 8;
            break;

        case 13://shlc
            ctrl_v = 9;
            ctrl_s = 9;
            break;

        case 14://cmpv
            ctrl_v = 1;
            ctrl_s = 1;
            break;

        default:
          printf("%s\n", "Error, bad opcode\n");
          break;
    }

    if(!data[0] && !data[1]) //vector-vector
    {
        WE_v = true;
        WE_s = false;
        sel_opA[0] = true;
        sel_opA[1] = false;
    }
    else if(!data[0] && data[1])  //escalar-vector
    {
        WE_v = true;
        WE_s = false;
        sel_opA[0] = false;
        sel_opA[1] = false;
    }

    else if(data[0] && !data[1])  //escalar-vector
    {
        WE_v = false;
        WE_s = true;
        sel_opA[0] = false;
        sel_opA[1] = false;
    }
    else //memory instruction
    {
        if(input == 0)
        {
            WE_v = true;
            WE_s = false;
        }
        if(input == 1)
        {
            WE_v = false;
            WE_s = false;
        }
        if(input == 2)
        {
            WE_v = false;
            WE_s = true;
        }
        if(input == 3)
        {
            WE_v = false;
            WE_s = false;
        }

    }

    //---------------------------
    if(input == 14)
        instr_enable = true;
    else
        instr_enable = false;

    //----------------------------
    if(input == 2) //para lds
        sel_dat = true;
    else
        sel_dat = false;
    //----------------------------

    if(input == 0) //para ldv
        sel_vec = true;
    else
        sel_vec = false;

    //-----------------------------
    if(!F[0])
        sel_opb = false ;
    else
        sel_opb = true ;


}



int ControlUnit::getIntOpcode(bool* opcode)
{
    if( !opcode[0] && !opcode[1] && !opcode[2] && !opcode[3])
        return 0;

    if( !opcode[0] && !opcode[1] && !opcode[2] && opcode[3])
        return 1;

    if( !opcode[0] && !opcode[1] && opcode[2] && !opcode[3])
        return 2;

    if( !opcode[0] && !opcode[1] && opcode[3] && opcode[3])
        return 3;

    if( !opcode[0] && opcode[1] && !opcode[2] && !opcode[3])
        return 4;

    if( !opcode[0] && opcode[1] && !opcode[2] && opcode[3])
        return 5;

    if( !opcode[0] && opcode[1] && opcode[2] && !opcode[3])
        return 6;

    if( !opcode[0] && opcode[1] && opcode[2] && opcode[3])
        return 7;

    if( opcode[0] && !opcode[1] && !opcode[2] && !opcode[3])
        return 8;

    if( opcode[0] && !opcode[1] && !opcode[2] && opcode[3])
        return 9;

    if( opcode[0] && !opcode[1] && opcode[2] && !opcode[3])
        return 10;

    if( opcode[0] && !opcode[1] && opcode[2] && opcode[3])
        return 11;

    if( opcode[0] && opcode[1] && !opcode[2] && !opcode[3])
        return 12;

    if( opcode[0] && opcode[1] && !opcode[2] && opcode[3])
        return 13;

    if( !opcode[0] && !opcode[1] && !opcode[2] && opcode[3])
        return 14;

    if( opcode[0] && opcode[1] && opcode[2] && opcode[3])
        return 15;

}
