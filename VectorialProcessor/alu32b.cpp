#include "alu32b.h"

ALU32b::ALU32b()
{

}


 unsigned char* ALU32b::operate(int ctrl_s, unsigned char* opa,  unsigned char* opb ,bool* z, bool* c)
 {
     int res=0;
     unsigned char* out = (unsigned char*)malloc(4*sizeof(unsigned char));
     if(ctrl_s ==0  )
            res = *(int*)opa + *(int*)opb;
     if(ctrl_s ==1  )
            res = *(int*)opa - *(int*)opb;
     if(ctrl_s ==2  )
            res = *(int*)opa * *(int*)opb;
     if(ctrl_s ==3  ) //3
            res = *(int*)opa & *(int*)opb;
     if(ctrl_s ==4  ) //4
            res = *(int*)opa | *(int*)opb;
     if(ctrl_s ==5  ) //5
            res = *(int*)opa ^ *(int*)opb;
     else
     {
         printf("%s\n", "error alu");
     }

     if(res == 0)
         *c = true;
     else
         *c = false;

     *out = *(unsigned char*)res;
     return out;
 }
