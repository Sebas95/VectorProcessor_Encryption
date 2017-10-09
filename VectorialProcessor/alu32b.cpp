#include "alu32b.h"

ALU32b::ALU32b()
{

}


void ALU32b::operate(int ctrl_s, unsigned char* opa,  unsigned char* opb ,bool* z, bool* c,unsigned char* result)
 {
     int* res= new int[1]();
     if(ctrl_s ==0  )
     {
            *res = *(int*)opa + *(int*)opb;

     }
     else if(ctrl_s ==1  )
            *res = *(int*)opa - *(int*)opb;
     else if(ctrl_s ==2  )
            *res = *(int*)opa * *(int*)opb;
     else if(ctrl_s ==3  ) //3
            *res = *(int*)opa & *(int*)opb;
     else if(ctrl_s ==4  ) //4
            *res = *(int*)opa | *(int*)opb;
     else if(ctrl_s ==5  ) //5
            *res = *(int*)opa ^ *(int*)opb;
     else
     {
         printf("%s\n", "error alu");
     }

     if(*res == 0)
         z[0] = true;
     else
         z[0] = false;

     *result = *(unsigned char*)res;

 }
