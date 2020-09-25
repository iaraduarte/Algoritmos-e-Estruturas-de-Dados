typedef struct{
    int id;
    int livre;
    char nome[50];
    char end[60];
} pessoa;

void inicio(pessoa *p,int tam);

int incluir(pessoa *p,int tam,char *nomep,char *endp);

int remover(pessoa *p,int rem,int tam);

void imprimir(pessoa *p,int i);

int buscar(pessoa *p,int tam,char *nomep);
