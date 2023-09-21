#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ARR_SIZE 4
#define STR_LEN 30


int primadi(char *fname, char *spartiacque, char *a[], int sizea);
void fill_array(char *a[]);
char *leggi_stringa();
void *xmalloc (size_t nbytes);


int main(void){
    char *a[ARR_SIZE];
    char *spartiacque;
    char *fname="prova.txt";
    int n=0;
    printf("RIEMPIMENTO ARRAY\n");
    fill_array(a);

    printf("\nInserisci la stringa spartiacque: ");
    spartiacque=leggi_stringa();

    n=primadi(fname, spartiacque, a, ARR_SIZE);
    printf("numero di elementi minori della stringa spartiacque = %d\n", n);
    return 0;
}

void fill_array(char *a[]){
    int i;
    for (i=0; i<ARR_SIZE; i++){
        printf("Inserisci elemento %d: ", i+1);
        a[i]=leggi_stringa();
    }
}

char *leggi_stringa(){
    char *s;
    s=xmalloc(STR_LEN+1);
    fgets(s, STR_LEN+1, stdin);
    return s;
}

void *xmalloc (size_t nbytes){
    void *result;
    result=malloc(nbytes);
    if (result==NULL){
        printf("Malloc Fallito!");
        exit(-1);
    }
    return result;
}

int primadi(char *fname, char *spartiacque, char *a[], int sizea){
    FILE *fp;
    int n=0, i;
    fp=fopen(fname, "w");
    if (fp==NULL){
        fprintf(stderr, "Errore apertura in scrittura\n");
        exit(2);
    }
    for (i=0; i<sizea; i++){
        if (strcmp(a[i], spartiacque)<0){
            fprintf(fp ,"%s", a[i]);
            n++;
        }
    }
    fclose(fp);
    return n;
} 