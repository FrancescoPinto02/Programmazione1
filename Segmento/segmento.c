#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define N 2

typedef struct segmento
{
    double x1;
    double y1;
    double x2;
    double y2;
}Segmento;

double lunghezza (Segmento *s);
void *xmalloc (size_t nbytes);
void elimina_lunghi (Segmento *as[], int n, double max_len);
Segmento *new_segmento();
void fill_array (Segmento *array[]);


int main(void){
    Segmento *as[N];
    fill_array(as);
    elimina_lunghi(as, N, 5);
    return 0;
}

double lunghezza (Segmento *s){
    double d=0, xdiff=0, ydiff=0;
    xdiff= s->x1 - s->x2;
    ydiff= s->y1 - s->y2;
    d=sqrt(xdiff*xdiff+ydiff*ydiff);
    return d;
}

void elimina_lunghi (Segmento *as[], int n, double max_len){
    int i, canc;
    canc=0;
    for (i=0; i<n; i++){
        if (lunghezza(as[i])>max_len){
            free(as[i]);
            as[i]=NULL;
            canc++;
        }
    }
    printf("elementi cancellati=%d\n", canc);
}

void fill_array (Segmento *array[]){
    int i;
    for (i=0; i<N; i++){
        array[i]=new_segmento();
    }
}

Segmento *new_segmento(){
    Segmento *sp;
    sp=xmalloc(sizeof(Segmento));
    printf("\nCREAZIONE NUOVO SEGMENTO\n");
    printf("Inserisci x1: ");
    scanf("%lf",&(sp->x1));
    printf("Inserisci y1: ");
    scanf("%lf",&(sp->y1));
    printf("Inserisci x2: ");
    scanf("%lf",&(sp->x2));
    printf("Inserisci y2: ");
    scanf("%lf",&(sp->y2));
    return sp;
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
