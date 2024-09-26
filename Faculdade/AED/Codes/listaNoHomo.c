#include <stdio.h>
#include <stdlib.>
#include <string.h>

#define INTGR 1
#define FLT 2
#define STRING 3

typedef struct nodo {
  int etype;
  union inf {
    int ival;
    float fval;
    char sval[20];
  } element;
  struct nodo *next;
  struct nodo *prev;
} nodo;

typedef nodo *lista;

void cria(lista *pl) { *pl = NULL; }

int tam(lista l) {
  int i = 1;
  while (l) {
    i++;
    l = l->next;
  }
}

int pertence(lista, union inf, int);

void ins(lista *l, int k, union inf v, int etype) {
  int t = tam(*l);
  if (k < 1 || k > t + 1) {
    puts("Pos inv");
    return;
  }
  if (pertence(*l, v, etype)) {
    puts("O valor ja se encontra na lista");
  } else {
    /*
        Condicoes de insercao
        - Lista vazia
        - Ultimo nodo
        - Nodo intermediario
    */

    lista novo = (nodo *)malloc(sizeof(nodo));
    if (!novo) {
      puts("Mem err");
      return;
    }
    novo->etype = etype;
    novo->element = v;

    if (!(*l)) {
      *l = novo->prev = novo->next = novo;
    } else {
      nodo *aux;
      if (k < t / 2) {
        for (aux = *l; k > 1; aux = aux->next, k--)
          ;
      } else {
        for (aux = *l; k <= t; aux = aux->prev, k++)
          ;
      }
      novo->next = aux->next;
      novo->prev = aux;
      aux->next = novo;
      novo->next->prev = novo;
      if (k == t + 1)
        *l = novo;
    }
  }
}

int pertence(lista l, union inf v, int etype) {
  if (!l)
    return 0;
  else {
    lista aux = l;
    do {
        if (aux->etype == etype &&
        ((INTGR == etype && aux->element.ival==v.ival) || 
        (FLT == etype && aux->element.fval == v.fval) ||
        (STRING == etype && !strcmp(aux->element.sval, v.sval)))) {
            return 1;
        }
        aux = aux->next;
    } while (aux != l);
    return 0;
  }
}

int main() { return 0; }