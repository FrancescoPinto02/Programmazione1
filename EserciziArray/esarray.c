#include <stdio.h>
#define MAXDIM 10

int insert_element(int arr[], int num, int maxdim, int newel, int pos);
int min_array(int arr[], int num);
void shiftdx(int arr[], int num, int pos);
void print_array(int arr[], int num);

int main(void){
    int array[MAXDIM]={3,6,2,4};
    int num=4, min=0, newel=0, pos=0;
    min=min_array(array, num);
    printf("Il minore è :%d\n", min);
    printf("Elemento da inserire: ");
    scanf("%d", &newel);
    printf("Posizione elemento: ");
    scanf("%d", &pos);
    num=insert_element(array, num, MAXDIM, newel, pos);
    printf("num:%d\n", num);
    print_array(array, num);
    min=min_array(array, num);
    printf("Il minore è :%d\n", min);
    return 0;
}

int min_array(int arr[], int num){
    int j, min;
    min=arr[0];
    for (j=0; j<num-1; j++){
        if (arr[j]<min){
            min=arr[j];
        }
    }
    return min;
}

int insert_element(int arr[], int num, int maxdim, int newel, int pos){
    int n;
    if (num>=maxdim){
        return num;
    }
    shiftdx(arr, num, pos);
    arr[pos]=newel;
    n=num+1;
    return n;
}

void shiftdx(int arr[], int num, int pos){
    int i;
    for (i=num-1; i>=pos; i--){
        arr[i+1]=arr[i];
    }
}

void print_array(int arr[], int num){
    int i;
    for(i=0; i<num; i++){
        printf("A[%d]=%d\n", i, arr[i]);
    }
}