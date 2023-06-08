#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv){

    unsigned int SIZE_STORAGE = 32*1024; //32KB mem
    unsigned int SIZE_SUPER = 512;
    char* storage = (char*)malloc(SIZE_STORAGE); //char=1byte

    memset(storage,'\0',SIZE_STORAGE);

    //printf("size : %u\n",sizeof(SIZE_STORAGE));

    /*print whole memory*/
    // for(unsigned int i=0;i<SIZE_STORAGE;i++){
    //     printf("%c",storage[i]);
    // }
    // printf("\n");

    /* print super */
    for(unsigned int i=0;i<SIZE_SUPER;i++){
        printf("%c",storage[i]);
    }

    free(storage);


    return 0;
}