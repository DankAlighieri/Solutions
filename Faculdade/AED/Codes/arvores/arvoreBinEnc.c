#include "arvoreBin.h"
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

arvoreBin father(arvoreBin a) { return a->father; }

int main() { return 0; }
