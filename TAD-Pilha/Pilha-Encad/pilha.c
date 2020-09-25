//pilha.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "pilha.h"

typedef struct no no_t;

struct no{
	elem info;
	struct no *prox;
};


struct pilha{
	struct no *topo;
};

pilha_t *criar()
{
	pilha_t *p = (pilha_t *)malloc(sizeof(pilha_t));

	p->topo=NULL;
	return p;
}

void insere(pilha_t *p,elem x)
{
	assert(p!=NULL);

	no_t *novo=(no_t *)malloc(sizeof(no_t));

	novo->info=x;

	if(p->topo==NULL)
	{
		novo->prox=NULL;
	}
	else
	{
		novo->prox=p->topo;
	}

	p->topo=novo;
}

int remover(pilha_t *p,elem *x)
{
	elem r;
	assert(p!=NULL);
	no_t *e=p->topo;
	*x=e->info;
	p->topo=p->topo->prox;
	free(e);

	return r;
}

void libera(pilha_t *p)
{
	if(p!=NULL)
	{
		no_t *e=p->topo;
		while(e!=NULL)
		{
			p->topo=e->prox;
			free(e);
			e=p->topo;
		}
		free(p);
	}
}

int top(pilha_t *p,elem *x)
{
    assert(p!=NULL);

	no_t *e=p->topo;

    if(p->topo==NULL)
    {
        return -1;
    }

    *x=e->info;

    return 1;
}
