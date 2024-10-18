#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int pos;
  struct nodo *next;
  struct nodo *prev;
} NODO;

typedef NODO *lista;

void cria_lista(lista *pl, int N) {
  lista tail;

  for (int i = 1; i <= N; i++) {
    lista novo = (lista) malloc(sizeof(NODO));
    novo->pos = i;

    if (i == 1) {
      *pl = novo;
      novo->prev = novo;
    } else {
      tail->next = novo;
      novo->prev = tail;
    }
    tail = novo;
  }
  tail->next = *pl;
  (*pl)->prev = tail;
}

lista ret(lista nodeRem) {
  lista adj = nodeRem->next;

  adj->prev = nodeRem->prev;
  nodeRem->prev->next = adj;

  free(nodeRem);
  return adj;
}

void solve(lista l, int k, int m, int n){
  lista hor = l, ant = l->prev;
  int f = 1;
  while (n) {
    if(!f) putchar(',');
    f = 0;
    for (int i = 1; i < k; i++) {
      hor = hor->next;
    }
    for (int i = 1; i < m; i++) {
      ant = ant->prev;
    }

    if (hor != ant) {
      printf("%3d%3d", hor->pos, ant->pos);
      ant = ret(ant);
      hor = ret(hor);
      n-=2;
    } else {
      printf("%3d", hor->pos);
      ant = hor = ret(hor);
      n--;
    }
    ant = ant->prev;
  }
  printf("\n");
}

int main() {
  int n, k, m;
  while (scanf("%d %d %d", &n, &k, &m), n) {
    lista l = NULL;
    cria_lista(&l, n);
    solve(l, k, m, n);
  }

  return 0;
}