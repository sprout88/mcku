#include <stdio.h>


int main(int argc, char *argv[]){
    pthread_t p1, p2;
    int rc;
    printf("main: begin\n");
    rc = pthread_create(&p1,NULL,mythread,"A"); assert(rc==0);
    rc = pthread_create(&p2, NULL,mythread,"B"); assert(rc==0);
    rc=pthread_join(p1,NULL); assert(rc==0);
    rc=pthread_join(p2,NULL); assert(rc==0);
    printf("main: end\n")
    printf("hello world!");
    return 0;
}