//pilha.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "fila.h"

typedef struct no no_t;

struct no{
	elem info;
	struct no *prox;
};


struct fila{
	struct no *primeiro,*ultimo;
};

fila_t *criar()
{
	fila_t *f = (fila_t *)malloc(sizeof(fila_t));

	f->primeiro=NULL;
	f->ultimo=NULL;
	return f;
}

void insere(fila_t *f,elem x)
{
	assert(f!=NULL);

	no_t *novo=(no_t *)malloc(sizeof(no_t));

	novo->info=x;

	if(f->primeiro==NULL)
	{
		f->primeiro=novo;
		f->ultimo=novo;
	}
	else
	{
		f->ultimo->prox=novo;
		f->ultimo=novo;
	}

	novo->prox=NULL;
}

int remover(fila_t *f,elem *x)
{
	elem r;
	assert(f!=NULL);
	no_t *e=f->primeiro;
	
	*x=e->info;
	f->primeiro=f->primeiro->prox;
	free(e);

	return r;
}

void libera(fila_t *f)
{
	if(f!=NULL)
	{
		no_t *e=f->primeiro;
		while(e!=NULL)
		{
			f->primeiro=e->prox;
			free(e);
			e=f->primeiro;
		}
		free(f);
	}
}

