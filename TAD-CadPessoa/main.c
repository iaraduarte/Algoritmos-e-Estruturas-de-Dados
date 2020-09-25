#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"


int main()
{
    pessoa *p;
    int tam,opc,op;
    int cont=1;
    int rem,crem;
    int cinc;
    int cbusc;
    char nomep[50];
    char endp[60];
    char busca[50];

    printf("Exercicio 1 - TAD Cadastro\n");
    printf("Digite o numero de cadastros desejado: ");
    scanf("%d",&tam);

    p = (pessoa *)malloc(sizeof(pessoa)*tam);

    inicio(p,tam);

    while(cont)
    {
        system("clear");

        printf("--Menu--\n");
        printf("1) Incluir Pessoa\n");
        printf("2) Excluir Pessoa\n");
        printf("3) Busca por Nome\n");
        printf("0) Sair\n");

        scanf("%d",&opc);

        switch(opc)
        {
            case 1:
                system("clear");
                printf("--Incluir--\n");

                printf("Nome: ");
                scanf(" %[^\n]s",nomep);

                printf("Endereço: ");
                scanf(" %[^\n]s", endp);

                cinc=incluir(p,tam,nomep,endp);

                if(cinc>=0)
                {
                    printf("\nPessoa incluída com sucesso!");
                    imprimir(p,cinc);
                }
                else
                {
                    printf("Erro na inclusão!\n");
                }
                
                printf("\nQuando quiser voltar ao menu, digite 1: ");
                scanf("%d",&op);
                if(op==1)
                {
                    break;
                }
            break;
            case 2:
                system("clear");
                printf("--Remover--\n");
                printf("Digite o id da pessoa que deseja remover: ");
                scanf("%d",&rem);
                crem=remover(p,rem,tam);

                if(crem!=1)
                {
                    printf("Erro na exclusão!\n");
                }
                
                printf("\nQuando quiser voltar ao menu, digite 1: ");
                scanf("%d",&op);
                if(op==1)
                {
                    break;
                }
            break;
            case 3:
                system("clear");
                printf("--Buscar por Nome--\n");
                printf("Digite o Nome: ");
                scanf(" %[^\n]s", busca);
                
                cbusc=buscar(p,tam,busca);
                
                if(cbusc!=-1)
                {
                    printf("\nPessoa encontrada com sucesso!");
                    imprimir(p,cbusc);
                }
                else
                {
                    printf("Erro na busca!\n");
                }
                
                printf("\nQuando quiser voltar ao menu, digite 1: ");
                scanf("%d",&op);
                if(op==1)
                {
                    break;
                }
            break;
            case 0:
                cont=0;
            break;
        }
    }
    return 0;
}
