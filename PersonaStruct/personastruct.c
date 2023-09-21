#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 30
#define MAXCF 16

typedef struct persona
{
    char *nome;
    char *cognome;
    char cod_fis[MAXCF+1];
}persona;

void *xmalloc (size_t nbytes);
persona *new_persona();
int controllo_cf(char codice_fiscale[]);
char *leggi_stringa();


int main (void){
    persona *p1;
    p1=new_persona();
    printf("nome: %sCognome: %sCodice Fiscale: %s", p1->nome, p1->cognome, p1->cod_fis);
    return 0;
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

persona *new_persona(){
    persona *p=xmalloc(sizeof(persona));
    printf("CREAZIONE NUOVA PERSONA\n");
    printf("Nome: ");
    p->nome=leggi_stringa();
    printf("Cognome: ");
    p->cognome=leggi_stringa();
    do{
        printf("Codice Fiscale: ");
        gets(p->cod_fis);
    }while(!controllo_cf(p->cod_fis));
    printf("PERSONA CREATA CON SUCCESSO\n");
    return p;
}

char *leggi_stringa(){
    char *s;
    s=xmalloc(MAXN+1);
    fgets(s,MAXN+1,stdin);
    return s;
}

int controllo_cf(char codice_fiscale[]){
    int i;
    if (strlen(codice_fiscale)!=MAXCF){
        printf("Codice Fiscale non valido\n");
        return 0;
    }
    else{
        for (i=0; i<MAXCF; i++){
            switch (i)
            {
            case 0: case 1: case 2: case 3: case 4: 
            case 5: case 8: case 11: case 15:
                if (!isalpha(codice_fiscale[i])){
                    printf("Codice Fiscale non valido\n");
                    return 0;
                }
                break;
            case 6: case 7: case 9: case 10: 
            case 12: case 13: case 14: 
                if (!isdigit(codice_fiscale[i])){
                    printf("Codice Fiscale non valido\n");
                    return 0;
                }
                break;
            default:
                printf("Codice Fiscale non valido\n");
                return 0;
                break;
            }
        }
    }
    return 1;
}