#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int v;
  struct nodo *next;
} NODO;

typedef NODO *lista;

void criar(lista *pl) { *pl = NULL; }

int vazia(lista l) { return !l; }

int tam(lista l) {
  int i;
  NODO *aux;

  if (!l) {
    return 0;
  }

  for (i = 1, aux = l->next; aux != l; i++, aux = aux->next)
    ;

  return i;
}

void ins(lista *pl, int v, int k) {
  NODO *novo;

  if (k < 1 || k > tam(*pl) + 1) {
    puts("Pos inv");
    return;
  }

  novo = (NODO *)malloc(sizeof(NODO));
  if (!novo) {
    puts("Mem err");
    return;
  }

  novo->v = v;
  if (*pl == NULL) {
    // Lista vazia
    novo->next = novo;
    *pl = novo;
  } else {
    lista aux = *pl;
    if (k == tam(*pl) + 1) {
      // Novo ultimo
      *pl = novo;
    } else {
      // Intermediario
      for (; k > 1; k--, aux = aux->next)
        ;
    }
    novo->next = aux->next;
    aux->next = novo;
  }
}

int recup(lista l, int k) {
  if (k < 1 || k > tam(l)) {
    puts("Pos inv");
    exit(1);
  }

  for (; k > 0; l = l->next, k--)
    ;

  return l->v;
}

/*
    As 3 situacoes de insercao se refletem aqui, na hora de retirar
*/
void ret(lista *pl, int k) {
  NODO *aux, *aux2;

  if (k < 1 || k > tam(*pl)) {
    puts("Pos inv");
    return;
  }

  if (tam(*pl) == 1) {
    // Caso tenha apenas um nodo
    free(*pl);
    // Atualizando a referencia externa
    *pl == NULL;
  }
  // Casos intermediarios
  for (aux = *pl; k > 1; k--, aux = aux->next)
    ;
  aux2 = aux->next;
  aux->next = aux2->next;
  if (k == tam(*pl)) {
    // Caso seja o ultimo, eh necessario atualizar a referencia externa
    *pl = aux;
  }
  free(aux2);
}

void destruir(lista l) {
  NODO *aux, *aux2;

  aux = l;
  l = l->next;
  while (aux != l) {
    aux2 = l;
    l = l->next;
    free(aux2);
  }
  free(l);
}

int main() {
  lista l;
  criar(&l);
  printf("%s\n", vazia(l) ? "Lista vazia" : "Lista Nao esta vazia");
  printf("Tamanho: %d\n", tam(l));

  ins(&l, 10, 1);
  ins(&l, 20, 2);
  ins(&l, 30, 3);

  printf("Valor na pos 1: %d\n", recup(l, 1));

  return 0;
}