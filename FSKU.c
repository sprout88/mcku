#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv){

    size_t size = 32*1024; //32KB mem
    char* buffer = (char*)malloc(size); //char=1byte


    free(buffer);


    return 0;
}