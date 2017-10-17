#ifndef SIGNALS
#define SIGNALS




int pc=0;
bool* instruction = new bool[32]();

bool* Data = new bool[2]();
bool*opcode = new bool[4]();
bool* F = new bool[1]();
bool* Cond = new bool[2]();
bool* ra= new bool[2]();
bool* rb= new bool[2]();
bool* Ra= new bool[2]();
bool* Rb= new bool[2]();
bool* Rc= new bool[2]();
bool* Imm= new bool[17]();
int* immExt = new int[1]();
unsigned char* content_ra = new unsigned char[4](); //4 byte int
unsigned char* content_rb = new unsigned char[4](); //4 byte int
unsigned char* content_Ra = new unsigned char[8](); //8 byte vector
unsigned char* content_Rb = new unsigned char[8](); //8 byte vector


bool* Z = new bool[1]();
bool* C = new bool[1]();
unsigned char* muxbResult = new unsigned char[4]();
unsigned char* muxAResult = new unsigned char[8]();
unsigned char* aluResult32 = new unsigned char[4]();
unsigned char* aluResult64 = new unsigned char[8]();
unsigned char* memOut32 = new unsigned char[4]();
unsigned char* memOut64 = new unsigned char[8]();
unsigned char* zero = new unsigned char[8]();
unsigned char* replicatedScalar = new unsigned char[8]();

unsigned char* sel_dat_out = new unsigned char[4]();
unsigned char* sel_vec_out = new unsigned char[8]();


#endif // SIGNALS

