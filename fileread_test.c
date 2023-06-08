#include <stdio.h>

int main(int argc, char* argv[]){
    FILE *file;
    char content[1000];

    file = fopen(argv[1],"r"); // return fd

    if(file==NULL){
        printf("no file names");
        return 1;
    }
    while(fscanf(file,"%s",content) != EOF){
        printf("%s ",content);
        printf("\n");
    }
    fclose(file);

    return 0;
}