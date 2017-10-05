#include "pipefetchdeco.h"

PipeFetchDeco::PipeFetchDeco()
{
    for (int i = 0 ;  i< 32 ; i++)
        reg[i]=0;
}

void PipeFetchDeco::writeReg(bool* reg)
{
    for (int i = 0 ;  i< 32 ; i++)
    {
        this->reg[i]=reg[i];
        std::cout<<reg[i]<<"\n";
    }

}
