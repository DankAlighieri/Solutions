#include "arvoreAVL.h"
#include "filaAVL.h"
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

// void rotacao_direita(arvoreAVL *a) {
//   arvoreAVL aux1, aux2;
//   aux1 = (*a)->left;
//   aux2 = aux1->right;
//   (*a)->left = aux2;
//   aux1->right = (*a);
//   if ((*a)->left == NULL) {
//     (*a)->alte = 0;
//   } else if ((*a)->left->alte > (*a)->left->altd) {
//     (*a)->alte = (*a)->left->alte + 1;
//   } else {
//     (*a)->alte = (*a)->left->altd + 1;
//   }
//   if ((*a)->right->alte > (*a)->right->altd) {
//     (*a)->altd = (*a)->right->alte + 1;
//   } else
//     (*a)->altd = (*a)->right->altd + 1;
//   *a = aux1;
// }

// void rotacao_esquerda(arvoreAVL *a) {
//   arvoreAVL novaRaiz, novoNeto;
//   novaRaiz = (*a)->right;
//   novoNeto = novaRaiz->left;
//   (*a)->right = novoNeto;
//   novaRaiz->left = (*a);
//   if (!(*a)->right) {
//     (*a)->altd = 0;
//   } else if ((*a)->right->alte > (*a)->right->altd)
//     (*a)->altd = (*a)->right->alte + 1;
//   else
//     (*a)->altd = (*a)->right->altd + 1;
//   if ((*a)->left->alte > (*a)->left->altd)
//     (*a)->alte = (*a)->left->alte + 1;
//   else
//     (*a)->alte = (*a)->left->altd + 1;
//   *a = novaRaiz;
// }

/* TODO */

void rotacaoDir(arvoreAVL *a) {}

void rotacaoEsq(arvoreAVL *a) {}

void balanceamento(arvoreAVL *a) {}

/* TODO */

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
          aux->alte++;
          FB = aux->altd - aux->alte;
          if (FB == 2 || FB == -2) {
            balanceamento(a);
          }
          break;
        }
      } else if (x > aux->info) {
        if (aux->right) {
          aux = aux->right;
        } else {
          setRight(aux, x);
          aux->altd++;
          FB = aux->altd - aux->alte;
          if (FB == 2 || FB == -2) {
            balanceamento(a);
          }
          break;
        }
      } else
        break;
    } while (1);
  }
}

int main(int argc, char **argv) { return 0; }