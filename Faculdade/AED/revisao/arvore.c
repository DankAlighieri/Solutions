#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  struct nodo *left, *right, *father;
  int info, alte, altd;
} nodo;

typedef nodo *arvore;

typedef struct _node {
  arvore leaf;
  struct _node *next;
} node;

typedef struct {
  node *inicio;
  node *fim;
} descritor;

typedef descritor *fila;

// Fila
void criaFila(fila *f) {
  *f = (fila)malloc(sizeof(descritor));
  if (!(*f))
    return;
  (*f)->inicio = (*f)->fim = NULL;
}
void ins(fila f, arvore leaf) {
  node *novo = (node *)malloc(sizeof(node));
  if (novo)
    return;
  novo->leaf = leaf;
  novo->next = NULL;
  if (!(f->inicio)) {
    f->inicio = novo;
  } else {
    f->fim->next = novo;
  }
  f->fim = novo;
}
void ret(fila f) {
  if (!f)
    return;
  node *aux = f->inicio;
  f->inicio = aux->next;
  if (!f->inicio) {
    f->fim = f->inicio;
  }
  free(aux);
}
arvore cons(fila f) { return f->inicio->leaf; }
void destroy(fila f) {
  if (!f)
    return;
  node *aux;
  while (f) {
    aux = f->inicio;
    f->inicio = aux->next;
    free(aux);
  }
}

// Arvore
void maketree(arvore *a, int x) {
  *a = (nodo *)malloc(sizeof(nodo));
  if (!(*a))
    return;
  (*a)->father = (*a)->left = (*a)->right = NULL;
  (*a)->alte = (*a)->altd = 0;
  (*a)->info = x;
}

void setLeft(arvore a, int x) {
  a->left = (nodo *)malloc(sizeof(nodo));
  if (!(a->left))
    return;
  a->left->info = x;
  a->left->left = a->left->right = NULL;
  a->left->father = a;
  a->alte++;
}

void setRight(arvore a, int x) {
  a->right = (nodo *)malloc(sizeof(nodo));
  if (!(a->right))
    return;
  a->right->info = x;
  a->right->left = a->right->right = NULL;
  a->right->father = a;
  a->altd++;
}

int info(arvore a) { return a->info; }

arvore left(arvore a) { return a->left; }

arvore right(arvore a) { return a->right; }

int isLeft(arvore a) {
  if (a->father) {
    if (a->father->left == a) {
      return 1;
    }
  }
  return 0;
}

int isRight(arvore a) {
  if (a->father) {
    if (!isLeft(a)) {
      return 1;
    }
  }
  return 0;
}

arvore brother(arvore a) {
  if (a->father) {
    return isLeft(a) ? a->father->right : a->father->left;
  }
  return NULL;
}

arvore father(arvore a) { return a->father; }

void buscaLargure(arvore a) {
  if (!a)
    return;
  fila leafQueue;
  criaFila(&leafQueue);
  ins(leafQueue, a);
  while (leafQueue->inicio) {
    nodo *leaf = cons(leafQueue);
    printf("%d ", leaf->info);
    if (left(leaf)) {
      ins(leafQueue, left(leaf));
    }
    if (right(leaf)) {
      ins(leafQueue, right(leaf));
    }
    ret(leafQueue);
  }
  destroy(leafQueue);
}

void preOrder(arvore a) {
  if (a) {
    printf("%d ", a->info);
    preOrder(a->left);
    preOrder(a->right);
  }
}

void inOrder(arvore a) {
  if (a) {
    inOrder(a->left);
    printf("%d ", a->info);
    inOrder(a->right);
  }
}

void postOrder(arvore a) {
  if (a) {
    postOrder(a->left);
    postOrder(a->right);
    printf("%d ", a->info);
  }
}

void ins_ele(arvore *a, int x) {
  if (!a) {
    maketree(a, x);
    return;
  }
  arvore aux = (*a);
  do {
    if (x < aux->info) {
      if (aux->left) {
        aux = aux->left;
      } else {
        setLeft(aux, x);
        break;
      }
    } else if (x > aux->info) {
      if (aux->right) {
        aux = aux->right;
      } else {
        setRight(aux, x);
        break;
      }
    } else
      break;
  } while (1);
}

void fusionRemove(arvore *a) {
  if (*a) {
    arvore tmp = *a;

    if (!((*a)->right)) {
      if ((*a)->left) {
        (*a)->left->father = (*a)->father;
      }
      *a = (*a)->left;
    } else if ((*a)->left == NULL) {
      if ((*a)->right)
        (*a)->right->father = (*a)->father;
      *a = (*a)->father;
    } else {
      tmp = (*a)->left;
      while (tmp) {
        tmp = tmp->right;
      }
      tmp->right = (*a)->right;
      if (tmp->right)
        tmp->right->father = tmp;
      tmp = *a;
      *a = (*a)->left;
    }
    free(tmp);
  }
}

void copyRemove(arvore *a) {
  if (*a) {
    arvore tmp = *a;

    if (!((*a)->right)) {
      if ((*a)->left) {
        (*a)->left->father = (*a)->father;
      }
      *a = (*a)->left;
    } else if ((*a)->left == NULL) {
      if ((*a)->right)
        (*a)->right->father = (*a)->father;
      *a = (*a)->father;
    } else {
      tmp = (*a)->right;
      while (tmp) {
        tmp = tmp->left;
      }
      (*a)->info = tmp->info;
      if (tmp->father == *a) {
        tmp->father->right = tmp->right;
        if (tmp->father->right) {
          tmp->father->right->father = tmp->father;
        }
      } else {
        tmp->father->left = tmp->right;
        if (tmp->right) {
          tmp->father->left->father = tmp->father;
        }
      }
    }
  }
}

int max(int a, int b) { return (a > b) ? a : b; }

void rotacaoDir(arvore *a) {
  // FB < 0
  if (*a) {
    nodo *novaRaiz, *novoNeto;
    novaRaiz = (*a)->left;
    novoNeto = novaRaiz->right;
    (*a)->left = novoNeto;
    novaRaiz->right = (*a);
    if (!((*a)->left))
      (*a)->alte = 0;
    else if ((*a)->left->alte > (*a)->left->altd)
      (*a)->alte = (*a)->left->alte + 1;
    else
      (*a)->altd = (*a)->left->altd + 1;
    if ((*a)->right->alte > (*a)->right->altd)
      (*a)->alte = (*a)->right->alte + 1;
    else
      (*a)->alte = (*a)->right->altd + 1;
    (*a) = novaRaiz;
  }
}

void rotacaoEsq(arvore *a) {
  if (*a) {
    nodo *novaRaiz, *novoNeto;
    novaRaiz = (*a)->right;
    novoNeto = novaRaiz->left;
    (*a)->right = novoNeto;
    novaRaiz->left = (*a);
    if (!((*a)->right))
      (*a)->altd = 0;
    else if ((*a)->right->alte > (*a)->right->altd)
      (*a)->altd = (*a)->right->alte + 1;
    else
      (*a)->altd = (*a)->right->altd + 1;
    if ((*a)->left->alte > (*a)->left->altd)
      (*a)->alte = (*a)->left->alte + 1;
    else
      (*a)->alte = (*a)->left->altd + 1;
    (*a) = novaRaiz;
  }
}

void balanceamento(arvore *a) {
  if (*a) {
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
      if (FBf >= 0) {
        rotacaoEsq(&((*a)->left));
      }
      rotacaoDir(a);
    }
  }
}

int main() { return 0; }