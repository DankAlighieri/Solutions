#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *next;
  struct nodo *ant;
} NODO;
typedef NODO *lista;
void cria(lista *pl) { *pl = NULL; }

int vazia(lista l) { return !l; }
int tam(lista l) {
  int i;

  for (i = 0; l; l = l->next, i++)
    ;
  return i;
}

void ins(lista *pl, int v, int k) {
  lista novo;

  if (k < 1 || k > tam(*pl) + 1) {
    puts("Pos inv");
    return;
  }

  novo = (lista)malloc(sizeof(NODO));

  if (!novo) {
    puts("Mem err");
    return;
  }

  novo->inf = v;

  /*
      Situacoes de insercao

      1. Lista vazia
      2. Primeiro elemento
      3. Elemento intermediario
      4. Ultimo elemento
  */

  // Lista vazia
  if (k == 1) {

    // eh necessario atribuir novo a pl!
    novo->next = *pl;
    novo->ant = NULL;
    *pl = novo;
    // Caso tenho mais de um elemento
    if ((*pl)->next) {
      (*pl)->next->ant = novo;
    }
  } else {
    lista aux;

    for (aux = *pl; k > 2; k--, aux = aux->next)
      ;
    // Caso seja o ultimo elemento
    novo->next = aux->next;
    novo->ant = aux;
    aux->next = novo;
    if (novo->next) {
      // Caso nao seja o ultimo elemento
      novo->next->ant = novo;
    }
  }
}

int recup(lista l, int k) {
  if (k < 1 || k > tam(l)) {
    puts("Pos inv");
    return 1;
  }

  for (; k > 1; k--, l = l->next)
    ;
  return (l->inf);
}

int ret(lista *pl, int k) {
  lista aux;

  if (k < 1 || k > tam(*pl)) {
    puts("Pos inv");
    return 1;
  }

  if (k == 1) {
    // elemento unico
    aux = *pl;
    *pl = (*pl)->next;
    if ((*pl)->next) {
      *pl = (*pl)->next;
    }
    free(aux);
  } else {
    lista aux2;

    for (aux = *pl; k > 2; k--, aux = aux->next)
      ;
    aux2 = aux->next;
    aux->next = aux2->next;
    if (aux2->next) {
      aux->next->ant = aux;
    }
    free(aux2);
  }
}
int destruir(lista l) {
  lista aux;
  while (l) {
    aux = l;
    l = l->next;
    free(aux);
  }
}

void mostra(lista l) {
  for (int count = 1; l != NULL; count++, l = l->next) {
    printf("%d: %d\n", count, l->inf);
  }
}

int main() {
  lista l;
  cria(&l);
  printf("%s\n", vazia(l) ? "Lista esta vazia" : "Lista nao esta vazia");
  printf("Tamanho da lista: %d\n", tam(l));
  
  puts("Inserindo");
  ins(&l, 10, 1);
  ins(&l, 20, 2);
  ins(&l, 30, 3);
  ins(&l, 40, 1);

  mostra(l);

  puts("Retirando");
  ret(&l, 1);

  mostra(l);

  destruir(l);
  
  return 0;
}