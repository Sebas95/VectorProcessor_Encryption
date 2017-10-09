#ifndef INT_BIN_CONVERTER_H
#define INT_BIN_CONVERTER_H
#include <stdio.h>

class Int_Bin_converter
{
public:
    Int_Bin_converter();
    int convert(bool*,int lenght);
    void printBin(bool*,int lenght);
};

#endif // INT_BIN_CONVERTER_H
