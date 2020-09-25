//main.c
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
	lista_t *l=cria();
	lista_t *i=cria();

	insere(l,5);

	imprimir(l);

	i=inverte(l);

	imprimir(i);

	libera(l);

	return 0;
}
