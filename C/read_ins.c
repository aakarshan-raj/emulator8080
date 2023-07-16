#include <stdio.h>
#include <stdlib.h>

int all_hex(unsigned char *,int);

   int main (int argc, char**argv)    
   {    
    FILE *f= fopen(argv[1], "rb");    
    if (f==NULL)    
    {    
        printf("error: Couldn't open %s\n", argv[1]);    
        exit(1);    
    }    

    //Get the file size and read it into a memory buffer    
    fseek(f, 0L, SEEK_END);    
    int fsize = ftell(f);    
    fseek(f, 0L, SEEK_SET);    

    unsigned char *buffer=malloc(fsize);    

    fread(buffer, fsize, 1, f);    
    fclose(f);    

    int pc = 0;    
    while(pc<=fsize){
       pc += all_hex(buffer,pc);
    }
    return 0;    
   }    


   int all_hex(unsigned char *buffer,int pc){
      int incre = 1;
        unsigned char* opcode = &buffer[pc];
           switch (*opcode)
           {
           case 0x00:
               printf("NOP\n");
            break;
           
           pc++;
      }
      return incre;
   }