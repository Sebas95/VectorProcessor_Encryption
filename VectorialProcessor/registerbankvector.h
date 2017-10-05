#ifndef REGISTERBANKVECTOR_H
#define REGISTERBANKVECTOR_H


class RegisterBankVector
{
public:
    unsigned char* v1;
    unsigned char* v2;
    unsigned char* v3;
    unsigned char* v4;
public:
    RegisterBankVector();
    void readVector(int dir,unsigned char* v);
    void writeVector(int dir_rc,unsigned char* v,bool we_v);
};

#endif // REGISTERBANKVECTOR_H
