#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void cria(pilha *p) { *p = NULL; }

int vazia(pilha p) { return (!p); }

void push(pilha *p, int v) {
  pilha novo = (pilha)malloc(sizeof(node));
  novo->inf = v;
  novo->next = *p;
  *p = novo;
}

int top(pilha p) {
  if (!p) {
    puts("Pilha vazia");
  } else {
    return p->inf;
  }
}

void pop(pilha *p) {
  if (!(*p)) {
    puts("Pilha vazia");
  } else {
    pilha aux = *p;
    *p = (*p)->next;
    free(aux);
  }
}

int top_pop(pilha *p) {
  if (!p) {
    puts("Pilha vazia");
  } else {
    int v = (*p)->inf;
    pop(p);
    return v;
  }
}

void destruir(pilha *p) {
  pilha aux;
  while (*p) {
    aux = *p;
    *p = (*p)->next;
    free(aux);
  }
  *p = NULL;
}

int main() {
  pilha p;
  cria(&p);
  printf("%s\n", vazia(p) ? "Vazia" : "Nao vazia");
  for (int i = 0, v = 10; i < 10; i++, push(&p, v), v += 10)
    ;
  for (; p->next; printf("%d ", top_pop(&p)))
    ;
  putchar('\n');
  printf("%d\n", top(p));
  destruir(&p);
  printf("%s\n", vazia(p) ? "Vazia" : "Nao vazia");
  return 0;
}