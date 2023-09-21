#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct acquisto{
    char descrizione[30];
    double quantita;
    double prezzo_unitario;
}Acquisto;

void *xmalloc (size_t nbytes);
Acquisto *leggi_acquisti(FILE *fin, int *n_acquisti);
double spesa_totale(Acquisto scontrino[], int n);

int main(void){
    FILE *fin;
    int n_acquisti, i;
    Acquisto *p;
    double spesa;

    fin=fopen("cassa.txt", "r");
    if (!fin){
        fprintf(stderr, "errore apertura file in lettura\n");
        exit(-1);
    }
    p=leggi_acquisti(fin, &n_acquisti);
    printf("\nACQUISTI LETTI DA FILE: %d\n", n_acquisti);
    
    for (i=0; i<n_acquisti; i++){
        printf("\nOGGETTO N%d\nDescrizione: %s\nQuantita: %lf\nPrezzo Unitario: %lf\n",i+1, p[i].descrizione, p[i].quantita, p[i].prezzo_unitario);
    }

    spesa=spesa_totale(p,n_acquisti);
    printf("\nSPESA TOTALE: %lf$\n\n", spesa);
    return 0;
}




Acquisto *leggi_acquisti(FILE *fin, int *n_acquisti){
    int i;
    int n;
    Acquisto *p;
    fscanf(fin, "%d", &n);
    p=xmalloc(sizeof(Acquisto)*n);
    for (i=0; i<n; i++){
        if(fscanf(fin, "%s", p[i].descrizione)!=1) break;
        if(fscanf(fin, "%lf", &p[i].quantita)!=1) break;
        if(fscanf(fin, "%lf", &p[i].prezzo_unitario)!=1) break;
    }
    *n_acquisti=i;
    fclose(fin);
    return p;
}

double spesa_totale(Acquisto scontrino[], int n){
    double tot;
    int i;
    for (i=0; i<n; i++){
        tot+=(scontrino[i].quantita) * (scontrino[i].prezzo_unitario); 
    }
    return tot;
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