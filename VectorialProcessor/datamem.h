#ifndef DATAMEM_H
#define DATAMEM_H
#include <stddef.h>

class DataMem
{

private:
    unsigned char *mem = NULL;
public:
    DataMem();
    unsigned char getVector(int dir);
};

#endif // DATAMEM_H
