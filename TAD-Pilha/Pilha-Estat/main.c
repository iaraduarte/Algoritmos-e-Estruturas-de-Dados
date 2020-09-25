#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    pilha_t *p;
    int i;
    int x;

    p=create();

    for(i=0;i<10;i++)
    {
        push(p,(elem)i);
    }

    while(!isEmpty(p))
    {
        pop(p,&x);
        printf("%d",x);
    }
    printf("\n");

    destroy(p);
    return 0;
}
