#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *next;
} NODO;

typedef NODO *lista;

void cria_lista(lista *pl) {
  *pl = (NODO *)malloc(sizeof(NODO));
  if (!*pl) {
    puts("Erro de memoria!");
    exit(1);
  }

  (*pl)->inf = 0;
  (*pl)->next = NULL;
}

int eh_vazia(lista l) { return l->inf == 0; }

int tam(lista l) { return l->inf; }

void ins(lista l, int v, int k) {
  int tamanho = tam(l);
  NODO *novo, *aux;

  if (k < 1 || k > tamanho + 1) {
    puts("Posicao invalida");
    exit(2);
  }

  novo = (NODO *)malloc(sizeof(NODO));
  if (!novo) {
    puts("Erro de memoria!");
    exit(1);
  }

  novo->inf = v;

  for (aux = l; k > 1; k--, aux = aux->next)
    ;

  novo->next = aux->next;
  aux->next = novo;
  l->inf++;
}

int recup(lista l, int k) {
  int tamanho = tam(l);

  if (k < 1 || k > tamanho) {
    puts("Posicao invalida");
    exit(2);
  }

  for (; k > 0; k--) {
    l = l->next;
  }

  return l->inf;
}

void ret(lista l, int k) {
  int tamanho = tam(l);
  NODO *aux, *aux2;

  if (k < 1 || k > l->inf) {
    puts("Posicao invalida");
    exit(2);
  }

  for (aux = l; k > 1; k--, aux = aux->next)
    ;
  aux2 = aux->next;
  aux->next = aux2->next;
  free(aux2);
  l->inf--;
}

void destruir(lista l) {
  NODO *aux;

  while (l) {
    aux = l;
    l = l->next;
    free(aux);
  }
}

void mostrar_Lista(lista l) {
  int count = 0;
  l = l->next;
  while (l) {
    count++;
    printf("%d : %d\n", count, l->inf);
    l = l->next;
  }
}

int main() {
  lista l;
  cria_lista(&l);
  printf("Eh vazia? -> %s\n", eh_vazia(l) ? "Esta Vazia" : "Nao esta vazia");

  printf("Tamanho: %d\n", tam(l));

  ins(l, 10, 1);
  ins(l, 20, 2);
  ins(l, 30, 3);

  puts("Mostrando");
  mostrar_Lista(l);
  puts("Removendo");
  ret(l, 3);

  puts("Mostrando dnv");
  mostrar_Lista(l);
  return 0;
}