#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv){

    unsigned int size = 32*1024; //32KB mem
    char* buffer = (char*)malloc(size); //char=1byte

    memset(buffer,'1',size);

    for(size_t i=0;i<size;i++){
        printf("%c",buffer[i]);
    }
    printf("\n");

    free(buffer);


    return 0;
}