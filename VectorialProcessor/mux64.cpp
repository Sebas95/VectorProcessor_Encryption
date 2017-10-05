#include "mux64.h"

Mux64::Mux64(string name)
{
     this->name = name;
}

unsigned char* Mux64::multiplex(bool select[2],unsigned char chan0[8], unsigned char chan1[8],unsigned char chan2[8])
{
    if(!select[1] && !select[0] )
    {
        return chan0;
    }
    else if( !select[1] && select[0] )
    {
        return chan1;
    }
    else if( select[1] && !select[0] )
    {
        return chan2;
    }
    else
    {
        printf("%s\n", "Error en mux 64" );
        return chan2;
    }

}
