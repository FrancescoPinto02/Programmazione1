#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20
#define NUM_STR 20

int main(int argc, char* argv[]){
    FILE *fp;
    char str[MAX_LEN+2];
    char* nome_file=argv[1];
    const char* mode1="o";
    const char* mode2="s";
    int occ=0, nstr=0, i=0, j=0;
    char *arr_str[20];

    fp=fopen(nome_file, "rt");
        if (!fp){
            printf("Errore apertura file!\n");
            exit(1);
        }

    if(strcmp(argv[2],mode1)==0){
        while (fgets(str, MAX_LEN, fp)!=NULL){
            if(str[strlen(str)-1]=='\n'){
                str[strlen(str)-1]='\0';
            }
            if(strcmp(argv[3], str)==0){
                occ++;
            }
        }
        printf("Occorrenze di %s: %d",argv[3],occ);
        fclose(fp);
    }
    else if(strcmp(argv[2],mode2)==0){
        while (fgets(str, MAX_LEN, fp)!=NULL){
            if(str[strlen(str)-1]=='\n'){
                str[strlen(str)-1]='\0';
            }
            printf("str:%s\n",str);
            arr_str[nstr]=strcpy(arr_str[0],str);
            nstr++;
            printf("nstr:%d str:%s\n",nstr,arr_str[nstr]);
        }
        fclose(fp);
        for(i=0; i<nstr-2; i++){
            for(j=0; j<nstr-2; j++){
                if(strcmp(arr_str[j], arr_str[i])<0){
                    strcpy(str, arr_str[j]);
                    strcpy(arr_str[j], arr_str[i]);
                    strcpy(arr_str[i], str);
                }
            }
        }
        fp=fopen("ordinato.txt","wt");
        for(i=0; i<nstr-1; i++){
            fscanf(fp,"%s",arr_str[i]);
        }
        fclose(fp);
    }
    return 0;
}