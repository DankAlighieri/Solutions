#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *next;
  struct nodo *prev;
} nodo;

typedef nodo *lista;

void cria(lista *l) { *l = NULL; }
int vazia(lista l) { return !l; }

int tam(lista l) {
  // if (!l) {
  //   return 0;
  // }
  // return tam(l->next) + 1;

  // int cont = 0;
  // for (; l; cont++, l = l->next);
  // return cont;

  int cont;
  for (cont = 0; l; cont++, l = l->next)
    ;
  return cont;
}

void ins(lista *l, int k, int v) {
  /*
    Ref externa aponta para o primeiro nodo
    Casos de insercao
    - lista vazia
    - Primeiro nodo
    - Ultimo nodo
    - Resto
  */

  if (k < 1 || k > tam(*l) + 1) {
    puts("Pos inv");
  } else {
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    novo->inf = v;

    // Caso lista vazia ou primeiro nodo
    if (k == 1) {
      // *l = NULL ou *l = nodo1
      /*
        Fazendo novo->next = *l tem-se novo->next = NULL ou novo->next = nodo1
      */
      novo->prev = NULL;
      novo->next = *l;
      *l = novo;
      // Caso lista nao esteja vazia
      if ((*l)->next) {
        // *l->[novo1]<-[nodo1Antigo]
        (*l)->next->prev = novo;
      }
    } else { // Caso ultimo ou algum outro nodo
      lista aux;
      for (aux = *l; k > 2; aux = aux->next, k--)
        ;
      novo->next = aux->next;
      aux->next = novo;
      novo->prev = aux;
      if (novo->next) {
        novo->next->prev = novo;
      }
    }
  }
}
int recup(lista l, int k) {
  if (k < 1 || k > tam(l) + 1) {
    puts("Pos inv");
  } else {
    for (; k > 1; l = l->next, k--)
      ;
    return l->inf;
  }
}
void ret(lista *l, int k) {
  if (k < 1 || k > tam(*l) + 1) {
    puts("Pos inv");
  } else {
    nodo *procura;
    if (k == 1) {
      procura = *l;
      *l = (*l)->next;
      if (*l) {
        (*l)->prev = NULL;
      }
      free(procura);
    } else {
      nodo *remove;
      for (procura = (*l)->next; k > 2; procura = procura->next, k--)
        ;
      procura->prev->next = procura->next;
      if (procura->next) {
        procura->next->prev = procura->prev;
      }
      free(procura);
    }
  }
}

void mostra(lista l) {
  if (!l) {
    puts("NULL");
    return;
  }
  printf("%d -> ", l->inf);
  mostra(l->next);
}

void destruir(lista l) {
  if (!l) {
    return;
  }
  nodo *aux = l;
  free(aux);
  destruir(l->next);
}

void inverterLista(lista *l) {
  if (*l) {
    nodo *aux;
    do {
      aux = (*l)->next;
      (*l)->next = (*l)->prev;
      (*l)->prev = aux;
      if (aux) {
        *l = aux;
      }
    } while (aux);
  }
}

int main() {
  lista l;

  cria(&l);
  // printf("%s\n\n", vazia(l) ? "Vazia" : "Nao vazia");
  // printf("Tam = %d\n\n", tam(l));
  for (int i = 1, v = 10; i <= 5; ins(&l, i++, v), v += 10)
    ;
  // printf("Tam = %d\n\n", tam(l));

  mostra(l);
  int v;
  while (scanf("%d", &v), v) {
    ret(&l, v);
    mostra(l);
  }

  destruir(l);
  return 0;
}