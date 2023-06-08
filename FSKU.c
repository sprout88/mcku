#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv){

    unsigned int SIZE_STORAGE = 32*1024; //32KB mem
    unsigned int SIZE_BLOCK = 512;
    unsigned int offset_SUPER = SIZE_BLOCK*0;
    unsigned int offset_IBMAP = SIZE_BLOCK;
    unsigned int offset_DBMAP = SIZE_BLOCK+256;
    unsigned int offset_INODE1 = SIZE_BLOCK*2;
    unsigned int offset_INODE2 = SIZE_BLOCK*3;
    unsigned int offset_DBLOCK = SIZE_BLOCK*4;

    typedef struct _inode{
        unsigned int fsize;
        unsigned int blocks;
        unsigned int dptr;
        unsigned int iptr;
    }inode;
    
    char* storage = (char*)malloc(SIZE_STORAGE); //char=1byte

    memset(storage,'1',SIZE_STORAGE); // init whole storage blocks with nulchar


    /* init super */
    for(unsigned int i=0;i<offset_SUPER+SIZE_BLOCK;i++){
        *(storage+i)='S';
        printf("%c",*(storage+i));
    }

    /* init super */
    for(unsigned int i=0;i<offset_SUPER+SIZE_BLOCK;i++){
        *(storage+i)='S';
        printf("%c",*(storage+i));
    }

    /*print whole memory*/
    for(unsigned int i=0;i<SIZE_STORAGE;i++){
        printf("%c",storage[i]);
    }
    printf("\n");
    
    free(storage);


    return 0;
}