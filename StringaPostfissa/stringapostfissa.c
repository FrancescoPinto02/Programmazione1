/*
Scrivere un programma che legge 2 stringhe strn1 e strn2, verificare se un strn1 è postfisso di strn2. Se vero, stampa strn1.
Esempio:   senza è postfisso di essenza
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 30

int is_postfissa(char string1[], char string2[]);
int controllo(char c1, char c2);

int main (void){
    char str1[MAXLEN+1], str2[MAXLEN+1];
    printf("Inserisci la prima stringa: ");
    gets(str1);
    printf("Inserisci la seconda stringa: ");
    gets(str2);
    if(is_postfissa(str1, str2)==1){
        printf("\nLa stringa: %s e' postfissa di: %s\n", str1, str2);
    }
    else{
        printf("\nLa stringa: %s non e' postfissa di: %s\n", str1, str2);
    }
    return 0;
}

int is_postfissa(char string1[], char string2[]){
    int len1, len2, j, k;
    len1=strlen(string1);
    len2=strlen(string2);
    k=1;
    for (j=len1-1; j>=0; j--){
        if(controllo(string1[j], string2[len2-k])==1){
            k++;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int controllo(char c1, char c2){
    if (c1==c2){
        return 1;
    }
    else{
        return 0;
    }
}