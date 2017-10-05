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
    unsigned char* multiplex(bool select[2],unsigned char chan0[8], unsigned char chan1[8],unsigned char chan2[8]);
};

#endif // MUX64_H
