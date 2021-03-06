#include "instructionmem.h"

InstructionMem::InstructionMem()
{
    init_mem("/home/sebastian95/QtWorkspace/VectorialProcessor/Files/Instructions.txt");


}

void InstructionMem:: getInstruction(int dir, bool *instruction)
{
    for(int y = 31 ; y > -1 ; y = y-1)
    {
        instruction[y] = mem[dir*8 + y];
    }

}

void InstructionMem::init_mem(const char *filename)
{

    int string_size, read_size;
    FILE *handler = fopen(filename, "r");
    if (handler)
    {
        unsigned char * buffer;
        // Seek the last byte of the file
        fseek(handler, 0, SEEK_END);
        // Offset from the first to the last byte, or in other words, filesize
        string_size = ftell(handler);
        size = string_size;
        // go back to the start of the file
        rewind(handler);

        // Allocate a string that can hold it all
        buffer = (unsigned char*) malloc(sizeof(unsigned char) * (string_size + 1) );

        // Read it all in one operation
        read_size = fread(buffer, sizeof(unsigned char), string_size, handler);

        // fread doesn't set it so put a \0 in the last position
        // and buffer is now officially a string
        buffer[string_size] = '\0';
        printf("\nThe size of the instructions mem is %d \n",string_size);
       // printf("%s \n",buffer);
        if (string_size != read_size)
        {
            //printf("%s \n","Error");
            // Something went wrong, throw away the memory and set
            // the buffer to NULL
            free(buffer);
            buffer = NULL;
        }
        mem  = new bool[size];
        for(int x = 0; x< size ; x++)
        {
            if(buffer[x] == '0')
                mem[x] = false;
            else
                mem[x] = true;

        }



        // Always remember to close the file.
        fclose(handler);

    }
}
