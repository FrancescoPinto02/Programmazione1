#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGHT 50


char *new_string(char string_array[][MAXLENGHT], int elements){
    int i,j,num;
    char *newS;
    num=elements;
    for (i=0; i<elements; i++){
        if(isalpha(string_array[i][0])==0){
            num--;
        }
    }
    newS= (char *) malloc(sizeof(char)*num+1);
    if(newS == NULL){
        printf("Memoria esaurita\n");
        exit(1);
    }

    j=0;
    for (i=0; i<elements; i++){
        if(isalpha(string_array[i][0])!=0){
            newS[j]=string_array[i][0];
            j++;
        }       
    }
    newS[num-1]='\0';
    return newS;
}