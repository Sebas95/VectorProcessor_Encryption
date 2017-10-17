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
        s[0] = s1[0];
        s[1] = s1[1];
        s[2] = s1[2];
        s[3] = s1[3];
    }
    else if(dir==1)
    {
        s[0] = s2[0];
        s[1] = s2[1];
        s[2] = s2[2];
        s[3] = s2[3];
    }
    else if(dir==2)
    {
        s[0] = s3[0];
        s[1] = s3[1];
        s[2] = s3[2];
        s[3] = s3[3];
    }
    else
    {
        s[0] = s4[0];
        s[1] = s4[1];
        s[2] = s4[2];
        s[3] = s4[3];
    }

}
void RegistersBankScalar::writeScalar(int dir_rc,unsigned char* s,bool we_s)
{
    if(we_s)
    {
        if(dir_rc==0)
        {
            s1[0] = s[0];
            s1[1] = s[1];
            s1[2] = s[2];
            s1[3] = s[3];
        }
        else if(dir_rc==1)
        {
            s2[0] = s[0];
            s2[1] = s[1];
            s2[2] = s[2];
            s2[3] = s[3];

        }
        else if(dir_rc==2)
        {

            s3[0] = s[0];
            s3[1] = s[1];
            s3[2] = s[2];
            s3[3] = s[3];

          //  printf("wrote scalar S2 %d \n", *(int*)s3);
        }
        else
        {
            s4[0] = s[0];
            s4[1] = s[1];
            s4[2] = s[2];
            s4[3] = s[3];

        }
    }
}
