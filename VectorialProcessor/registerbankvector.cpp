#include "registerbankvector.h"
#include <stdio.h>

RegisterBankVector::RegisterBankVector()
{
    v1 = new unsigned char[8]();
    v2 = new unsigned char[8]();
    v3 = new unsigned char[8]();
    v4 = new unsigned char[8]();
}

void RegisterBankVector::readVector(int dir,unsigned char* v)
{
    if(dir==0)
    {
       // printf(" vector 0 %c %c %c %c %c %c %c %c \n",v1[0],v1[1],v1[2],v1[3],v1[4],v1[5],v1[6],v1[7]);
        v[0] = v1[0];
        v[1] = v1[1];
        v[2] = v1[2];
        v[3] = v1[3];
        v[4] = v1[4];
        v[5] = v1[5];
        v[6] = v1[6];
        v[7] = v1[7];

    }
    else if(dir==1)
    {
        v[0] = v2[0];
        v[1] = v2[1];
        v[2] = v2[2];
        v[3] = v2[3];
        v[4] = v2[4];
        v[5] = v2[5];
        v[6] = v2[6];
        v[7] = v2[7];
    }
    else if(dir==2)
    {
        v[0] = v3[0];
        v[1] = v3[1];
        v[2] = v3[2];
        v[3] = v3[3];
        v[4] = v3[4];
        v[5] = v3[5];
        v[6] = v3[6];
        v[7] = v3[7];
    }
    else
    {
        v[0] = v4[0];
        v[1] = v4[1];
        v[2] = v4[2];
        v[3] = v4[3];
        v[4] = v4[4];
        v[5] = v4[5];
        v[6] = v4[6];
        v[7] = v4[7];
    }

}
void RegisterBankVector::writeVector(int dir_rc,unsigned char* v,bool we_v)
{
    if(we_v)
    {
        if(dir_rc==0)
        {

            v1[0] = v[0];
            v1[1] = v[1];
            v1[2] = v[2];
            v1[3] = v[3];
            v1[4] = v[4];
            v1[5] = v[5];
            v1[6] = v[6];
            v1[7] = v[7];
          //  printf(" vector escritura en v0 %c %c %c %c %c %c %c %c \n",v[0],v1[1],v1[2],v1[3],v1[4],v1[5],v1[6],v1[7]);
        }
        else if(dir_rc==1)
        {
            v2[0] = v[0];
            v2[1] = v[1];
            v2[2] = v[2];
            v2[3] = v[3];
            v2[4] = v[4];
            v2[5] = v[5];
            v2[6] = v[6];
            v2[7] = v[7];
        }
        else if(dir_rc==2)
        {
            v3[0] = v[0];
            v3[1] = v[1];
            v3[2] = v[2];
            v3[3] = v[3];
            v3[4] = v[4];
            v3[5] = v[5];
            v3[6] = v[6];
            v3[7] = v[7];
        }
        else
        {
            v4[0] = v[0];
            v4[1] = v[1];
            v4[2] = v[2];
            v4[3] = v[3];
            v4[4] = v[4];
            v4[5] = v[5];
            v4[6] = v[6];
            v4[7] = v[7];
        }
    }
}
