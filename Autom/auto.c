#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX 40
typedef struct segmento{
int x;
int y;
}segmento;
 
void *xmalloc(size_t nbytes)
{
	void *s;
	s=malloc(nbytes);
	if (!s) return NULL;
	return s;
}

int main(void){
	segmento *p;
	segmento seg;
	p=&seg;
	seg.x=10;
	seg.y=5;
	printf("%d-%d",p->x, p->y);
	return 0;
}