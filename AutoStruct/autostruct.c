#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSTR 20

typedef struct automobile
{
    char *marca;
    int cilindrata;
    int anno;
    char *cognome;
    char *nome;
}Automobile;

void *xmalloc (size_t nbytes);
Automobile **fill_array(int *elements);
Automobile *new_auto();
char *leggi_stringa();

int main (void){
    Automobile **autosalone;
    int num;
    autosalone=fill_array(&num);
    int i;
    for(i=0; i<num; i++){
        printf("marca:%s cilindrata:%d anno:%d cognome:%s nome:%s", autosalone[i]->marca, autosalone[i]->cilindrata, autosalone[i]->anno, autosalone[i]->cognome, autosalone[i]->nome);
    }

    return 0;
}

Automobile **fill_array(int *elements){
    int n, i;
    Automobile **ap;
    printf("quante auto vuoi inserire? ");
    scanf("%d", &n);
    while ((getchar()) != '\n');
    n=2;
    ap=xmalloc(sizeof(Automobile *)*n);
    for (i=0; i<n; i++){
        ap[i]=new_auto();
    }
    *elements=n;
    return ap;
}

Automobile *new_auto(){
    Automobile *na;
    na=xmalloc(sizeof(Automobile));
    printf("CREAZIONE AUTO\n");
    printf("marca: ");
    na->marca=leggi_stringa();
    printf("cilindrata: ");
    scanf("%d", &(na->cilindrata));
    while ((getchar()) != '\n');
    printf("anno immatricolazione: ");
    scanf("%d", &(na->anno));
    while ((getchar()) != '\n');
    printf("cognome proprietario: ");
    na->cognome=leggi_stringa();
    printf("nome proprietario: ");
    na->nome=leggi_stringa();
    return na;
}

char *leggi_stringa(){
    char *s;
    s=xmalloc(MAXSTR+1);
    fgets(s,MAXSTR+1,stdin);
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
