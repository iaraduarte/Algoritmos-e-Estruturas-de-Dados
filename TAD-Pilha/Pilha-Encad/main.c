//main.c
#include <stdio.h>
#include "pilha.h"

int main()
{
	int x;
	pilha_t *p=criar();

	insere(p,5);
	insere(p,6);

	top(p,&x);
	printf("%d\n",x);

	remover(p,&x);

	top(p,&x);
	printf("%d\n",x);
	libera(p);
}
