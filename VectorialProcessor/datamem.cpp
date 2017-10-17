#include "datamem.h"


DataMem::DataMem()
{
    init_mem("/home/sebastian95/QtWorkspace/VectorialProcessor/Files/original.data");
    Parser* parser = new Parser();
    int image_size = size-reservedSpaceForVars;
    parser->ProcessInstructions(image_size);
}

void DataMem:: getVector(int dir, unsigned char* vector)
{

    vector[0] = mem[dir+0];
    vector[1] = mem[dir+1];
    vector[2] = mem[dir+2];
    vector[3] = mem[dir+3];
    vector[4] = mem[dir+4];
    vector[5] = mem[dir+5];
    vector[6] = mem[dir+6];
    vector[7] = mem[dir+7];


}

void DataMem:: getScalar(int dir, unsigned char* vector)
{
    vector[0] = mem[dir+0];
    vector[1] = mem[dir+1];
    vector[2] = mem[dir+2];
    vector[3] = mem[dir+3];
}

void DataMem:: write(bool* WE, unsigned char* direction, unsigned char* Din32, unsigned char* Din64)
{
    int dir = *(int*)direction;

   if(WE[0])
   {
       mem[dir+0] = Din32[0];
       mem[dir+1] = Din32[1];
       mem[dir+2] = Din32[2];
       mem[dir+3] = Din32[3];
      // printf("char : .%c::::::::::::::::::",mem[dir+0]);
   }
   if(WE[1])
   {
       mem[dir+0] = Din64[0];
       mem[dir+1] = Din64[1];
       mem[dir+2] = Din64[2];
       mem[dir+3] = Din64[3];
       mem[dir+4] = Din64[4];
       mem[dir+5] = Din64[5];
       mem[dir+6] = Din64[6];
       mem[dir+7] = Din64[7];


   }

}
void DataMem::init_mem(const char *filename)
{


    int  read_size;
    FILE *handler = fopen(filename, "r");
    if (handler)
    {
        // Seek the last byte of the file
        fseek(handler, 0, SEEK_END);
        // Offset from the first to the last byte, or in other words, filesize
        string_size = ftell(handler);
        size = string_size + reservedSpaceForVars;
        // go back to the start of the file
        rewind(handler);

        // Allocate a string that can hold it all
        mem = (unsigned char*) malloc(sizeof(unsigned char) * (size+ 1) );

        // Read it all in one operation
        read_size = fread((mem+reservedSpaceForVars), sizeof(unsigned char), string_size, handler);

        // fread doesn't set it so put a \0 in the last position
        // and buffer is now officially a string
        mem[string_size] = '\0';
        printf("\n\n The size of the image is %d \n",string_size);
        if (string_size != read_size)
        {
            //printf("%s \n","Error");
            // Something went wrong, throw away the memory and set
            // the buffer to NULL
            free(mem);
            mem = NULL;
        }




        // Always remember to close the file.
        fclose(handler);
     }



}

void DataMem::write_image(){
    FILE * pFile;

    pFile = fopen ("/home/sebastian95/QtWorkspace/VectorialProcessor/Files/myfile.data", "wb");
    fwrite ((mem+reservedSpaceForVars) , sizeof(char), string_size, pFile);
    fclose (pFile);
}
