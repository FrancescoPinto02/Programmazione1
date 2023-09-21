#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DIM_STR 50
#define NUM_STR 3

char * read_string(int maxdim); //Funzione per leggere una stringa e allocare solo lo spazio necessario
char * merge(char* string1, char* string2); //Funzione per concatenare due stringhe
char * incastona(char* string1, char* string2); //Funzione per incastonare due stringhe
void inverti(char** matrix); //Funzione per invertire nome e cognome nella matrice
void crea (char** matrix); //Funzione per creare una nuova stringa all`interno della matrice
void ordina (char * string); //Funzione per ordinare i caratteri di una stringa

int main(void){
    char *nome;
    char *cognome;
    char **credenziali=calloc(NUM_STR, sizeof(char *));
    printf("Inserisci il nome: ");
    nome=read_string(DIM_STR);
    printf("Inserisci il cognome: ");
    cognome=read_string(DIM_STR);
    credenziali[0]=nome;
    credenziali[1]=cognome;
    
    char *concstr;
    concstr=merge(nome, cognome);
    printf("Stringhe Concatenate: %s\n", concstr);

    char *incstr;
    incstr=incastona(nome, cognome);
    printf("Stringhe Incastonate: %s\n", incstr);

    inverti(credenziali);

    crea(credenziali);
    printf("Nuova Stringa: %s\n", credenziali[2]);

    ordina(nome);
    printf("Nome Ordinato: %s\n", nome);
    ordina(cognome);
    printf("Cognome Ordinato: %s\n", cognome);
    return 0;
}

char * read_string(int maxdim){
    int j=0;
    //Allocazione e Controllo
    char *str=(char *)calloc(maxdim, sizeof(char));
    if (!str){
        printf("ERRORE!\n");
        return NULL;
    }
    //-----------------------------
    //Input string ed eliminazione ritorno a capo
    str=fgets(str, maxdim, stdin);
    while(str[j]!='\0'){
        if (str[j]=='\n'){
            str[j]='\0';
        }
        j++;
    }
    //------------------------------------------
    str=realloc(str, sizeof(char)*(strlen(str)+1));
    return str;
}

char * merge(char* string1, char* string2){
    //Creazione e allocazione (con controllo) della nuova stringa
    char * newstr=(char *)calloc(strlen(string1)+strlen(string2)+1, sizeof(char));
    if (!newstr){
        printf("ERRORE!\n");
        return NULL;
    }
    //----------------------------
    //Copia e concatenzaione
    newstr=strcpy(newstr, string1);
    newstr=strcat(newstr, string2);
    return newstr;
}

char * incastona(char* string1, char* string2){
    char * bigstr;
    char * smallstr;
    char * newstr;
    int j;
    int chardiff=0;
    //Individua stringa grande e stringa piccola
    if (strlen(string1)==strlen(string2)){
        printf("ERRORE: Le stringhe non si possono incastonare!\n");
        return NULL;
    }
    if(strlen(string1)>strlen(string2)){
        bigstr=string1;
        smallstr=string2;
    }
    else{
        bigstr=string2;
        smallstr=string1;
    }
    //---------------------------------------
    //Allocazione con controllo della nuova stringa
    newstr=(char *)calloc(strlen(bigstr)+1, sizeof(char));
    if (!newstr){
        printf("ERRORE!\n");
        return NULL;
    }
    //------------------------------------------------
    //Concatenazione caratteri
    newstr=strncat(newstr,bigstr,(strlen(bigstr)-strlen(smallstr))/2);
    newstr=strcat(newstr, smallstr);
    for(j=strlen(newstr); j<=strlen(bigstr); j++){
        newstr[j]=bigstr[j];
    }
    newstr[strlen(bigstr)]='\0';
return newstr;
}

void inverti(char** matrix){
    char * swap=matrix[0];
    matrix[0]=matrix[1];
    matrix[1]=swap;
}

void crea (char** matrix){
    int j, k;
    char * newstr=(char *)calloc(7, sizeof(char));
    //For per i primi 3 caratteri del nome
    for(j=0; j<3; j++){
        newstr[j]=matrix[1][j];
    }
    //------------------------------
    //For per gli ultimi 3 caratteri del cognome
    k=3;
    for(j=0; j<3; j++){
        newstr[3+j]=matrix[0][strlen(matrix[0])-k];
        k--;
    }
    //---------------------------------------
    newstr[6]='\0';
    matrix[2]=newstr;
}

void ordina (char * string){
    int dim=strlen(string);
    int i,j;
    char swap;
    for(i=0; i<=dim-2; i++){
        for(j=i+1; j<=dim-1; j++){
            //tolower=funzione per convertire un char nell`equivalente in minuscolo
            if(tolower(string[j])<tolower(string[i])){
                swap=string[j];
                string[j]=string[i];
                string[i]=swap;
            }
        }
    } 
}