#ifndef MUX32_H
#define MUX32_H
#include <string>
using namespace std;

class Mux32
{

private:
    string name;
public:
    Mux32(string);
    unsigned char* multiplex(bool select,unsigned char chan0[4], unsigned char chan1[4]);
};

#endif // MUX32_H
