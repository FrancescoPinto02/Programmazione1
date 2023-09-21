//Scrivere un programma che, data una stringa di N caratteri, la inverta (es: "Informatica" diventa "acitamrofnI")

#include <stdio.h>
#include <string.h>
#define N 31

void scambia(char *a, char *b)
{
    char aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

void inverti(char v[])
{
    int i,l;

    l = strlen(v)-1;
    for (i=0; i<l/2; i++) scambia(&v[i],&v[l-i-1]);
}
 

int main(void)
{
    char s[N];
    printf("\nInserisci Stringa: ");
    fgets(s, N, stdin);
    inverti(s);
    printf("\nStringa invertita: %s",s);
    return 0;
}