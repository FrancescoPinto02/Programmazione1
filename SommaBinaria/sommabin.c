#include <stdio.h>
#include <math.h>
int bin_control(int num);
int bin_to_dec(int bin);
int dec_to_bin(int dec);

int main(void){
    int n1=0, n2=0, somma=0;
    do{
        printf("Inserisci numero 1: ");
        scanf("%d", &n1);
    }while(bin_control(n1)==0);
    do{
        printf("Inserisci numero 2: ");
        scanf("%d", &n2);
    }while(bin_control(n2)==0);
    n1=bin_to_dec(n1);
    n2=bin_to_dec(n2);
    somma=n1+n2;
    somma=dec_to_bin(somma);
    printf("Somma: %d", somma);
    return 0;
}

int bin_control(int num){
    while(num>0){
        if(num%10==0 || num%10==1){
            num/=10;
        }
        else{
            printf("Errore: Numero non binario\n");
            return 0;
        }
    }
    return 1;
}

int bin_to_dec(int bin){
    int dec=0, i=0;
    while(bin>0){
        if(bin%10!=0){
            dec=dec+pow(2,i);
        }
        bin=bin/10;
        i++;
    }
    return dec;
}

int dec_to_bin(int dec){
    int bin=0, div=0, r=0, i=0;
    double pot;
    do{
        div=dec/2;
        r=dec%2;
        dec=div;
        pot=pow(10,i);
        bin=bin +(r*pot);
        i++;
    }while(dec!=0);
    return bin;
}