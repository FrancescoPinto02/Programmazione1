#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define NL 3

typedef struct point
{
    double x;
    double y;
}point;

void *xmalloc (size_t nbytes);
point *new_point();
void new_triangle(point *triangle[]);
void triangle_sides_lenght(double sides[], point *triangle[]);
double distance(point *p1, point *p2);
void array_sort(double array[], int lenght);
int is_equal(double sides1[], double sides2[], int numsides);


int main(void){
    //dichiarazione variabili
    int i;
    point *tria1[NL], *tria2[NL];
    double lati_tria1[NL], lati_tria2[NL];

    //creazione triangoli
    new_triangle(tria1);
    new_triangle(tria2);
    
    //calcolo e ordinamento lati
    triangle_sides_lenght(lati_tria1, tria1);
    triangle_sides_lenght(lati_tria2, tria2);
    array_sort(lati_tria1, NL);
    array_sort(lati_tria2, NL);

    //controllo lati
    for (i=0; i<NL; i++){
        printf("[%lf] ", lati_tria1[i]);
        printf("[%lf] \n", lati_tria2[i]);
    }

    //lati uguali o diversi
    if (!is_equal(lati_tria1, lati_tria2, 3)){
        printf("LE DUE FIGURE NON HANNO I LATI UGUALI\n\n");
    }
    else{
        printf("LE DUE FIGURE HANNO I LATI UGUALI\n\n");
    }
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

point *new_point(){
    point *p = xmalloc(sizeof(point));
    //double xx, yy;
    printf("NUOVO PUNTO\n");
    printf("Inserisci coordinata x: ");
    scanf("%lf", &p->x);
    //printf("x:%lf ", p->x);
    printf("Inserisci coordinata y: ");
    scanf("%lf", &p->y);
    //printf("y:%lf ", p->y);
    return p;
}

void new_triangle(point *triangle[]){
    int j;
    printf("CREAZIONE NUOVO TRIANGOLO\n");
    for (j=0; j<NL; j++){
        triangle[j]=new_point();
    }
    printf("TRIANGOLO CREATO\n\n\n");
}

void triangle_sides_lenght(double sides[], point *triangle[]){
    sides[0]=distance( *triangle, *(triangle+1) );
    sides[1]=distance( *(triangle+1), *(triangle+2) );
    sides[2]=distance( *(triangle+2), *triangle );
}

double distance(point *p1, point *p2){
    double d=0, xdiff=0, ydiff=0;
    xdiff=p1->x - p2->x;
    ydiff=p1->y - p2->y;
    d=sqrt(xdiff*xdiff+ydiff*ydiff);
    return d;
}

void array_sort(double array[], int lenght){
    double tmp;
    int i,j, min;
    for (i=0; i<lenght-1; i++){
        min=i;
        for (j=i+1; j<lenght; j++){
            if (array[j]<array[min]){
                min=j;
            }
        }
        tmp=array[i];
        array[i]=array[min];
        array[min]=tmp;
    }
}

int is_equal(double sides1[], double sides2[], int numsides){
    int i;
    for (i=0; i<numsides; i++){
        if (sides1[i]!=sides2[i]){
            //printf("[%lf]!=[%lf] \n", sides1[i], sides2[i]); Controllo Bug
            return 0;
        }
    }
    return 1;
}