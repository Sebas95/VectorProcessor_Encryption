#include "mux64.h"

Mux64::Mux64(string name)
{
     this->name = name;
}

unsigned char* Mux64::multiplex(bool select[],unsigned char* chan0, unsigned char* chan1,unsigned char* chan2)
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
