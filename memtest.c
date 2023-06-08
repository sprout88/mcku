#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv){

    int SIZE = 100;

    char* storage = (char*)malloc(SIZE);

    memset(storage,'1',SIZE);

    for(int i=0;i<SIZE;i++){
        printf("%c",storage[i]);
    }

    return 0;
}