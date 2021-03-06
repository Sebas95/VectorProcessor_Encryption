#include "parser.h"

Parser::Parser()
{

}

int Parser::getIntFromChar(char c)
{
    if (c == '1')
        return 1;
    if (c == '2')
        return 2;
    if (c == '3')
        return 3;
    if (c == '4')
        return 4;

}

void
Parser::ProcessInstructions(int image_size){
    FILE *archivo;

    char caracteres[100];

    archivo = fopen("/home/sebastian95/QtWorkspace/VectorialProcessor/Files/RawInstructions.txt","r+");

    if (archivo == NULL)
        exit(1);

    FILE * pFile;
    bool entro_repeat = false;
    int replicated_instr=0;
    char* instructions_replicated_buffer = new char[100*32]();
    int index_replicated = 0;
    pFile = fopen ("/home/sebastian95/QtWorkspace/VectorialProcessor/Files/Instructions.txt", "wb");
    int unrolling=0;
    while (feof(archivo) == 0)
    {
        fgets(caracteres,100,archivo);
        char* token = strtok(caracteres, "( ) , " );
        bool comment = false;
        bool macro = false;
        char* instruction = new char[32]();
        bool inmediato = false;
        bool* instr_mem = new bool();
        int iteration=0;
        char* temp = new char[2]();
        char* imm = new char[17]();
        fillImm(imm);

        while (token != NULL)
          {
            if(token[0] == '/')
            {
                comment = true;
                printf (" %s ","\n");
            }
            if(strncmp(token ,"-repeat",7) == 0)
            {
                macro = true;
                entro_repeat = true;
            }
            //-u
           if((token[0] == '-' ) && (token[1] == 'u'))

                unrolling = getIntFromChar(token[2]);


            if(isImm(token)) inmediato = true;
            if(!comment && !macro)
            {
                AddOpcode(token,instruction,instr_mem);
                AddDataType(token,instruction);
                AddCond(token,instruction);
                printf (" %s ",token);
                if (!instr_mem[0])
                {
                    if(iteration == 3) AddOperand(token,instruction);
                    if(iteration == 4) AddOperand(token,instruction);
                    if(iteration == 5)
                    {
                        imm[9] = token[1];
                        imm[10] = token[2];
                        imm[11] = token[3];
                        imm[12] = token[4];
                        imm[13] = token[5];
                        imm[14] = token[6];
                        imm[15] = token[7];
                        imm[16] = token[8];
                        AddOperand(token,instruction);
                    }
                }
                else //si es un store que es diferente
                {
                    if(iteration == 3) //rc
                    {
                        temp[0] = token[0];
                        temp[1] = token[1];
                        strcat(instruction, "00"); //unused RC en strv and strs
                    }
                    if(iteration == 4) //ra
                        AddOperand(token,instruction); //ra place
                    if(iteration == 5) //rb
                    {
                        imm[9] = token[1];
                        imm[10] = token[2];
                        imm[11] = token[3];
                        imm[12] = token[4];
                        imm[13] = token[5];
                        imm[14] = token[6];
                        imm[15] = token[7];
                        imm[16] = token[8];

                        AddOperand(temp,instruction); //ra place
                    }
                }
            }
            token = strtok (NULL, "(), ");
            iteration++;
          }
          if(inmediato)
          {
              instruction[6]='1';
              strcat(instruction, imm);
          }
          else
          {
              instruction[6]='0';
              strcat(instruction, "00000000000000000");
          }
          if((feof(archivo) == 0) && !macro)
          {
              printf (" La instrucción es: %s\n\n",instruction);
              fwrite (instruction , sizeof(char), 32, pFile);
              if(entro_repeat) //copiando enel bufer de replicas
              {
                  for(int i = 0; i< 32;i++)
                  {
                    instructions_replicated_buffer[index_replicated+i] = instruction[i];
                  }
                  index_replicated = index_replicated +32;
                  replicated_instr++;
              }
          }


    }

    for(int y = 0 ; y< image_size/(2*unrolling) -1 ; y++)
    {
        fwrite (instructions_replicated_buffer , sizeof(char), replicated_instr*32, pFile);
        //printf (" La instrucción es: %s\n\n",instructions_replicated_buffer);

    }
    free(instructions_replicated_buffer);


    fclose (pFile);
    fclose(archivo);
}

