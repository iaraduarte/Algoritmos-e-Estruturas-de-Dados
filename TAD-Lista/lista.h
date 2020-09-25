//lista.h
typedef int elem;
typedef struct lista lista_t;

lista_t *cria();

void libera(lista_t *l);

void insere(lista_t *l,elem x);

int tamanho(lista_t *l);

void imprimir(lista_t *l);

int esta_na_lista(lista_t *l, elem x);

int remover(lista_t *l,elem x);

lista_t *inverte(lista_t *l);
