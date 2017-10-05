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
/**
 * @brief PipeFetchDeco::getOpcode
 * @param bus Receives a bool[4] pointer
 */
void PipeFetchDeco:: getOpcode(bool* bus)
{
    bus[0] = reg[28];
    bus[1] = reg[29];
    bus[2] = reg[30];
    bus[2] = reg[31];
}
/** Returns the type of operators (vector-scalar)
 * @brief PipeFetchDeco::getData
 * @param bus receives 2 bits
 */
void PipeFetchDeco::getData(bool* bus)
{
    bus[0] = reg[26];
    bus[1] = reg[27];
}
/** Returns the instruction format
 * @brief PipeFetchDeco::getF
 * @param bus
 * Receives a bit
 */
void PipeFetchDeco::getF(bool* bus)
{
    bus[0]=reg[25];
}
/** Receives the condition of the instruction
 * @brief PipeFetchDeco::getCond
 * @param bus
 */
void PipeFetchDeco::getCond(bool* bus)
{
    bus[0] = reg[24];
    bus[1] = reg[23];
}
void PipeFetchDeco::getra(bool* bus)
{
    bus[0] = reg[19];
    bus[1] = reg[20];
}
void PipeFetchDeco::getrb(bool* bus)
{
    bus[0] = reg[17];
    bus[1] = reg[18];
}
void PipeFetchDeco::getRa(bool* bus)
{
    bus[0] = reg[19];
    bus[1] = reg[20];
}
void PipeFetchDeco::getRb(bool* bus)
{
    bus[0] = reg[17];
    bus[1] = reg[18];
}
void PipeFetchDeco::getRc(bool* bus)
{
    bus[0] = reg[21];
    bus[1] = reg[22];
}

void PipeFetchDeco::getImm(bool* bus)
{
    bus[0] = reg[0];
    bus[1] = reg[1];
    bus[2] = reg[2];
    bus[3] = reg[3];
    bus[4] = reg[4];
    bus[5] = reg[5];
    bus[6] = reg[6];
    bus[7] = reg[7];
    bus[8] = reg[8];
    bus[9] = reg[9];
    bus[10] = reg[10];
    bus[11] = reg[11];
    bus[12] = reg[12];
    bus[13] = reg[13];
    bus[14] = reg[14];
    bus[15] = reg[15];
    bus[16] = reg[16];
    bus[17] = reg[17];
    bus[18] = reg[18];
    bus[19] = reg[19];
}
