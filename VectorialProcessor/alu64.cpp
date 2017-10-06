#include "alu64.h"

ALU64::ALU64()
{
    alu0 = new ALU8b();
    alu1 = new ALU8b();
    alu2 = new ALU8b();
    alu3 = new ALU8b();
    alu4 = new ALU8b();
    alu5 = new ALU8b();
    alu6 = new ALU8b();
    alu7 = new ALU8b();

}

void ALU64::operate(int ctrl_v, unsigned char* opa,  unsigned char* opb ,unsigned char* result)
{
    unsigned char* res0 = (unsigned char*)malloc(sizeof(unsigned char));
    alu0->operate(ctrl_v,opa[0],opb[0],res0);

    unsigned char* res1 = (unsigned char*)malloc(sizeof(unsigned char));
    alu1->operate(ctrl_v,opa[1],opb[1],res1);

    unsigned char* res2 = (unsigned char*)malloc(sizeof(unsigned char));
    alu2->operate(ctrl_v,opa[2],opb[2],res2);

    unsigned char* res3 = (unsigned char*)malloc(sizeof(unsigned char));
    alu3->operate(ctrl_v,opa[3],opb[3],res3);

    unsigned char* res4 = (unsigned char*)malloc(sizeof(unsigned char));
    alu4->operate(ctrl_v,opa[4],opb[4],res4);

    unsigned char* res5 = (unsigned char*)malloc(sizeof(unsigned char));
    alu5->operate(ctrl_v,opa[5],opb[5],res5);

    unsigned char* res6 = (unsigned char*)malloc(sizeof(unsigned char));
    alu6->operate(ctrl_v,opa[6],opb[6],res6);

    unsigned char* res7 = (unsigned char*)malloc(sizeof(unsigned char));
    alu7->operate(ctrl_v,opa[7],opb[7],res7);

    result[0] = res0[0];
    result[1] = res1[0];
    result[2] = res2[0];
    result[3] = res3[0];
    result[4] = res4[0];
    result[5] = res5[0];
    result[6] = res6[0];
    result[7] = res7[0];
}
