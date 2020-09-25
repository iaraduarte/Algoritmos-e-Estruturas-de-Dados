//pilha.h

typedef int elem;
typedef struct fila fila_t;

fila_t *criar();

void insere(fila_t *f,elem x);

int remover(fila_t *f,elem *x);

void libera(fila_t *f);