void Parser::fillImm(char* imm)
{
    for (int i=0 ; i<17 ; i++)
        imm[i] = '0';
}

void Parser::AddDataType(char* data_type,char* instruction)
{
    if(strncmp (data_type , "vv", 2 ) == 0)
    {
        strcat(instruction, "00 ");
    }
    if(strncmp (data_type , "sv", 2 ) == 0)
    {
        strcat(instruction, "01 ");
    }
    if(strncmp (data_type , "ss", 2 ) == 0)
    {
        strcat(instruction, "10 ");
    }
    if(strncmp (data_type , "m", 1 ) == 0)
    {
        strcat(instruction, "11 ");
    }
}
void Parser::AddOpcode(char* opcode,char* instruction, bool* instr_mem)
{

    if(strncmp ( opcode , "ldv", 3 ) == 0)
    {
        strcpy(instruction, "0000");
    }
    if(strncmp ( opcode , "strv", 4 ) == 0)
    {
        instr_mem[0] = true;
        strcpy(instruction, "0001");
    }
    if(strncmp ( opcode , "lds", 3 ) == 0)
    {
        strcpy(instruction, "0010");
    }
    if(strncmp ( opcode , "strs", 4 ) == 0)
    {
         instr_mem[0] = true;
        strcpy(instruction, "0011");
    }
    if(strncmp ( opcode , "add", 3 ) == 0)
        strcpy(instruction, "0100");
    if(strncmp ( opcode , "sub", 3 ) == 0)
        strcpy(instruction, "0101");
    if(strncmp ( opcode , "mult", 3 ) == 0)
        strcpy(instruction, "0110 ");
    if(strncmp ( opcode , "and", 3 ) == 0)
        strcpy(instruction, "0111");
    if(strncmp ( opcode , "or", 2 ) == 0)
        strcpy(instruction, "1000");
    if(strncmp ( opcode , "xor", 3 ) == 0)
        strcpy(instruction, "1001");
    if(strncmp ( opcode , "shr", 3 ) == 0)
        strcpy(instruction, "1010");
    if(strncmp ( opcode , "shl", 3 ) == 0)
        strcpy(instruction, "1011");
    if(strncmp ( opcode , "shrc", 4 ) == 0)
        strcpy(instruction, "1100");
    if(strncmp ( opcode , "shlc", 4 ) == 0)
        strcpy(instruction, "1101");
    if(strncmp ( opcode , "cmp", 3 ) == 0)
        strcpy(instruction, "1110");
}
void Parser::AddCond(char* cond,char* instruction)
{
    if(strncmp ( cond , "eq", 2 ) == 0)
        strcat(instruction, "00");

    if(strncmp ( cond , "ne", 2 ) == 0)
        strcat(instruction, "01");

    if(strncmp ( cond , "nc", 2 ) == 0)
        strcat(instruction, "10");

}

bool Parser::isImm(char* token)
{
    if(token[0] == '#' )
        return true;
    else
        return false;
}

void Parser::AddOperand(char* operand,char* instruction)
{
    if(strncmp (operand , "S0", 2 ) == 0)
        strcat(instruction, "00");
    else if(strncmp (operand , "S1", 2 ) == 0)
        strcat(instruction, "01");
    else if(strncmp (operand , "S2", 2 ) == 0)
        strcat(instruction, "10");
    else if(strncmp (operand , "S3", 2 ) == 0)
        strcat(instruction, "11");

    else if(strncmp (operand , "V0", 2 ) == 0)
        strcat(instruction, "00");
    else if(strncmp (operand , "V1", 2 ) == 0)
        strcat(instruction, "01");
    else if(strncmp (operand , "V2", 2 ) == 0)
        strcat(instruction, "10");
    else if(strncmp (operand , "V3", 2 ) == 0)
        strcat(instruction, "11");
    else
        strcat(instruction, "00");
}

