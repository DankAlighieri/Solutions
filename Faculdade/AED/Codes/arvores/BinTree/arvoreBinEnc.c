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
  destruir(leafQueue);
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
      } else if (v > aux->info) {
        if (aux->right)
          aux = aux->right;
        else {
          setRight(aux, v);
          break;
        }
      } else
        break; // Nao eh permitido elementos identicos na arvore de busca
    } while (1);
  }
}

void fusionRemove(arvoreBin *a) {
  if (!(*a))
    return;

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
    // Atualizando o ponteiro para father
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

// Funcao do professor ** PRIORIDADE **
void remocaoPorFusao(arvoreBin *a) {
  if (*a) {
    arvoreBin tmp = *a;

    // Nao existe sub arvore a direita
    if (!((*a)->right)) {
      // Existe arvore a esquerda
      if ((*a)->left) {
        // Religando os ponteiros do pai
        (*a)->left->father = (*a)->father;
      }
      // Atualizando a referencia da raiz da arvore
      *a = (*a)->left;
      // Existe sub arvore direita
      // Nao existe sub arvore esquerda
    } else if ((*a)->left == NULL) {
      // Religando os ponteiros do pai da raiz da sub arvore direita
      (*a)->right->father = (*a)->father;
      // Atualizando a referencia da raiz da arvore
      *a = (*a)->right;
    } else {
      tmp = (*a)->left;
      // Procurando o nodo mais a direita da sub arvore esquerda
      while (tmp->right) {
        tmp = tmp->right;
      }
      // Fundindo ambas as arvores
      tmp->right = (*a)->right;
      // Atualizando o ponteiro do pai da arvore fundida
      tmp->right->father = tmp;
      // Voltando para a raiz
      tmp = *a;
      // Atualizando o ponteiro da raiz
      *a = (*a)->left;
    }
    free(tmp);
  }
}

void copyRemoval(arvoreBin *a) {
  if (!*a) {
    return;
  }
  int profundidade = 0;
  nodo *sucessorImediato, *aux;
  if ((*a)->right) {
    aux = (*a)->right;
    while (aux->left) {
      aux = aux->left;
      profundidade++;
    }
    aux->father->left = NULL;
    sucessorImediato = aux;
  } else {
    sucessorImediato = (*a)->left;
  }
  sucessorImediato->father = NULL;
  if ((*a)->father) {
    sucessorImediato->father = (*a)->father;
    if (isLeft((*a)))
      sucessorImediato->father->left = sucessorImediato;
    else
      sucessorImediato->father->right = sucessorImediato;
  }

  if (profundidade) {
    sucessorImediato->left = (*a)->left;
    if (sucessorImediato->left)
      sucessorImediato->left->father = sucessorImediato;
    sucessorImediato->right = (*a)->right;
    if (sucessorImediato->right)
      sucessorImediato->right->father = sucessorImediato;
  }

  free(*a);
  *a = sucessorImediato;
}

// Funcao do professor ** PRIORIDADE **
void remocaoPorCopia(arvoreBin *a) {
  if (*a) {
    arvoreBin tmp = *a;
    if (!((*a)->right)) {
      if ((*a)->left) {
        (*a)->left->father = (*a)->father;
        *a = (*a)->left;
      }
    } else if ((*a)->left == NULL) {
      (*a)->right->father = (*a)->father;
      *a = (*a)->right;
    } else {
      tmp = (*a)->right;
      while (tmp->left != NULL) {
        tmp = tmp->left;
      }
      (*a)->info = tmp->info;
      if (tmp->father == *a) {
        tmp->father->right = tmp->right;
        if (tmp->father->right)
          tmp->father->right->father = tmp->father;
      } else {
        tmp->father->left = tmp->right;
        if (tmp->right)
          tmp->father->left->father = tmp->father;
      }
    }
  }
}

int main() {

  // Declaração da árvore binária
  arvoreBin tree;

  // Criação da árvore com o nó raiz de valor 10
  makeTree(&tree, 15);

  // Inserindo elementos na árvore binária
  ins_ele(&tree, 30);
  ins_ele(&tree, 20);
  ins_ele(&tree, 40);
  ins_ele(&tree, 10);
  ins_ele(&tree, 5);
  ins_ele(&tree, 11);
  ins_ele(&tree, 12);

  // Testando percursos na árvore
  // printf("Pre-Order traversal: ");
  // preOrder(tree);
  // printf("\n");

  // printf("In-Order traversal: ");
  // inOrder(tree);
  // printf("\n");

  // printf("Post-Order traversal: ");
  // postOrder(tree);
  // printf("\n");

  // Testando busca em largura
  // printf("Busca em largura (Breadth-First Search): ");
  // buscaLargura(tree);
  // printf("\n");

  // fusionRemove(&tree);
  copyRemoval(&tree);

  printf("Busca em largura (Breadth-First Search): ");
  buscaLargura(tree);
  printf("\n");
  return 0;
}