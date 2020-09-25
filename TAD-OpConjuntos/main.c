#include <stdio.h>
#include <stdlib.h>
#include "inteiro.h"

int main()
{
    int num;
    conj *A,*B,*C;
    int contr=1;
    int op,saida;
    char conjunto;
    int tem,iguais,minimo,maximo;
    
    A=criar();
    B=criar();
    
    while(contr)
    {
        system("clear");
        printf("Seja bem-vindo!\n");
        printf("\n-Menu-\n");
        printf(" 1)Inserir\n 2)Imprimir\n 3)União (A U B)\n 4)Intersecção (A C B)\n 5)Diferença(A-B)\n");
        printf(" 6)Contem x?\n 7)Remover\n 8)Minimo\n 9)Maximo\n 10)Conjuntos Iguais?\n");
        printf("Para sair digite 0 :)\n");
        printf("\nDigite sua opção: ");
        scanf("%d",&op);
        
        switch(op)
        {
            case 1:
            inserir:
            printf("Digite o elemento (ou -1 para encerrar): ");
            scanf("%d",&num);
            if(num==-1)
            {
                break;
            }
            printf("Deseja inserir elementos em A ou B?");
            scanf(" %c",&conjunto);
            if(conjunto!='A' && conjunto!='B')
            {
                printf("Conjunto inválido, tente novamente!");
                goto inserir;
            }
            if(conjunto=='A')
            {
                inserir(num,A);
            }
            if(conjunto=='B')
            {
                inserir(num,B);
            }
            if(num!=-1)
            {
                goto inserir;
            }
            break;
            case 2:
            //imprimir
            imprimir:
            printf("\nDeseja imprimir A ou B? ");
            scanf(" %c",&conjunto);
            if(conjunto!='A' && conjunto!='B')
            {
                printf("Conjunto inválido, tente novamente!");
                goto imprimir;
            }
            if(conjunto=='A')
            {
                printf("\nA = { ");
                imprimir(A);
                printf("}\n");
            }
            if(conjunto=='B')
            {
                printf("\nB = { ");
                imprimir(B);
                printf("}\n");
            }            
            printf("\nQuando quiser voltar ao menu, digite 1: ");
            scanf("%d",&saida);
            if(saida==1)
            {
                break;
            }
            break;
            case 3:
            //uniao
            C=uniao(A,B);
            printf("União\n");
            printf("\n{ ");imprimir(A);printf("}");
            printf(" U ");
            printf("{ ");imprimir(B);printf("}");
            printf(" = ");
            printf("{ ");imprimir(C);printf("}");

            printf("\nQuando quiser voltar ao menu, digite 1: ");
            scanf("%d",&saida);
            if(saida==1)
            {
                liberar(C);
                break;
            }
            break;
            case 4:
            //interseccao
            C=inters(A,B);
            printf("Intersecção\n");
            printf("\n{ ");imprimir(A);printf("}");
            printf(" C ");
            printf("{ ");imprimir(B);printf("}");
            printf(" = ");
            printf("{ ");imprimir(C);printf("}");

            printf("\nQuando quiser voltar ao menu, digite 1: ");
            scanf("%d",&saida);
            if(saida==1)
            {
                liberar(C);
                break;
            }
            break;
            case 5:
            //dif
            C=dif(A,B);
            printf("Diferença\n");
            printf("\n{ ");imprimir(A);printf("}");
            printf(" - ");
            printf("{ ");imprimir(B);printf("}");
            printf(" = ");
            printf("{ ");imprimir(C);printf("}");

            printf("\nQuando quiser voltar ao menu, digite 1: ");
            scanf("%d",&saida);
            if(saida==1)
            {
                liberar(C);
                break;
            }
            break;
            case 6:
            //contem?
            contem:
            printf("Digite x: ");
            scanf("%d",&num);
            printf("Deseja procurar no conjunto A ou B? ");
            scanf(" %c",&conjunto);
            if(conjunto!='A' && conjunto!='B')
            {
                printf("Conjunto inválido, tente novamente!");
                goto contem;
            }
            if(conjunto=='A')
            {
                tem=membro(num,A);
            }
            if(conjunto=='B')
            {
                tem=membro(num,B);
            }
            if(tem==1)
            {
                printf("%d está em %c",num,conjunto);
            }
            if(tem==0)
            {
                printf("%d não está em %c",num,conjunto);
            }
            printf("\nQuando quiser voltar ao menu, digite 1: ");
            scanf("%d",&saida);
            if(saida==1)
            {
                break;
            }
            break;
            case 7:
            //remover
            remover:
            printf("\nDigite o elemento a ser removido (ou -1 para encerrar): ");
            scanf("%d",&num);
            if(num==-1)
            {
                break;
            }
            printf("Deseja remover elementos em A ou B? ");
            scanf(" %c",&conjunto);
            if(conjunto!='A' && conjunto!='B')
            {
                printf("Conjunto inválido, tente novamente!");
                goto inserir;
            }
            if(conjunto=='A')
            {
                tem=membro(num,A);
                if(tem==1)
                {
                    remover(num,A);
                }
                else
                {
                    printf("\nElemento não existe em A");
                }
            }
            if(conjunto=='B')
            {
                tem=membro(num,B);
                if(tem==1)
                {
                    remover(num,B);
                }
                else
                {
                    printf("\nElemento não existe em B");
                }
            }
            if(num!=-1)
            {
                goto remover;
            }
            break;
            case 8:
            //min
            printf("Deseja analisar A ou B? ");
            scanf(" %c",&conjunto);
            if(conjunto!='A' && conjunto!='B')
            {
                printf("Conjunto inválido, tente novamente!");
                goto inserir;
            }
            if(conjunto=='A')
            {
                minimo=min(A);                
                printf("Minimo de A: %d",minimo);
            }
            if(conjunto=='B')
            {
                minimo=min(B);
                printf("Minimo de B: %d",minimo);
            }
            printf("\nQuando quiser voltar ao menu, digite 1: ");
            scanf("%d",&saida);
            if(saida==1)
            {
                break;
            }
            break;
            case 9:
            //max
            printf("Deseja analisar A ou B? ");
            scanf(" %c",&conjunto);
            if(conjunto!='A' && conjunto!='B')
            {
                printf("Conjunto inválido, tente novamente!");
                goto inserir;
            }
            if(conjunto=='A')
            {
                maximo=max(A);                
                printf("Máximo de A: %d",maximo);
            }
            if(conjunto=='B')
            {
                maximo=max(B);
                printf("Máximo de B: %d",maximo);
            }
            printf("\nQuando quiser voltar ao menu, digite 1: ");
            scanf("%d",&saida);
            if(saida==1)
            {
                break;
            }
            break;
            case 10:
            //igual
            printf("São iguais?\n");
            iguais = igual(A,B);
            printf("\n{ ");imprimir(A);printf("}");
            printf(" e ");
            printf("{ ");imprimir(B);printf("}\n");
            if(iguais==0)
            {
                printf("Não são iguais");
            }
            if(iguais==1)
            {
                printf("São iguais");
            }
            printf("\nQuando quiser voltar ao menu, digite 1: ");
            scanf("%d",&saida);
            if(saida==1)
            {
                break;
            }
            break;
            case 0:
                contr=0;
            break;
        }
    }
    liberar(A);
    liberar(B);
    return 0;
}
