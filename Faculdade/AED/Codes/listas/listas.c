#include <stdio.h>
#include <stdlib.h>
#define max 10000

typedef struct {
  int N;
  int val[max];
} LISTA;

void criar_lista(LISTA *l) { l->N = 0; }

int eh_vazia(LISTA *l) { return (!l->N); }

int tam(LISTA *l) { return l->N; }

void ins(LISTA *l, int valor, int posicao) {
  int i;
  if (l->N == max) {
    puts("Erro! Lista cheia!");
    return;
  } else if (posicao < 1 || posicao > max - 1) {
    puts("Posicao invalida!");
    return;
  }
  for (i = l->N; i >= posicao; i--) {
    l->val[i] = l->val[i - 1];
  }

  l->val[posicao - 1] = valor;
  l->N++;
}

int recup(LISTA *l, int k) {
  if (k < 1 || k > l->N) {
    puts("Posicao invalida!");
    return 1;
  }

  printf("Valor %d na posicao %d\n", l->val[k - 1], k);

  return l->val[k];
}

void printa_lista(LISTA *l, int in) {
  int i;
  for (i = in - 1; i <= l->N; printf("%d - %d\n", i + 1, l->val[i]), i++)
    ;
}

void ret(LISTA *l, int k) {
  int i;

  if (k < 1 || k > l->N) {
    puts("Posicao invalida!");
    return;
  }

  l->N--;

  for (i = k; i < l->N; i++) {
    l->val[i - 1] = l->val[i];
  }
}

int pertence(LISTA *l, int val) {
  int i, encontrado = 0;

  for (i = 0; i < l->N; i++) {
    if (l->val[i] == val)
      return 0;
  }

  return 1;
}

int eh_ord(LISTA *l) {
  int i;

  for (i = 0; i < l->N - 1; i++) {
    if (l->val[i] > l->val[i + 1])
      return 0;
  }

  return 1;
}

void gera_lista(LISTA *l, int inicio, int fim) {
  if (inicio > fim)
    return;

  ins(l, rand(), inicio);
  gera_lista(l, inicio + 1, fim);
}

int main() {
  LISTA l, g;

  //   criar_lista(&l);
  criar_lista(&g);
  ins(&l, 100, 1);
  ins(&l, 101, 5);
  ins(&l, 122, 10);
  ins(&l, 8, 20);
  ins(&l, 9, 9999);
  //   recup(&l, 1);
  // recup(&l, 2);
  // ret(&l, 2);
  // recup(&l, 2);
  // printf("%d", pertence(&l, 11));
  printa_lista(&l, 1);
  //   gera_lista(&g, 2, 10);
  //   printa_lista(&g, 2);
  return 0;
}
