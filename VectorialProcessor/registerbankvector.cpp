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
        printf(" vector 0 %c %c %c %c %c %c %c %c \n",v1[0],v1[1],v1[2],v1[3],v1[4],v1[5],v1[6],v1[7]);
        *v = *v1;
    }
    else if(dir==1)
    {
        *v = *v2;
    }
    else if(dir==2)
    {
        *v = *v3;
    }
    else
    {
        *v = *v4;
    }

}
void RegisterBankVector::writeVector(int dir_rc,unsigned char* v,bool we_v)
{
    if(we_v)
    {
        if(dir_rc==0)
            *v1 = *v;
        else if(dir_rc==1)
            *v2 = *v;
        else if(dir_rc==2)
            *v3 = *v;
        else
            *v4 = *v;
    }
}
