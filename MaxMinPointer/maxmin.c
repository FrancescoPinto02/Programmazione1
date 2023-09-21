#include <stdio.h>
#define N 10

void fill_array(int array[]);
void min_max(int array[], int *min, int *max);


int main(void){
    int num[N], big=0, small=0;
    fill_array(num);
    min_max(num, &small, &big);
    printf("Il numero più grande è %d\n",big);
    printf("Il numero più piccolo è %d\n",small);
    return 0;
}

void fill_array(int array[]){
    int j;
    for (j=0; j<N; j++){
        printf("Inserisci l`elemento %d:", j+1);
        scanf("%d", &array[j]);
    }
}

void min_max(int array[], int *min, int *max){
    int j;
    *min=array[0];
    *max=array[0];
    for (j=0; j<N; j++){
        if (*min>array[j]){
            *min=array[j];
        }
        else if (*max<array[j]){
            *max=array[j];
        }       
    }
}