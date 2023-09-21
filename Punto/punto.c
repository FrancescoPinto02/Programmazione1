#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct point
{
    double x;
    double y;
}point;

void *xmalloc (size_t nbytes);
point *new_point(double xx, double yy);
double distance(point *p1, point *p2);

int main (void){
    double dist;
    point *origine, *centro;
    origine=new_point(0,0);
    centro=new_point(3.1, 4.7);
    dist=distance(origine, centro);
    printf("dist:%f", centro->x);
    return 0;
}

point *new_point(double xx, double yy){
    point *p = xmalloc(sizeof(point));
    p->x=xx;
    p->y=yy;
    return p;
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

double distance(point *p1, point *p2){
    double d, xdiff, ydiff;
    xdiff=p1->x - p2->x;
    ydiff=p1->y - p2->y;
    d=sqrt((xdiff*xdiff)+(ydiff*ydiff));
    return d;
}