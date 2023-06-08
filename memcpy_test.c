#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int* test_mem = malloc(sizeof(int)*100);

    
    for(int i=0;i<100;i++){
        *(test_mem+i)=i;
    }

    // for(int i=0;i<100;i++){
    //     printf("%d ",*(test_mem+i));
    // }

    int* zero_mem = malloc(sizeof(int)*8);
    for(int i=0;i<8;i++){
        *(zero_mem+i)=0;
    }
    memcpy(test_mem,zero_mem,sizeof(int)*8);

    printf("###\n");

    for(int i=0;i<100;i++){
        printf("%d ",*(test_mem+i));
    }

    free(test_mem);
    free(zero_mem);
}