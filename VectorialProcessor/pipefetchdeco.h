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

    void getOpcode(bool*);
    void getData(bool*);
    void getF(bool*);
    void getCond(bool*);
    void getra(bool*);
    void getrb(bool*);
    void getRa(bool*);
    void getRb(bool*);
    void getRc(bool*);
    void getImm(bool*);
};

#endif // PIPEFETCHDECO_H
