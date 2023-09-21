#include <stdio.h>
#define MAXDIM 50

void FillArray(int Array[], int elements);
void Armstrong(int Array[], int index);
void PrintNoNull(int Array[], int elements);
void Print(int Array[], int elements);


int main(void)
{
	int A[MAXDIM];
	int n=0;
	int i;
	do{
		printf("Inserisci il numero di elementi: ");
		scanf("%d" , &n);
		if (n>50||n<0)
		{
			printf("Errore: Riprova!");
		}
	}
	while(n>50||n<0);
	
	FillArray(A, n);
	
	for (i=0; i<n; i++)
	{
		Armstrong(A, i);
	}
	PrintNoNull(A, n);
	
	return 0;
}


void FillArray(int Array[], int elements)
{
	int j;
	for (j=0; j<elements; j++)
	{
		printf("Inserisci elemento numero %d: ", j+1);
		scanf("%d", &Array[j]);
	}
}

void Armstrong(int Array[], int index)
{
	int tot, num, j;
	tot=0;
	num=Array[index];
	
	if (num<100 || num>999)
	{
		Array[index]=0;
	}
	else
	{
		for (j=0; j<3; j++)
		{
			tot+=(num%10)*(num%10)*(num%10);
			num/=10;
		}
		if (tot!=Array[index])
		{
			Array[index]=0;
		}
	}
}
	
	
	
void PrintNoNull(int Array[], int elements)
{
	int j;
	printf("\nNUMERI DI ARMSTRONG: ");
	for (j=0; j<elements; j++)
	{
		if (Array[j]!=0)
		{
			printf("%d ", Array[j]);
		}	
	}

}



void Print(int Array[], int elements)
{
	int j;
	for (j=0; j<elements; j++)
	{
		printf("%daaa ", Array[j]);		
	}

}
