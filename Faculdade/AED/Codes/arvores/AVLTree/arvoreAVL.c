#include "arvoreAVL.h"
#include "filaAVL.h"
#include <math.h>
#include <stdio.h>
#include <stdlib>

void makeTree(arvoreAVL *a, int x) {
  *a = (arvoreAVL)malloc(sizeof(nodo));
  if (!(*a))
    return;
  (*a)->info = x;
  (*a)->altd = (*a)->alte = 0;
  (*a)->left = (*a)->right = NULL;
}

void setLeft(arvoreAVL a, int x) {
  a->left = (arvoreAVL)malloc(sizeof(nodo));
  if (!(a->left))
    return;
  a->left->info = x;
  a->left->altd = a->left->alte = 0;
  a->left->left = a->left->right = NULL;

  a->alte = 1;
}

void setRight(arvoreAVL a, int x) {
  a->right = (arvoreAVL)malloc(sizeof(nodo));
  if (!(a->right))
    return;
  a->right->info = x;
  a->right->altd = a->right->alte = 0;
  a->right->left = a->right->right = NULL;

  a->altd = 1;
}

int info(arvoreAVL a) {
  if (!a) {
    return -1;
  }

  return a->info;
}

arvoreAVL left(arvoreAVL a) { return a->left; }

arvoreAVL right(arvoreAVL a) { return a->right; }

void buscaLargura(arvoreAVL a) {
  avlQueue leafQueue;
  cria(&leafQueue);
  if (a) {
    ins(leafQueue, a);
  }
  while (leafQueue->inicio) {
    nodo *leaf = cons(leafQueue);
    printf("%d ", cons(leafQueue)->info);
    if (left(leaf))
      ins(leafQueue, left(leaf));
    if (right(leaf))
      ins(leafQueue, right(leaf));
    ret(leafQueue);
  }
  destroy(leafQueue);
}

void preOrder(arvoreAVL a) {
  if (a) {
    printf("%d", a->info);
    preOrder(a->left);
    preOrder(a->right);
  }
}

void inOrder(arvoreAVL a) {
  if (a) {
    inOrder(a->left);
    printf("%d", a->info);
    inOrder(a->right);
  }
}

void postOder(arvoreAVL a) {
  if (a) {
    postOder(a->left);
    postOder(a->right);
    printf("%d", a->info);
  }
}

void rotacaoEsq(arvoreAVL *a) {
  arvoreAVL novaRaiz, novoNeto;
  // Salvando endereco da nova raiz (no a direita da antiga raiz)
  novaRaiz = (*a)->right;
  // Salvando endereco do no a esquerda da nova raiz
  novoNeto = novaRaiz->left;
  // ligando novo no, caso exista, a a antiga raiz
  (*a)->right = novoNeto;
  // Ligando nova raiz a antiga raiz
  novaRaiz->left = (*a);
  // Caso nao existe sub arvore direita
  if (!(*a)->right)
    (*a)->altd = 0;

  // Verificar altura direita e atribuir a raiz da sub arvore
  else if ((*a)->right->alte > (*a)->right->altd)
    (*a)->altd = (*a)->right->alte + 1;
  else
    (*a)->altd = (*a)->right->altd + 1;
  // Verificar altura esquerda e atribuir a raiz da sub arvore
  if ((*a)->left->alte > (*a)->left->altd)
    (*a)->alte = (*a)->left->alte + 1;
  else
    (*a)->alte = (*a)->left->altd + 1;
  *a = novaRaiz;
}

void rotacaoDir(arvoreAVL *a) {
  arvoreAVL novaRaiz, novoNeto;
  novaRaiz = (*a)->left;
  novoNeto = novaRaiz->right;
  (*a)->right = novoNeto;
  novaRaiz->right = (*a);
  if (!(*a)->left)
    (*a)->alte = 0;
  else if ((*a)->left->alte > (*a)->left->altd)
    (*a)->alte = (*a)->left->alte + 1;
  else
    (*a)->alte = (*a)->left->altd + 1;
  if ((*a)->right->alte > (*a)->right->altd)
    (*a)->altd = (*a)->right->alte + 1;
  else
    (*a)->altd = (*a)->right->altd + 1;
  *a = novaRaiz;
}

void balanceamento(arvoreAVL *a) {
  int FBp, FBf;
  FBp = (*a)->altd - (*a)->alte;
  if (FBp == 2) {
    FBf = (*a)->right->altd - (*a)->right->alte;
    if (FBf < 0) {
      rotacaoDir(&((*a)->right));
    }
    rotacaoEsq(a);
  } else if (FBp == -2) {
    FBf = (*a)->left->altd - (*a)->left->alte;
    if (FBf > 0) {
      rotacaoEsq(&((*a)->left));
    }
    rotacaoDir(a);
  }
}

/* TODO */

int height(nodo *n) { return n ? max(n->alte, n->altd) + 1 : 0; }

void updateHeight(nodo *n) {
  if (n) {
    n->alte = n->left ? height(n->left) : 0;
    n->altd = n->right ? height(n->right) : 0;
  }
}

void ins_ele(arvoreAVL *a, int x) {
  if (!a) {
    makeTree(a, x);
  } else {
    arvoreAVL aux = *a;
    int FB;
    do {
      /*
        TODO

        - Implementar incremento de altura 💹
        - Verificacao de balanceamento ✅
      */
      if (x < aux->info) {
        if (aux->left) {
          aux = aux->left;
        } else {
          setLeft(aux, x);
          updateHeight(aux);
          break;
        }
      } else if (x > aux->info) {
        if (aux->right) {
          aux = aux->right;
        } else {
          setRight(aux, x);
          updateHeight(aux);
          break;
        }
      } else
        break;
    } while (1);

    while (aux) {
      updateHeight(aux);
      balanceamento(&aux);
    }
  }
}

int main(int argc, char **argv) { return 0; }