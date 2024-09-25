#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int v;
  struct nodo *next;
} nodo;

typedef nodo *lista;

void cria(lista *l) { *l = NULL; }

int vazia(lista l) { return !l; }

int tam(lista l) {
  if (!l) {
    return 0;
  } else {
    int c = 1;
    while (l) {
      c++;
      l = l->next;
    }
    return c;
  }
}

void ins(lista *l, int k, int v) {
  if (k < 1 || k > tam(*l) + 1) {
    puts("pos inv");
    return;
  } else {
    nodo *novo = (lista)malloc(sizeof(nodo));

    if (!novo) {
      puts("Mem err");
      return;
    }

    /*
        Condicoes de insercao
        1 - Primeiro nodo
        2 - Resto
    */

    novo->v = v;

    if (k == 1) {
      // Caso a lista esteja vazia, ja apontara para nulo
      // Caso esteja preenchida, aponta para o antigo primeiro
      novo->next = *l;
      *l = novo;
    } else {
      lista aux;
      for (aux = *l; k > 2; aux = aux->next, k--)
        ;
      novo->next = aux->next;
      aux->next = novo;
    }
  }
}

void insRec(lista *l, int k, int v) {
  if (k < 1 || k > tam(*l) + 1) {
    puts("Pos inv");
  } else if (k == 1) {
    lista novo = (nodo *)malloc(sizeof(nodo));
    if (!novo) {
      puts("Mem err");
      return;
    }
    novo->v = v;
    novo->next = *l;
    *l = novo;
  } else {
    insRec(&((*l)->next), k - 1, v);
  }
}

int recup(lista l, int k) {
  if (k < 1 || k > tam(l)) {
    puts("pos inv");
    exit(0);
  } else {
    for (; k > 1; l = l->next, k--)
      ;
    return l->v;
  }
}

void ret(lista *l, int k) {
  if (k < 1 || k > tam(*l)) {
    puts("pos inv");
    exit(0);
  } else {
    lista aux, aux2;

    if (k == 1) {
      aux = *l;
      (*l) = aux->next;
      free(aux);
    } else {

      for (aux = *l; k > 2; aux = aux->next, k--)
        ;
      aux2 = aux->next;
      aux->next = aux2->next;
      free(aux2);
    }
  }
}

void mostra(lista l) {
  for (int i = 1; l; l = l->next) {
    printf("%d : %d\n", i++, l->v);
  }
}

int pertence(lista l, int v) {
  if (!l) {
    puts("Lista vazia");
  } else {
    while (l) {
      l = l->next;
      if (l->v == v) {
        return 1;
      }
    }
    return 0;
  }
}

int eh_ord(lista l) {
  if (!l || !(l->next))
    return 1;
  if (l->v > l->next->v) {
    return 0;
  }
  return eh_ord(l->next);
}

void geraRec(lista *l, int inicio, int fim) {
  if (inicio > fim) {
    return;
  }
  lista novo = (nodo *)malloc(sizeof(nodo));
  novo->v = inicio;
  novo->next = *l; 
  *l = novo;
  geraRec(&((*l)->next), inicio + 1, fim);
}

// [*l] -> null  [*l] -> null \\ [novo]->[*l]->next \\ []; 
int main() {
  lista l;
  cria(&l);
  // printf("%s\n", vazia(l) ? "Lista vazia" : "Lista preenchida");
  // for (int i = 1, v = 10; i <= 5; v += 10) {
  //   ins(&l, i++, v);
  // }
  // //   mostra(l);
  // ret(&l, 1);

  geraRec(&l, 1, 20);
  mostra(l);
}