#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *next;
  struct nodo *prev;
} nodo;

typedef nodo *lista;

void cria(lista *l) {
  // Necessario reservar memoria para o No cabecalho

  *l = (nodo *)malloc(sizeof(nodo));
  if (!(*l)) {
    puts("Mem err");
    return;
  }
  (*l)->inf = 0;
  (*l)->next = (*l)->prev = *l; // Fechando o circulo
}
int vazia(lista l) { return !l->inf; }
int tam(lista l) { return l->inf; }
void ins(lista l, int k, int v) {
  if (k < 1 || k > l->inf + 1) {
    puts("Pos inv");
  } else {
    nodo *aux, *novo = (nodo *)malloc(sizeof(nodo));
    if (!novo) {
      puts("Mem err");
      return;
    }
    novo->inf = v;
    l->inf++;
    // Apenas umas situacao de insercao
    for (aux = l->next; k > 2; aux = aux->next, k--)
      ;
    novo->next = aux->next;
    aux->next = novo;
    novo->prev = aux;
    novo->next->prev = novo;
  }
}
int recup(lista l, int k) {
  if (k < 1 || k > l->inf) {
    puts("Pos inv");
  } else {
    // Necessario pular o no cabecalho na durante a busca
    for (; k > 0; l = l->next, k--)
      ;
    return l->inf;
  }
}
void ret(lista l, int k) {
  if (k < 1 || k > l->inf) {
    puts("Pos inv");
  } else {
    l->inf--;
    for (; k > 0; k--, l = l->next)
      ;
    l->next->prev = l->prev;
    l->prev->next = l->next;
    free(l);
  }
}
void destruir(lista l) {
  nodo *aux = l, *temp;
  while (aux != l->prev) {
    temp = aux;
    aux = aux->next;
    free(temp);
  }
  free(aux);
}

void inverterLista(lista l) {
    int i = l->inf;
    if (i > 1) {
        nodo *aux;
        for (i++; i; l = l->prev, i--) {
            aux = l->prev;
            l->prev = l->next;
            l->next = aux;
        }
    }
}

void mostra(lista l) {
  int t = l->inf;
  while (t--) {
    l = l->next;
    printf("%d -> ", l->inf);
  }
  puts("NULL");
}

int main() {
  lista l;

  cria(&l);
  //   printf("%s\n\n", vazia(l) ? "Vazia" : "Nao vazia");
  //   printf("Tam = %d\n\n", tam(l));
  for (int i = 1, v = 10; i <= 5; ins(l, i++, v), v += 10)
    ;
  //   printf("Tam = %d\n\n", tam(l));

  mostra(l);
  int v;
  inverterLista(l);
  mostra(l);
  // while (scanf("%d", &v), v) {
  //   ret(l, v);
  //   mostra(l);
  // }

  destruir(l);
  return 0;
}