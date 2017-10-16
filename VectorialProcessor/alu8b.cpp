#include "alu8b.h"

ALU8b::ALU8b()
{

}

void ALU8b::operate(int ctrl, unsigned char opa,  unsigned char opb, unsigned char* result)
{

    if(ctrl ==0  )
           *(int*)result = (int)opa + (int)opb;
    else if(ctrl ==1  )
           *(int*)result = (int)opb - (int)opa;
    else if(ctrl ==2  )
           *(int*)result = (int)opa * (int)opb;
    else if(ctrl ==3  ) //3
           *(int*)result = (int)opa & (int)opb;
    else if(ctrl ==4  ) //4
           *(int*)result = (int)opa | (int)opb;
    else if(ctrl ==5  )
    {
           *(int*)result = (int)opa ^ (int)opb;

    }
    else if(ctrl ==6  )
           *(int*)result = (int)opb >> (int)opa;
    else if(ctrl ==7  )
    {
            *(int*)result = (int)opb << (int)opa;
    }
    else if(ctrl ==8  ) //TODO
            *(int*)result = (int)opb >> (int)opa;
    else if(ctrl ==9  ) //TODO
         *(int*)result = (int)opb << (int)opa;
    else
    {
        printf("%s\n", "error alu");
    }



}
