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

  // alocando memoria
  novo = (NODO *)malloc(sizeof(NODO));
  if (!novo) {
    puts("Mem err");
    return;
  }

  // setando posicao
  novo->pos = tot - N + 1;

  // lista vazia
  if (!(*pl)) {
    novo->next = novo;
    novo->ant = novo;
  }

  /*
    Lista nao vazia
    apenas um caso de insercao - ultimo elemento
  */
  else {
    NODO *aux = *pl;

    novo->next = aux->next;
    novo->ant = aux;
    aux->next->ant = novo;
    aux->next = novo;
  }

  // referencia externa sera o ultimo nodo
  *pl = novo;
  ins(pl, N - 1, tot);
}

void ret(NODO *node) {
  node->ant->next = node->next;
  node->next->ant = node->ant;
  free(node);
}

void search(lista *pl, int k, int m) {
  NODO *nd, *ne;
  int posN, posA;

  
}

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
  int k, m, N;

  cria_lista(&l);
  do {
    scanf("%d %d %d", &N, &k, &m);

    if (N && k && m) {
      ins(&l, N, N);
      /*
      while (l) {
        // search(&l, k, m);
       };
      */
    }
  } while (N);

  return 0;
}