#include <stdio.h>
#include <stdlib.h>
#include "inteiro.h"

conj *criar()
{
    conj *c = calloc(1,sizeof(conj));
    return c;
}

void inserir(int x, conj *c)
{
    c->vetor[x]=1;
}

void imprimir(conj *c)
{
    int i;
    
    for(i=0;i<100;i++)
    {
        if(c->vetor[i]==1)
        {
            printf("%d ",i);
        }
    }
}

void liberar(conj *c)
{
    if(c!=NULL)
    {
        free(c);
        c=NULL;
    }
}
conj *uniao(conj *A, conj *B)
{
    int i;
    conj *res = criar();
    
    for(i=0;i<100;i++)
    {
        if((A->vetor[i]==1)||(B->vetor[i]==1))
        {
            res->vetor[i]=1;
        }
    }
    return res;
}

conj *inters(conj *A, conj *B)
{
    int i;
    conj *res = criar();
    
    for(i=0;i<100;i++)
    {
        if((A->vetor[i]==1)&&(B->vetor[i]==1))
        {
            res->vetor[i]=1;
        }
    }
    return res;
}

conj *dif(conj *A, conj *B)
{
    int i;
    conj *res = calloc(1,sizeof(conj));
    
    for(i=0;i<100;i++)
    {
        if((A->vetor[i]==1)&&(B->vetor[i]==0))
        {
            res->vetor[i]=1;
        }
    }
    return res;
}

int membro(int x,conj *c)
{
    int res;
    if(c->vetor[x]==1)
    {
        res=1;
    }
    else
    {
        res=0;
    }
    return res;
}

void remover(int x, conj *c)
{
    c->vetor[x]=0;
}

int min(conj *c)
{
    int i;
    int res;
    for(i=0;i<100;i++)
    {
        if(c->vetor[i]==1)
        {
            res=i;
            break;
        }
    }
    return res;
}

int max(conj *c)
{
    int i;
    int res;
    for(i=99;i>=0;i--)
    {
        if(c->vetor[i]==1)
        {
            res=i;
            break;
        }
    }
    return res;
}

int igual(conj *A,conj *B)
{
    int res=1;
    int i;
    for(i=0;i<100;i++)
    {
        if(A->vetor[i]!=B->vetor[i])
        {
            res=0;
            break;
        }
    }
    return res;
}

//atribuir(int *A,int *B);
