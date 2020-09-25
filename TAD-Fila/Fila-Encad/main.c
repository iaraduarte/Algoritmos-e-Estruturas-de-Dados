//main.c
#include <stdio.h>
#include "fila.h"

int main()
{
	int x;
	fila_t *f=criar();

	insere(f,5);
	insere(f,6);


	remover(f,&x);

	printf("%d\n",x);
	remover(f,&x);

	printf("%d\n",x);

	libera(f);
}
