#include "datamem.h"
#include "instructionmem.h"

DataMem::DataMem()
{
    mem = new unsigned char[64*MEGA]();

}

void DataMem:: getVector(int dir, unsigned char* vector)
{

    vector[0] = mem[dir+0];
    vector[1] = mem[dir+1];
    vector[2] = mem[dir+2];
    vector[3] = mem[dir+3];
    vector[4] = mem[dir+4];
    vector[5] = mem[dir+5];
    vector[6] = mem[dir+6];
    vector[7] = mem[dir+7];

}

void DataMem:: getScalar(int dir, unsigned char* vector)
{
    vector[0] = mem[dir+0];
    vector[1] = mem[dir+1];
    vector[2] = mem[dir+2];
    vector[3] = mem[dir+3];
}

void DataMem:: write(bool WE[], unsigned char* direction, unsigned char* Din32, unsigned char* Din64)
{
    int dir = *(int*)direction;

   if(WE[0])
   {
       mem[dir+0] = Din32[0];
       mem[dir+1] = Din32[1];
       mem[dir+2] = Din32[2];
       mem[dir+3] = Din32[3];
   }
   if(WE[1])
   {
       mem[dir+0] = Din64[0];
       mem[dir+1] = Din64[1];
       mem[dir+2] = Din64[2];
       mem[dir+3] = Din64[3];
       mem[dir+4] = Din64[4];
       mem[dir+5] = Din64[5];
       mem[dir+6] = Din64[6];
       mem[dir+7] = Din64[7];
   }

}
