#include "int_bin_converter.h"
#include <math.h>

Int_Bin_converter::Int_Bin_converter()
{

}
int Int_Bin_converter::convert(bool* reg,int lenght)
{
    int result = 0;
    int exp = lenght-1;
    for (int i = 0; i< lenght ; i++)
    {
        if(reg[i])
            result = result + pow(2,exp);
        exp = exp-1;
    }
    return result;
}


void Int_Bin_converter::printBin(bool* reg,int lenght)
{

    printf("%s"," [ " );
    for (int i = 0; i< lenght ; i++)
    {
        if(reg[i])
            printf("%s", " 1 ");
        else
            printf("%s", " 0 ");

    }
    printf("%s"," ]\n" );

}
