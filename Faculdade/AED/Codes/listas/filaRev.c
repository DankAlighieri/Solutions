#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int v;
  struct nodo *next;
  struct nodo *prev;
} nodo;

typedef nodo *lista;

void criaLista(lista *l, int N) {
  lista tail;

  for (int i = 1; i <= N; i++) {
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    novo->v = i;

    if (i == 1) {
      *l = novo;
      novo->prev = novo;
    } else {
      tail->next = novo;
      novo->prev = tail;
    }
    tail = novo;
  }
  tail->next = *l;
  (*l)->prev = tail;
}

nodo *ret(nodo *rem) {
  nodo *target = rem->next;
  target->prev = rem->prev;
  rem->prev->next = target;
  free(rem);
  return target;
}

void solve(lista *l, int k, int m, int N) {
  lista hor = *l, ant = (*l)->prev;
  int first = 1;
  while (N) {
    if (!first)
      printf(",");
    first = 0;
    // Procura hor
    for (int h = 1; h < k; h++, hor = hor->next)
      ;
    // Procura ant
    for (int a = 1; a < m; a++, ant = ant->prev)
      ;
    //   printf("Rem hor: %d - Rem Ant: %d\n", hor->v, ant->v);
    if (hor == ant) {
    //   printf("Iguais %d %d\n", hor->v, ant->v);
      printf("%3d", hor->v);
      ant = hor = ret(hor);
      N--;
    } else {
      printf("%3d%3d", hor->v, ant->v);

      // Anti horario precisa ser removido primeiro para evitar falha de segmentacao
      ant = ret(ant);
      hor = ret(hor);
      N -= 2;
    }
    ant = ant->prev;
  }
  printf("\n");
}

int main() {
  int N, k, m;
  while (scanf("%d %d %d", &N, &k, &m), N) {
    lista l = NULL;
    criaLista(&l, N);
    solve(&l, k, m, N);
  }

  return 0;
}