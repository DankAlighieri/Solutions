#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int pos;
  struct nodo *ant;
  struct nodo *next;
} NODO;

typedef NODO *lista;

void cria_lista(lista *pl) { *pl = NULL; }

int tam(lista l) {
  int i;
  NODO *aux;

  if (!l) {
    return 0;
  }

  for (i = 1, aux = l->next; aux != l; i++, aux = aux->next)
    ;

  return i;
}

void ins(lista *pl, int N, int tot) {
  if (!N) {
    return;
  }
  NODO *novo, *aux;
  novo = (NODO *)malloc(sizeof(NODO));
  if (!novo) {
    puts("Mem err");
    return;
  }
  novo->pos = tot - N + 1;
  if (!(*pl)) {
    novo->next = novo;
    novo->ant = novo;
    *pl = novo;
  } else {
    NODO *aux=*pl;
    
    novo->next = aux->next;
    aux->next = novo;
    novo->ant = aux;
    aux->next->ant = novo;
    (*pl) = novo;
  }
  ins(pl, N - 1, tot);
}

int recup(lista l, int k) {
    for (; k > 0; k--, l=l->next);
    return l->pos;
}

void search(lista *pl, int k, int m);

void mostra(lista l) {
  NODO *aux = l->next;
  int i = 0;
  do {
    i++;
    printf("%d : %d\n", i, aux->pos);
    aux = aux->next;
  } while (aux != l->next);
}

int main() {
  lista l;
  cria_lista(&l);
  ins(&l, 10, 10);
  mostra(l);
  return 0;
}