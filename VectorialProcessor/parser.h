#ifndef PARSER_H
#define PARSER_H

#include <stddef.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>

#include <string.h>
#include <stdbool.h>
#include <assert.h>

class Parser
{
private:
    void AddOpcode(char* opcode, char* instruction, bool* instr_mem);
    void AddDataType(char* data_type,char* instruction);
    bool isImm(char* token);
    void AddCond(char* cond,char* instruction);
    void AddOperand(char* operand,char* instruction);
    void fillImm(char* imm);
    int getIntFromChar(char);
public:


    Parser();
    void ProcessInstructions(int image_size);
};

#endif // PARSER_H
