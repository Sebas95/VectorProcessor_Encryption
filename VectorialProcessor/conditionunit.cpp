#include "conditionunit.h"

ConditionUnit::ConditionUnit()
{

}

void
ConditionUnit::write_flags(bool z,bool instr_en)
{
    if(instr_en)
    {
        this->Z = z;
    }
}

void ConditionUnit::eval_conditions(bool* WE,bool* we_s, bool* we_v, bool* cond)
{
    if(!cond[1] && !cond[0])
    {
        WE[0] = WE[0] && Z;
        WE[1] = WE[1] && Z;
        we_s[0] =  we_s[0] && Z;
        we_v[1] =  we_v[1] && Z;
    }
    if(!cond[1] && cond[0])
    {
        WE[0] = WE[0] && !Z;
        WE[1] = WE[1] && !Z;
        we_s[0] =  we_s[0] && !Z;
        we_v[1] =  we_v[1] && !Z;
    }
}