#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZEY 10
#define SIZEX 5

int *intersez(int x[], int sizex, int y[], int sizey, int *newsize);
int ver_num(int num, int arr[], int arrdim);
void *xmalloc (size_t nbytes);

int main(void){
    int x[SIZEX]={11,25,11,46,15};
    int y[SIZEY]={25,12,6,83,11,125,46,16,33,20};
    int *xy, newsize, i;
    xy=intersez(x, SIZEX, y, SIZEY, &newsize);
    printf("newsize:%d\n", newsize);
    for(i=0; i<newsize; i++){
        printf("[%d] ", xy[i]);
    }
    return 0;
}



int *intersez(int x[], int sizex, int y[], int sizey, int *newsize){
    int i, j, k, n;
    int *xy;
    n=0;
    for (i=0; i<sizex; i++){
        for (j=0; j<sizey; j++){
            if (ver_num(x[i], y, sizey)==1){
                n++;
                break;
            }
        }
    }
    xy=xmalloc(sizeof(int)*n);
    k=0;
    for (i=0; i<sizex; i++){
        for (j=0; j<sizey; j++){
            if (ver_num(x[i], y, sizey)==1){
                xy[k]=x[i];
                k++;
                break;
            }
        }
    }
    *newsize=n;
    return xy;
}

int ver_num(int num, int arr[], int arrdim){
    int i;
    for (i=0; i<arrdim; i++){
        if (num==arr[i]){
            return 1;
        }
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