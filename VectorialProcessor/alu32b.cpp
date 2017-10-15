#include "alu32b.h"

ALU32b::ALU32b()
{

}


void ALU32b::operate(int ctrl_s, unsigned char* opa,  unsigned char* opb ,bool* z, bool* c,unsigned char* result)
 {

     if(ctrl_s ==0  )
     {
            *(int*)result = *(int*)opa + *(int*)opb;
     }
     else if(ctrl_s ==1  )
            *(int*)result = *(int*)opa - *(int*)opb;
     else if(ctrl_s ==2  )
            *(int*)result = *(int*)opa * *(int*)opb;
     else if(ctrl_s ==3  ) //3
            *(int*)result = *(int*)opa & *(int*)opb;
     else if(ctrl_s ==4  ) //4
            *(int*)result = *(int*)opa | *(int*)opb;
     else if(ctrl_s ==5  ) //5
            *(int*)result = *(int*)opa ^ *(int*)opb;
     else
     {
         printf("%s\n", "error alu");
     }

     if(*(int*)result == 0)
         z[0] = true;
     else
         z[0] = false;



 }
