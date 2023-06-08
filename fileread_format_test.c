#include <stdio.h>

int main(int argc,char* argv[]){
    
    FILE* file;
    file = fopen(argv[1],"r");

    int integer;
    float floatingPoint;
    char string[1000];
    fscanf(file,"%d %f %s",&integer,&floatingPoint,string);
    
    printf("Integer : %d\n",integer);
    printf("Floating Point : %f\n",floatingPoint);
    printf("String : %s\n",string);

    fclose(file);

    return 0;
}