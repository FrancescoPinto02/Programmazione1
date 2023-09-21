//Presa in input una data GGMMAA viene scomposta in GG MM AA e stampata
//La funziona per fare ciò deve usare il passaggio di parametri tramite indirizzo

#include <stdio.h>
int dataform(int date, int *day, int *month, int*year);

int main(void){
    int data=0, gg=0, mm=0, aa=0, valida=0;
    do{
        printf("\ninserisci una data formato ggmmaa: ");
        scanf("%d",&data);
        if (data<10100 || data>311299){
            printf("data non valida! Riprova\n");
        }
    }while(data<10100 || data>311299);
    if(dataform(data, &gg, &mm, &aa)!=0){
        printf("DATA: %d / %d / 20%d", gg, mm, aa);
    }
    return 0;
}

int dataform(int date, int *day, int *month, int*year){
    int maxday=0;
    *year=date%100;
    date/=100;
    if (date%100<1 || date%100>12){
        printf("DATA NON VALIDA!\n");
        return 0;
    }
    *month=date%100;
    date/=100;
    switch (*month)
    {
    case 2:
        maxday=28; //NON PREVEDO GIORNI DI 29 (mi scocciavo!)
        break;
    case 4: case 6: case 9: case 11:
        maxday=30;
        break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        maxday=31;
        break;
    default:
        printf("DATA NON VALIDA!\n");
        return 0;
        break;
    }
    if (date%100<1 || date%100>maxday){
        printf("DATA NON VALIDA!\n");
        return 0;       
    }
    *day=date%100;
}