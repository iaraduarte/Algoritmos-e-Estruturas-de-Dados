#define N 100

typedef struct{
    int vetor[N];
} conj;

conj *criar();

void inserir(int x, conj *c);

void imprimir(conj *c);

void liberar(conj *c);

conj *uniao(conj *A, conj *B);

conj *inters(conj *A, conj *B);

conj *dif(conj *A, conj *B);

int membro(int x,conj *c);

void remover(int x, conj *c);

int min(conj *c);

int max(conj *c);

int igual(conj *A,conj *B);

//atribuir(int *A,int *B);
