#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *next;
} nodo;

typedef nodo *lista;

void cria(lista *l) { *l = NULL; }

int vazia(lista l) { return !l; }

int tam(lista l) {
  if (!l) {
    return 0;
  } else {
    int i = 1;
    lista aux = l->next;
    while (aux != l) {
      aux = aux->next;
      i++;
    }
    return i;
  }
}

void ins(lista *l, int k, int v) {
  if (k < 1 || k > tam(*l) + 1) {
    puts("Pos inv");
  } else {
    /*
        Casos de insercao
        - Lista vazia
        - Ultimo elemento
        - Resto
    */
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    novo->inf = v;
    if (!(*l)) {
      (*l) = novo;
      novo->next = novo;
    } else {
      lista aux = (*l);
      if (k == tam(*l) + 1)
        (*l) = novo;

      /* k > 1 para desconsiderar o fato de que o ponteiro *l aponta para o
      ultimo elemento */

      for (; k > 1; aux = aux->next, k--)
        ;
      novo->next = aux->next;
      aux->next = novo;
    }
  }
}

int recup(lista l, int k) {
  if (k < 1 || k > tam(l)) {
    puts("Pos inv");
  } else {
    for (; k > 1; l = l->next)
      ;
    return l->inf;
  }
}

void ret(lista *l, int k) {
  int tamanho = tam(*l);
  if (k < 1 || k > tamanho) {
    puts("Pos inv");
  } else {
    /*
        Condicoes de retirada
        - Elemtno unico
        - Ultimo no
        - Resto
    */

    if (tamanho == 1) {
      free(*l);
      *l = NULL;
    } else {
      nodo *remover, *aux = *l;
      int i = k;
      for (; i > 1; aux = aux->next, i--)
        ;
      remover = aux->next;
      aux->next = remover->next;
      if (k == tamanho) {
        *l = aux;
      }
      free(remover);
    }
  }
}

void destruir(lista l) {
  if (l) {
    nodo *aux;
    for (aux = l->next; aux != l; aux = aux->next)
      free(aux);
    free(aux);
  }
}

void mostra(lista l) {
  lista aux = l->next;
  do {
    printf("%d -> ", aux->inf);
    aux = aux->next;
  } while (aux != l->next);
  printf("NULL\n");
}

int main() {
  lista l;
  int k, v;

  cria(&l);
  //   printf("%s\n", vazia(l) ? "Vazia" : "Nao vazia");
  //   printf("%d\n", tam(l));

  for (int i = 1, v = 10; i <= 5; v += 10)
    ins(&l, i++, v);
  while (scanf("%d", &k), k) {
    scanf("%d", &v);
    ins(&l, k, v);
  }

  mostra(l);

  while (scanf("%d", &k), k) {
    ret(&l, k);
    mostra(l);
  }
}