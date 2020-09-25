#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct ponto
{
    int x,y;
}ponto_t;

int main()
{
    int i;
    pilha_t *p;

    p=create(sizeof(ponto_t));

    ponto_t ponto;

    for(i=0;i<10;i++)
    {
        ponto.x=i;
        ponto.y=-i;
        push(p,&ponto);
    }
    
    while(!isEmpty(p))
    {
        pop(p,&ponto);
        printf("%d, %d\n",ponto.x,ponto.y);
    }

    destroy(p);
    return 0;
}
