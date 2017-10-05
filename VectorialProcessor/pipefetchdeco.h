#ifndef PIPEFETCHDECO_H
#define PIPEFETCHDECO_H
#include <iostream>
#include <stdio.h>
using namespace std;

class PipeFetchDeco
{

private:
    bool reg[32];
public:
    PipeFetchDeco();
    void writeReg(bool*);
};

#endif // PIPEFETCHDECO_H
