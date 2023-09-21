#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXDIM 100

char minimo(char * str);
char minimo2(char **str);

int main(void){
    char *nome;
    char *cognome;
    char *arrstr[2];
    char *minarr;
    char min_nome, min_cognome, min;
    nome=malloc(MAXDIM);
    if (!nome){
        printf("Errore\n");
        return 1;
    }
    printf("inserisci il nome: ");
    scanf("%s", nome);


    cognome=(char*)malloc(MAXDIM);
    if (!cognome){
        printf("Errore\n");
        return 1;
    }
    printf("inserisci il cognome: ");
    scanf("%s", cognome);

    nome=realloc(nome, strlen(nome));
    cognome=realloc(cognome, strlen(cognome));
    
    min_nome=minimo(nome);
    min_cognome=minimo(cognome);

    printf("nome: %s\n", nome);
    printf("cognome: %s\n", cognome);

    if(min_cognome<min_nome){
        min=min_cognome;
    }
    else{
        min=min_nome;
    }
    printf("carattere minore: %c\n", min);

    arrstr[1]=malloc(strlen(nome));
    arrstr[2]=malloc(strlen(cognome));
    strcpy(arrstr[1], nome);
    strcpy(arrstr[2], cognome);
    minarr=minimo2(arrstr);
    return 1;

}

char minimo(char * str){
    int i, dim=strlen(str);
    char min=str[0];
    for(i=0; i<dim; i++ ){
        if(str[i]<min){
            min=str[i];
        }
    }
    return min;
}

char minimo2(char **str){
    
}