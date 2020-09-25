//lista.c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lista.h"

typedef struct no no_t;

struct no{
	elem info;
	struct no *prox;
};

struct lista{
	no_t *ini,*fim;
	int tam;
};

lista_t *cria()
{
	lista_t *l;
	l=(lista_t *)malloc(sizeof(lista_t));

	assert(l!=NULL);

	l->ini=NULL;
	l->fim=NULL;
	l->tam=0;

	return l;
}

void libera(lista_t *l)
{
	if(l!=NULL)
	{
		no_t *p=l->ini;
		while(p!=NULL)
		{
			l->ini=p->prox;
			free(p);
			p=l->ini;
		}
		free(l);
	}
}

void insere(lista_t *l,elem x)
{
	assert(l!=NULL);

	if(esta_na_lista(l,x)==1)
	{
		return;
	}

	no_t *p=(no_t *)malloc(sizeof(no_t));
	p->info=x;
	p->prox=NULL;

	if(l->ini==NULL)
	{
		l->ini=p;
	}
	else
	{
		l->fim->prox=p;
	}

	l->fim=p;
	l->tam=l->tam+1;
}

int tamanho(lista_t *l)
{
	assert(l!=NULL);
	return l->tam;
}

void imprimir(lista_t *l)
{
	assert(l!=NULL);

	no_t *p=l->ini;

	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->prox;
	}
}

int esta_na_lista(lista_t *l, elem x)
{
	assert(l!=NULL);

	no_t *p=l->ini;
	while(p!=NULL)
	{
		if(p->info==x)
		{
			return 1;
		}
		p=p->prox;
	}
	return 0;
}

int remover(lista_t *l,elem x)
{
	elem r;
	assert(l!=NULL);
	no_t *ant=NULL;
	no_t *p=l->ini;

	while(p!=NULL)
	{
		if(p->info==x)
		{
			if(p == l->ini)
			{
				l->ini=l->ini->prox;
				r=p->info;
				free(p);
			}
			else if(p==l->fim)
			{
				r=p->info;
				l->fim=ant;
				l->fim->prox=NULL;
				free(p);
			}
			else
			{
				r=p->info;
				ant->prox=p->prox;
				free(p);
			}
			l->tam=l->tam-1;
			return r;
		}
		else
		{	
			ant=p;
			p=p->prox;
		}
	}
	return 0;
}

lista_t *inverte(lista_t *l)
{
	assert(l!=NULL);

	lista_t *inv=cria();
	assert(inv!=NULL);

	int n;
	no_t *p=l->ini;

	while(l->tam!=0)
	{
		n=remover(l,l->fim->info);
		insere(inv,n);
	}
	return inv;
}
