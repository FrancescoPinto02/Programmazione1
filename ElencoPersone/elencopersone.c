#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 30
#define MAXCF 16
#define MAXP 4

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
void fill_array(persona *arr[]);
void cerca_nc (persona *arr[], int num);
void cerca_cf (persona *arr[], int num);
persona **sottoelenco(persona *elenco[], int *num);


int main (void){
    int i, num;
    persona *p1[MAXP];
    persona **sot;
    fill_array(p1);
    cerca_nc(p1, MAXP);
    cerca_cf(p1, MAXP);
    sot=sottoelenco(p1, &num);
    
    for(i=0; i<num; i++){
        printf("PERSONA %d\nnome: %sCognome: %sCodice Fiscale: %s\n", i+1, sot[i]->nome, sot[i]->cognome, sot[i]->cod_fis);
    }

    return 0;
}

persona **sottoelenco(persona *elenco[], int *num){
    int i,n;
    char *cognome;
    persona **sot;
    printf("CREAZIONE SOTTOELENCO");
    printf("Inserisci il cognome:");
    cognome=leggi_stringa();
    
    n=0;
    for(i=0; i<MAXP; i++){
        if(strcmp(cognome,elenco[i]->cognome)==0){
            n++;
        }
    }
    
    sot=xmalloc(sizeof(persona*) * n);
    *num=n;
    
    int k=0;
    for(i=0; i<MAXP; i++){
        if(strcmp(cognome,elenco[i]->cognome)==0){
            sot[k]=elenco[i];
            k++;
        }
    }
    return sot;
}

void cerca_nc (persona *arr[], int num){
    int i;
    char *nome, *cognome;
    printf("RICERCA NOME E COGNOME\n");
    printf("Inserisci il nome da ricercare: ");
    nome=leggi_stringa();
    printf("Inserisci il cognome da ricercare: ");
    cognome=leggi_stringa();
    for (i=0; i<MAXP; i++){
        if(strcmp(nome,arr[i]->nome)==0){
            if(strcmp(cognome, arr[i]->cognome)==0){
                printf("PERSONA TROVATA!\n");
                printf("nome: %scognome: %scodice fiscale:%s",arr[i]->nome, arr[i]->cognome, arr[i]->cod_fis);
                return;
            }
        }
    }
    printf("PERSONA NON TROVATA!");
}

void cerca_cf (persona *arr[], int num){
    int i;
    char *cf;
    printf("RICERCA CODICE FISCALE\n");
    printf("Inserisci il codice fiscale da ricercare: ");
    gets(cf);
    for (i=0; i<MAXP; i++){
        if(strcmp(cf,arr[i]->cod_fis)==0){
            printf("PERSONA TROVATA!\n");
            printf("nome: %scognome: %scodice fiscale:%s",arr[i]->nome, arr[i]->cognome, arr[i]->cod_fis);
            return;
        }
    }
    printf("PERSONA NON TROVATA!");
}

void fill_array(persona *arr[]){
    int i;
    for (i=0; i<MAXP; i++){
        arr[i]=new_persona();
    }
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