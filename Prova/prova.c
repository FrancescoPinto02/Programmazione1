/*Scrivere un programma C che permetta di raccogliere dei nomi da
tastiera. L’utente inserisce tali nomi finchè non ritiene di aver
terminato.

? Attraverso un numero intero N passato da tastiera, l’utente indica
quale nome vuole che venga cancellato e sostituito con un nuovo
nome dato anche esso da tastiera. Questo compito deve essere svolto
da una funzione il cui prototipo deve essere il seguente:
void cancella_rimpiazza (char nuovo_nome);*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 20

int main(void)
{
    int n,i;
    char **arr_str;
    //char str[MAXLEN];

    /*for (i=0; i<n; i++){
        scanf("%s", str);
        arr_str[i]=malloc((strlen(str))*sizeof(char));
        strcpy(arr_str[i], str);
    }*/

    printf ("quante stringhe vuoi allocare? ");
    scanf("%d", &n);

    arr_str=malloc(n*sizeof(char*));

    for (i=0; i<n; i++){
        arr_str[i]=malloc(MAXLEN*sizeof(char));
    }
    
    for (i=0; i<n; i++){
        printf("inserisci stringa %d: ", i+1);
        scanf("%s", arr_str[i]);
    }

    for (i=0; i<n; i++){
        printf("stringa %d: %s\n", i+1, arr_str[i]);
    }
return 0;
}

