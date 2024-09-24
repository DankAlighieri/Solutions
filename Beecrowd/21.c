#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} NODE;

typedef NODE *lista;

void cria(lista *pl) { *pl = NULL; }

void ins(lista *pl, int v) {
  lista nodo, aux;
  nodo = (lista)malloc(sizeof(NODE));
  if (!nodo) {
    puts("mem err");
    exit(1);
  }

  nodo->val = v;
  nodo->next = NULL;

  if (!(*pl)) {
    (*pl) = nodo;
  } else {
    aux = *pl;
    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = nodo;
  }
}

void insRec(lista *pl, int N, int tot) {
  if (N < 1)
    return;
  lista nodo, aux;
  nodo = (lista)malloc(sizeof(NODE));
  if (!nodo) {
    puts("mem err");
    exit(1);
  }

  nodo->val = tot - N + 1;
  nodo->next = NULL;

  if (!(*pl)) {
    *pl = nodo;
  } else {
    lista aux = *pl;
    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = nodo;
  }

  insRec(pl, N - 1, tot);
}

void mostra(lista l) {
  int i;
  for (i = 1; l; l = l->next, i++)
    printf("%d : %d\n", i, l->val);
}

lista mergeSortedList(lista l1, lista l2) {
  lista l3 = (lista)malloc(sizeof(NODE));
  lista tail = l3;

  if (!novo || !l3) {
    puts("Mem err");
    exit(1);
  }

  while (l1 && l2) {
  lista novo = (lista)malloc(sizeof(NODE));

    if (l1->val < l2->val) {
      novo->val = l1->val;
      l1 = l1->next;
    } else {
      novo->val = l2->val;
      l2 = l2->next;
    }

    tail->next = novo;
    tail = tail->next;
  }

  while (l1) {
  lista novo = (lista)malloc(sizeof(NODE));
    novo->val = l1->val;
    l1 = l1->next;
    tail->next = novo;
    tail = tail->next;
  }

  while (l2) {
  lista novo = (lista)malloc(sizeof(NODE));
    novo->val = l2->val;
    l1 = l1->next;
    tail->next = novo;
    tail = tail->next;
  }

  tail->next = NULL;

  return l3->next;
}

int main() {
  lista list1, list2;
  cria(&list1);
  cria(&list2);
  ins(&list1, 1);
  ins(&list1, 3);
  ins(&list1, 5);
  ins(&list1, 9);
  insRec(&list2, 4, 4);
  // mostra(list1);
  // mostra(list2);

  mostra(mergeSortedList(list1, list2));
  return 0;
}