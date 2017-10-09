#include "mux64.h"

Mux64::Mux64(string name)
{
     this->name = name;
}

unsigned char* Mux64::multiplex(bool select[],unsigned char* chan0, unsigned char* chan1,unsigned char* chan2)
{
    //printf("Multiplexing : %c %c %c %c %c %c %c %c \n",chan0[0],chan0[1],chan0[2],chan0[3],chan0[4],chan0[5],chan0[6],chan0[7] );
    //printf("Multiplexing : %c %c %c %c %c %c %c %c \n",chan1[0],chan1[1],chan1[2],chan1[3],chan1[4],chan1[5],chan1[6],chan1[7] );
    //printf("Multiplexing : %c %c %c %c %c %c %c %c \n",chan2[0],chan2[1],chan2[2],chan2[3],chan2[4],chan2[5],chan2[6],chan2[7] );
    if(!select[0] && !select[1] )
    {
        return chan0;
    }
    else if( !select[0] && select[1] )
    {
        return chan1;
    }
    else if( select[0] && !select[1] )
    {
        return chan2;
    }
    else
    {
        printf("%s\n", "Error en mux 64" );
        return chan2;
    }

}
unsigned char* Mux64::multiplex2chan(bool select, unsigned char* chan0, unsigned char* chan1)
{
    if(select)
    {
        return chan0;
    }
    else
    {
        return chan1;
    }
}
