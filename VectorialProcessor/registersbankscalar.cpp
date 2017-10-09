#include "registersbankscalar.h"
#include <stdio.h>

RegistersBankScalar::RegistersBankScalar()
{
    s1 = new unsigned char[4]();
    s2 = new unsigned char[4]();
    s3 = new unsigned char[4]();
    s4 = new unsigned char[4]();
}


void RegistersBankScalar::readScalar(int dir,unsigned char* s)
{
    if(dir==0)
    {
        *s = *s1;
    }
    else if(dir==1)
    {
        *s = *s2;
    }
    else if(dir==2)
    {
        *s = *s3;
    }
    else
    {
        *s = *s4;
    }

}
void RegistersBankScalar::writeScalar(int dir_rc,unsigned char* s,bool we_s)
{
    if(we_s)
    {
        if(dir_rc==0)
            *s1 = *s;
        else if(dir_rc==1)
        {
            *s2 = *s;
        }
        else if(dir_rc==2)
        {

            *s3 = *s;
            printf("wrote scalar 2 %d \n", *(int*)s3);
        }
        else
            *s4 = *s;
    }
}
