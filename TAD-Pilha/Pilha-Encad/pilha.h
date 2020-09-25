//pilha.h

typedef int elem;
typedef struct pilha pilha_t;

pilha_t *criar();

void insere(pilha_t *p,elem x);

int remover(pilha_t *p,elem *x);

void libera(pilha_t *p);

int top(pilha_t *p,elem *x);
