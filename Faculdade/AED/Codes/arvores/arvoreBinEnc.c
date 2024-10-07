#include "arvoreBin.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void makeTree(arvoreBin *a, int x) {
  *a = (arvoreBin)malloc(sizeof(nodo));
  if (!(*a))
    puts("Mem err");
  else {
    (*a)->info = x;
    (*a)->father = (*a)->right = (*a)->left = NULL;
  };
}

void setLeft(arvoreBin a, int x) {
  a->left = malloc(sizeof(nodo));
  if (!a->right)
    puts("mem err");
  else {
    a->left->info = x;
    a->left->left = a->left->right = NULL;
    a->left->father = a;
  }
}

void setRight(arvoreBin a, int x) {
  a->right = malloc(sizeof(nodo));
  if (!a->right)
    puts("mem err");
  else {
    a->right->info = x;
    a->right->left = a->right->right = NULL;
    a->right->father = a;
  }
}

int isLeft(arvoreBin a) {
  if (a->father) {
    if (a == a->father->left)
      return 1;
  }
  return 0;
}

int isRight(arvoreBin a) {
  if (a->father)
    return !isLeft(a);
  return 0;
}

int info(arvoreBin a) { return a->info; }

arvoreBin left(arvoreBin a) { return a->left; }

arvoreBin right(arvoreBin a) { return a->right; }

arvoreBin brother(arvoreBin a) {
  if (a->father) {
    if (isLeft(a)) {
      return a->father->right;
    }
    return a->father->left;
  }
  return NULL;
}

void buscaLargura(arvoreBin a) {
  fila leafQueue;
  cria(&leafQueue);
  if (a) {
    ins(leafQueue, a);
  }
  while (!vazia(leafQueue)) {
    printf("%d ", cons(leafQueue)->info);
    if (left(cons(leafQueue)))
      ins(leafQueue, left(cons(leafQueue)));
    else if (right(cons(leafQueue)))
      ins(leafQueue, right(cons(leafQueue)));
    ret(leafQueue);
  }
}

void preOrder(arvoreBin a) {
  if (a) {
    printf("%d ", a->info);
    preOrder(a->left);
    preOrder(a->right);
  }
}
void inOrder(arvoreBin a) {
  if (a) {
    preOrder(a->left);
    printf("%d ", a->info);
    preOrder(a->right);
  }
}
void postOrder(arvoreBin a) {
  if (a) {
    preOrder(a->left);
    preOrder(a->right);
    printf("%d ", a->info);
  }
}

void ins_ele(arvoreBin *a, int v) {
  if (!a) {
    makeTree(a, v);
  } else {
    arvoreBin aux = *a;
    do {
      if (v < aux->info) {
        if (aux->left)
          aux = aux->left;
        else {
          setLeft(aux, v);
          break;
        }
      }
      if (v > aux->info) {
        if (aux->right)
          aux = aux->right;
        else {
          setRight(aux, v);
          break;
        }
      }
    } while (1);
  }
}

arvoreBin father(arvoreBin a) { return a->father; }

int main() { return 0; }
