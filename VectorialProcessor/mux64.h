#ifndef MUX64_H
#define MUX64_H
#include <string>
#include <stdio.h>
using namespace std;

class Mux64
{
private:
    string name="";
public:
    Mux64(string);
    unsigned char* multiplex(bool select[], unsigned char* chan0, unsigned char* chan1, unsigned char* chan2);
    unsigned char* multiplex2chan(bool select, unsigned char* chan0, unsigned char* chan1);
};

#endif // MUX64_H
