#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

void inicio(pessoa *p,int tam){
    int i;
    for(i=0;i<tam;i++)
    {
        p[i].id=-1;
        p[i].livre=1;
    }
}

int incluir(pessoa *p,int tam,char *nomep,char *endp)
{
    int i,cont=0,controle;

	for(i=0;i<tam;i++)
    {
        if(p[i].livre==1)
        {
            p[i].id=i;

            strcpy(p[i].nome,nomep);
            strcpy(p[i].end,endp);

            p[i].livre=0;

            controle=i;
            cont++;
            break;
        }
    }
    if(cont>=0)
    {
        return controle;
    }
    else
    {
        return 0;
    }

}

int remover(pessoa *p,int rem,int tam)
{
    int i,cont;
    
    for(i=0;i<tam;i++)
    {
        if(rem==p[i].id)
        {
            if(p[i].livre==0)
            {
                strcpy(p[i].nome," ");
                strcpy(p[i].end," ");
                p[i].livre=1;

                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

void imprimir(pessoa *p,int i)
{
    if(p[i].livre==0)
    {
        printf("\n--Dados--\n");
        printf("Nome: %s\n",p[i].nome);
        printf("Endereço: %s\n",p[i].end);
    }

}

int buscar(pessoa *p,int tam,char *nomep)
{
    int cont=0,i;

    for(i=0;i<tam;i++)
    {
        if(strcasecmp(p[i].nome,nomep)==0)
        {
           return i;
           cont++;
        }
    }

    if(cont==0)
    {
        return -1;
    }
}
