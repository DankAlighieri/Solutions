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
  if (!a->left)
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

void buscaLargura(arvoreBin a) {
  fila leafQueue;
  cria(&leafQueue);
  if (a) {
    ins(leafQueue, a);
  }
  while (!vazia(leafQueue)) {
    nodo *auxLeaf = cons(leafQueue);
    printf("%d ", auxLeaf->info);
    if (left(auxLeaf))
      ins(leafQueue, left(auxLeaf));
    if (right(auxLeaf))
      ins(leafQueue, right(auxLeaf));
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
    inOrder(a->left);
    printf("%d ", a->info);
    inOrder(a->right);
  }
}
void postOrder(arvoreBin a) {
  if (a) {
    postOrder(a->left);
    postOrder(a->right);
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
      else if (v > aux->info) {
        if (aux->right)
          aux = aux->right;
        else {
          setRight(aux, v);
          break;
        }
      } else break;
    } while (1);
  }
}

void fusionRemove(arvoreBin *a) {
  if (!(*a)) {
    return;
  } else {
    // Nova raiz
    nodo *fthr = (*a)->left;
    // Sub arvore a ser fundida
    arvoreBin rightTree = (*a)->right;

    // Caso a raiz antiga tenho um pai
    if (father(*a)) {
      // Ligando antigo pai a nova raiz
      if (isLeft(*a))
        (*a)->father->left = fthr ? fthr : rightTree;
      else
        (*a)->father->right = fthr ? fthr : rightTree;
    }

    // Se existir apenas a subarvore direita
    if (!fthr) {
      fthr = (*a)->right;
      if (fthr) {
        fthr->father = (*a)->father;
      }
    } else {
      fthr->father = (*a)->father;
      nodo *aux = fthr;
      // Procurando folha mais a direita
      while (aux->right) {
        aux = aux->right;
      }
      // Linkando nova subarvore
      aux->right = rightTree;
      if (rightTree) {
        rightTree->father = aux;
      }
    }
    free(*a);
    *a = fthr;
  }
}

int main() {

  // Declaração da árvore binária
  arvoreBin tree;

  // Criação da árvore com o nó raiz de valor 10
  makeTree(&tree, 10);

  // Inserindo elementos na árvore binária
  ins_ele(&tree, 20);
  ins_ele(&tree, 11);
  ins_ele(&tree, 15);
  ins_ele(&tree, 14);
  ins_ele(&tree, 15);
  ins_ele(&tree, 30);

  // Testando percursos na árvore
  printf("Pre-Order traversal: ");
  preOrder(tree);
  printf("\n");

  printf("In-Order traversal: ");
  inOrder(tree);
  printf("\n");

  printf("Post-Order traversal: ");
  postOrder(tree);
  printf("\n");

  // Testando busca em largura
  // printf("Busca em largura (Breadth-First Search): ");
  // buscaLargura(tree);
  // printf("\n");

  fusionRemove(&tree);

  printf("Busca em largura (Breadth-First Search): ");
  buscaLargura(tree);
  printf("\n");
  return 0;
}