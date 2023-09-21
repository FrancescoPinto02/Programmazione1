#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

int main(int argc, char* argv[]){
    FILE *fp;
    char str[MAX_LEN+2];
    char* nome_file=argv[1];
    int occ=0;

    fp=fopen(nome_file, "rt");
    if (!fp){
        printf("Errore apertura file!\n");
        exit(1);
    }

    while (fgets(str, MAX_LEN, fp)!=NULL){
        if(str[strlen(str)-1]=='\n'){
            str[strlen(str)-1]='\0';
        }
        if(strcmp(argv[2], str)==0){
            occ++;
        }
    }
    printf("Occorrenze di %s: %d",argv[2],occ);
    return 0;
}