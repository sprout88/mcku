#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

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
        *(storage+i)='0'; // fill super block with 0
    }
    *(storage+offset_IBMAP)='0'; // 삭제 비트 나중에 0으로 수정
    *(storage+offset_IBMAP+1)='0'; // 배드 비트 나중에 0으로 수정

    /* init i-bmap*/
    for(unsigned int i=offset_DBMAP;i<offset_DBMAP+SIZE_BLOCK;i++){
        *(storage+i)='0'; // fill super block with 0
    }
    *(storage+offset_DBMAP)='1'; // root dir bit

    /* init iblock0*/
    for(unsigned int i=offset_INODE0;i<offset_INODE0+SIZE_BLOCK;i++){
        *(storage+i)='0'; // fill iblock0 z
    }
    /* init root directory's inode */
    *(storage+offset_INODE0+2)='R';
    inode* inode_root = malloc(sizeof(inode));
    inode_root->fsize = 4*61;
    inode_root->blocks = 1;
    inode_root->dptr = 0;
    inode_root->iptr = 0;
    memcpy(storage+offset_INODE0,inode_root,sizeof(inode_root));

    /*memcpy test*/
    // char* src = malloc(sizeof(char)*8);
    // for(int i=0;i<sizeof(src);i++){
    //     *(src+i)='c';
    // }
    // memcpy(storage+offset_INODE0,src,sizeof(src));

    /*set root directory's inode's dptr table*/
    
    /* init iblock1*/
    for(unsigned int i=offset_INODE1;i<offset_INODE1+SIZE_BLOCK;i++){
        *(storage+i)='0'; // fill iblock1 o
    }

    /* file reader */
    FILE* file;
    file = fopen(argv[1],"r");

    char line_buffer[100];

    typedef struct _file_ent{
        char filename[5];
        char iocommand[5];
        int filelen;
    }file_ent;

    file_ent line_data;
    while(fscanf(file,"%s %s %d\n",line_data.filename,line_data.iocommand,&line_data.filelen)==3){
        printf("%s %s %d\n",line_data.filename,line_data.iocommand,line_data.filelen);\
        /*write op*/
        if(line_data.iocommand[0]=='w'){
            //printf("write!\n");
            /* init i-bmap*/
            for(unsigned int i=offset_IBMAP;i<offset_DBMAP+SIZE_BLOCK;i++){
                // if(*(storage+offset_DBMAP+i)!='0'){
                if(*(storage+offset_DBMAP+i)=='0'){    
                    //printf("%d\n",i);
                   *(storage+offset_INODE1+i)=line_data.filename[0];
                   break;
                }else{
                    printf("fail\n");
                }
            }
        }
        if(line_data.iocommand[0]=='r'){
            printf("Success\n");
        }
        if(line_data.iocommand[0]=='d'){
            printf("Success\n");
        }
    }
    

    /*print whole memory*/
    for(unsigned int i=0;i<SIZE_STORAGE;i++){
        printf("%x ",storage[i]);
    }
    printf("\n");
    
    free(storage);
    fclose(file);


    return 0;
}