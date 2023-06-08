#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv){

    unsigned int SIZE_STORAGE = 32*1024; //32KB mem
    unsigned int SUPER = 512;
    char* buffer = (char*)malloc(SIZE_STORAGE); //char=1byte

    memset(buffer,'0',SIZE_STORAGE);

    //printf("size : %u\n",sizeof(SIZE_STORAGE));

    //print memory
    for(unsigned int i=0;i<SIZE_STORAGE;i++){
        printf("%c",buffer[i]);
    }
    printf("\n");

    free(buffer);


    return 0;
}