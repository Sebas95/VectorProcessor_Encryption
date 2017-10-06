#ifndef DATAMEM_H
#define DATAMEM_H
#include <stddef.h>

class DataMem
{

private:
    unsigned char *mem = NULL;
public:
    DataMem();
    void getVector(int dir, unsigned char* vector);
    void getScalar(int dir, unsigned char* vector);
    void write(bool WE[], unsigned char* direction, unsigned char* Din32, unsigned char* Din64);
};

#endif // DATAMEM_H
