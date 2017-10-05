#ifndef REGISTERSBANKSCALAR_H
#define REGISTERSBANKSCALAR_H


class RegistersBankScalar
{
private:
    unsigned char* s1;
    unsigned char* s2;
    unsigned char* s3;
    unsigned char* s4;
public:
    RegistersBankScalar();
    void readVector(int dir,unsigned char* s);
    void writeScalar(int dir_rc,unsigned char* s,bool we_s);
};

#endif // REGISTERSBANKSCALAR_H
