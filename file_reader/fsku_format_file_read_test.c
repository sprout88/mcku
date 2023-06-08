#include <stdio.h>

int main(int argc,char* argv[]){
    
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
        printf("%s %s %d\n",line_data.filename,line_data.iocommand,line_data.filelen);
    }
    

    fclose(file);

    return 0;
}