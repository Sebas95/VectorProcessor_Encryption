#ifndef PC_H
#define PC_H
#include <stddef.h>

class Pc
{
private:
    bool reg[32];
public:
    Pc();
    void readPc(bool*);
};

#endif // PC_H
