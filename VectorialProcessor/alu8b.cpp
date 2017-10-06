#include "alu8b.h"

ALU8b::ALU8b()
{

}

void ALU8b::operate(int ctrl, unsigned char opa,  unsigned char opb, unsigned char* result)
{
    int res=0;
    if(ctrl ==0  )
           res = (int)opa + (int)opb;
    if(ctrl ==1  )
           res = (int)opa - (int)opb;
    if(ctrl ==2  )
           res = (int)opa * (int)opb;
    if(ctrl ==3  ) //3
           res = (int)opa & (int)opb;
    if(ctrl ==4  ) //4
           res = (int)opa | (int)opb;
    if(ctrl ==5  )
           res = (int)opa ^ (int)opb;
    if(ctrl ==6  )
            res = (int)opa >> (int)opb;
    if(ctrl ==7  )
            res = (int)opa << (int)opb;
    if(ctrl ==8  ) //TODO
            res = (int)opa >> (int)opb;
    if(ctrl ==9  ) //TODO
         res = (int)opa << (int)opb;
    else
    {
        printf("%s\n", "error alu");
    }

    *result = (unsigned char)res;

}
