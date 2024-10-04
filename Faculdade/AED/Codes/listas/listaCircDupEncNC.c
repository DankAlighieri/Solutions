#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *ant;
  struct nodo *next;
} NODO;

typedef NODO *lista;

void cria(lista *l) {
  *l = (lista)malloc(sizeof(NODO));
  if (!(*l)) {
    puts("Mem err");
    return;
  }

  (*l)->inf = 0;
  (*l)->ant = (*l)->next = *l;
}

int vazia(lista l) { return (l->inf == 0); }
int tam(lista l) { return l->inf; }
void ins(lista l, int v, int k) {
  lista novo;
  if (k < 1 || k > tam(l) + 1) {
    puts("Pos inv");
    return;
  }

  novo = (lista)malloc(sizeof(NODO));

  if (!novo) {
    puts("Mem err");
    return;
  }

  l->inf++;
  novo->inf = v;
  for (; k > 1; k--, l = l->next)
    ;
  novo->next = l->next;
  l->next = novo;
  novo->ant = l;
  novo->next->ant = novo;
}
int recup(lista l, int k) {
  if (k < 1 || k > l->inf) {
    puts("Pos inv");
    return 1;
  }

  for (; k > 0; k--, l = l->next)
    ;

  return (l->inf);
}
void ret(lista l, int k) {
  if (k < 1 || k > l->inf) {
    puts("Pos inv");
    return;
  }
  l->inf--;
  for (; k > 0; k--, l = l->next)
    ;
  l->ant->next = l->next;
  l->next->ant = l->ant;
  free(l);
}
void destruir(lista l) {
  lista aux = l->next;
  while (aux != l) {
    NODO *aux2;
    aux2 = l;
    aux = aux->next;
    free(aux2);
  }
  free(l);
}
void mostra(lista l) {
  lista aux = l->next;
  int c = 1;
  while (aux != l) {
    printf("%d : %d\n", c++, aux->inf);
    aux = aux->next;
  }
}

int main() {
  lista l;
  cria(&l);
  printf("%s\n", vazia(l) ? "A lista esta vazia" : "A lista nao esta vazia");
  printf("Tamanho: %d\n", tam(l));

  ins(l, 10, 1);
  ins(l, 20, 2);
  ins(l, 30, 3);

  mostra(l);

  printf("Elemento na pos 1: %d\n", recup(l, 1));

  puts("Removendo 1");
  ret(l, 1);
  mostra(l);

  destruir(l);

  return 0;
}