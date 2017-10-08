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
       // std::cout<<reg[i]<<"\n";
    }

}
/**
 * @brief PipeFetchDeco::getOpcode
 * @param bus Receives a bool[4] pointer
 */
void PipeFetchDeco:: getOpcode(bool* bus)
{
    bus[3] = reg[31-28];
    bus[2] = reg[31-29];
    bus[1] = reg[31-30];
    bus[0] = reg[31-31];
}
/** Returns the type of operators (vector-scalar)
 * @brief PipeFetchDeco::getData
 * @param bus receives 2 bits
 */
void PipeFetchDeco::getData(bool* bus)
{
    bus[1] = reg[31-26];
    bus[0] = reg[31-27];
}
/** Returns the instruction format
 * @brief PipeFetchDeco::getF
 * @param bus
 * Receives a bit
 */
void PipeFetchDeco::getF(bool* bus)
{
    bus[0]=reg[31-25];
}
/** Receives the condition of the instruction
 * @brief PipeFetchDeco::getCond
 * @param bus
 */
void PipeFetchDeco::getCond(bool* bus)
{
    bus[1] = reg[31-23];
    bus[0] = reg[31-24];
}
void PipeFetchDeco::getra(bool* bus)
{
    bus[1] = reg[31-19];
    bus[0] = reg[31-20];
}
void PipeFetchDeco::getrb(bool* bus)
{
    bus[1] = reg[31-17];
    bus[0] = reg[31-18];
}
void PipeFetchDeco::getRa(bool* bus)
{
    bus[1] = reg[31-19];
    bus[0] = reg[31-20];
}
void PipeFetchDeco::getRb(bool* bus)
{
    bus[1] = reg[31-17];
    bus[0] = reg[31-18];
}
void PipeFetchDeco::getRc(bool* bus)
{
    bus[1] = reg[31-21];
    bus[0] = reg[31-22];
}

void PipeFetchDeco::getImm(bool* bus)
{
    bus[16] = reg[31-0];
    bus[15] = reg[31-1];
    bus[14] = reg[31-2];
    bus[13] = reg[31-3];
    bus[12] = reg[31-4];
    bus[11] = reg[31-5];
    bus[10] = reg[31-6];
    bus[9] = reg[31-7];
    bus[8] = reg[31-8];
    bus[7] = reg[31-9];
    bus[6] = reg[31-10];
    bus[5] = reg[31-11];
    bus[4] = reg[31-12];
    bus[3] = reg[31-13];
    bus[2] = reg[31-14];
    bus[1] = reg[31-15];
    bus[0] = reg[31-16];

}
