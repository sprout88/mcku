#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv){

    unsigned int SIZE_STORAGE = 32*1024; //32KB mem
    unsigned int SIZE_BLOCK = 512;
    unsigned int offset_SUPER = 0;
    unsigned int offset_IBMAP = SIZE_BLOCK;
    unsigned int offset_DBMAP = SIZE_BLOCK+256;
    unsigned int offset_INODE0 = SIZE_BLOCK*2;
    unsigned int offset_INODE1 = SIZE_BLOCK*3;
    unsigned int offset_DBLOCK = SIZE_BLOCK*4;

    typedef struct _inode{
        unsigned int fsize;
        unsigned int blocks;
        unsigned int dptr;
        unsigned int iptr;
    }inode;
    
    char* storage = (char*)malloc(SIZE_STORAGE); //char=1byte

    memset(storage,'\0',SIZE_STORAGE); // init whole storage blocks with nulchar

    printf("### FCKU ###\n");

    /* init super */
    for(unsigned int i=offset_SUPER;i<SIZE_BLOCK;i++){
        *(storage+i)='0'; // fill super block with 0
    }
    /* init i-bmap*/
    for(unsigned int i=offset_IBMAP;i<offset_IBMAP+SIZE_BLOCK;i++){
        *(storage+i)='b'; // fill super block with 0
    }
    *(storage+offset_IBMAP)='R'; // 삭제 비트 나중에 0으로 수정
    *(storage+offset_IBMAP+1)='B'; // 배드 비트 나중에 0으로 수정

    /* init i-bmap*/
    for(unsigned int i=offset_DBMAP;i<offset_DBMAP+SIZE_BLOCK;i++){
        *(storage+i)='r'; // fill super block with 0
    }
    *(storage+offset_DBMAP)='1'; // root dir bit
    

    /*print whole memory*/
    for(unsigned int i=0;i<SIZE_STORAGE;i++){
        printf("%c",storage[i]);
    }
    printf("\n");
    
    free(storage);


    return 0;
}