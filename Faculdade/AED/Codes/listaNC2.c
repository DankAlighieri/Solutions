#include <stdio.h>
#include <stdlib.h>

// Lista encadeada simples com no cabecalho
typedef struct nodo {
  int inf;
  struct nodo *next;
} nodo;

typedef nodo *lista;

void cria(lista *l) {
  *l = (nodo *)malloc(sizeof(nodo));
  if (!(*l)) {
    puts("Mem err");
    return;
  }
  (*l)->inf = 0;
  (*l)->next = NULL;
}

int vazia(lista l) { return !l->inf; }

int tam(lista l) { return l->inf; }

void ins(lista l, int k, int v) {
  if (k < 1 || k > tam(l) + 1) {
    puts("Pos inv");
  } else {
    lista novo = (nodo *)malloc(sizeof(nodo));
    if (!novo) {
      puts("Mem err");
      return;
    }
    /*
        Condicoes de insercao
        -> Primeiro nodo
        -> Resto dos nodos
    */
    novo->inf = v;
    l->inf++;
    if (k == 1) {
      novo->next = l->next;
      l->next = novo;
    } else {
      nodo *aux;
      for (aux = l->next; k > 2; aux = aux->next, k--)
        ;
      novo->next = aux->next;
      aux->next = novo;
    }
  }
}

int recup(lista l, int k) {
  if (!l->inf || k < 1 || k > l->inf) {
    puts("Vazia ou pos inv");
  } else {
    l = l->next;
    for (; k > 1; k--, l = l->next)
      ;
    return l->inf;
  }
}

void ret(lista l, int k) {
  if (!l->inf || k < 1 || k > l->inf) {
    puts("Vazia ou pos inv");
  } else {
    l->inf--;
    lista aux2;

    if (k!=1) {
        for (l = l->next; k > 2; l = l->next, k--)
      ;
    }
    aux2 = l->next;
    l->next = aux2->next;
    free(aux2);
  }
}

void destruir(lista l) {
    lista aux;
    while (l) {
        aux = l;
        l = l->next;
        free(aux);
    }
}

void mostra(lista l) {
  l = l->next;
  while (l) {
    printf("%d -> ", l->inf);
    l = l->next;
  }
  printf("NULL\n");
}

int main() {
  lista l;
  cria(&l);
  printf("%s\n", vazia(l) ? "Vazia" : "Nao vazia");
  for (int i = 1, v = 10; i < 5; v += 10) {
    ins(l, i++, v);
  }
  ins(l, 2, 11);
  //   printf("%d\n", recup(l, 2));
  ret(l, 1);

  mostra(l);

  return 0;
}