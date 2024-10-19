#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _treeNode {
  char info;
  struct _treeNode *father, *left, *right;
} treeNode;

typedef treeNode *tree;

// Definicao TAD fila inicio

typedef struct _queueNode {
  tree leaf;
  struct _queueNode *next;
} queueNode;

typedef struct {
  queueNode *inicio, *fim;
} descritor;
typedef descritor *queue;

void makeQueue(queue *q) {
  *q = (descritor *)malloc(sizeof(descritor));
  if (!(*q))
    return;
  (*q)->inicio = (*q)->fim = NULL;
}

void insQueue(queue q, tree leaf) {
  queueNode *novo = (queueNode *)malloc(sizeof(queueNode));
  if (!novo)
    return;
  novo->leaf = leaf;
  novo->next = NULL;
  if (!q->inicio) {
    q->inicio = novo;
  } else {
    q->fim->next = novo;
  }
  q->fim = novo;
}

tree cons(queue q) {
  if (!(q->inicio)) {
    return NULL;
  }
  return q->inicio->leaf;
}

void ret(queue q) {
  if (!(q->inicio))
    return;

  queueNode *aux = q->inicio;
  q->inicio = aux->next;
  if (!q->inicio) {
    q->fim = NULL;
  }
  free(aux);
}

void destroy(queue q) {
  queueNode *aux;
  while (q) {
    aux = q->inicio;
    q->inicio = q->inicio->next;
    free(aux);
  }
}

int emptyQueue(queue q) { return !q->inicio; }

// Definicao TAD fila fim

void makeTree(tree *t, char l) {
  (*t) = (tree)malloc(sizeof(treeNode));
  if (!(*t))
    return;
  (*t)->info = l;
  (*t)->father = (*t)->right = (*t)->left = NULL;
}

void setLeft(tree t, char l) {
  t->left = (tree)malloc(sizeof(treeNode));
  if (!(t->left))
    return;
  t->left->info = l;
  t->left->father = t;
  t->left->left = t->left->right = NULL;
}

void setRight(tree t, char l) {
  t->right = (tree)malloc(sizeof(treeNode));
  if (!(t->right))
    return;
  t->right->info = l;
  t->right->father = t;
  t->right->left = t->right->right = NULL;
}

void insEle(tree *t, char l) {
  treeNode *aux = *t;
  do {
    if (l < aux->info) {
      if (aux->left)
        aux = aux->left;
      else {
        setLeft(aux, l);
        break;
      }
    } else if (l > aux->info) {
      if (aux->right) {
        aux = aux->right;
      } else {
        setRight(aux, l);
        break;
      }
    } else
      break;
  } while (1);
}

void preOrder(tree t, int *first) {
  if (t) {
    if (!*first) {
      putchar(' ');
    }
    printf("%c", t->info);
    *first = 0;
    preOrder(t->left, first);
    preOrder(t->right, first);
  }
}

void preOrderHelper(tree t) {
  int first = 1;
  preOrder(t, &first);
}

void inOrder(tree t, int *first) {
  if (t) {
    inOrder(t->left, first);
    if (!*first) {
      putchar(' ');
    }
    printf("%c", t->info);
    *first = 0;
    inOrder(t->right, first);
  }
}

void inOrderHelper(tree t) {
  int first = 1;
  inOrder(t, &first);
}

void postOrder(tree t, int *first) {
  if (t) {
    postOrder(t->left, first);
    postOrder(t->right, first);
    if (!*first) {
      putchar(' ');
    }
    printf("%c", t->info);
    *first = 0;
  }
}

void postOrderHelper(tree t) {
  int first = 1;
  postOrder(t, &first);
}

void busca(tree t, char l) {
  queue q;
  makeQueue(&q);
  if (t) {
    insQueue(q, t);
  }
  while (!emptyQueue(q)) {
    tree auxLeaf = cons(q);
    if (auxLeaf->info == l) {
      printf("%c existe\n", l);
      ret(q);
      return;
    } else {
      if (auxLeaf->left) {
        insQueue(q, auxLeaf->left);
      }
      if (auxLeaf->right) {
        insQueue(q, auxLeaf->right);
      }
      ret(q);
    }
  }
  printf("%c nao existe\n", l);
}

int main() {
  char op[10], info;
  int first = 1, firstChar;
  tree t;
  while (scanf(" %s", op) != EOF) {
    firstChar = 1;
    if (!strcmp(op, "I")) {
      scanf(" %c", &info);
      if (first) {
        makeTree(&t, info);
        first = 0;
      } else
        insEle(&t, info);
    } else if (!strcmp(op, "P")) {
      scanf(" %c", &info);
      busca(t, info);
    } else if (!strcmp(op, "INFIXA")) {
      inOrderHelper(t);
      putchar('\n');
    } else if (!strcmp(op, "PREFIXA")) {
      preOrderHelper(t);
      putchar('\n');
    } else if (!strcmp(op, "POSFIXA")) {
      postOrderHelper(t);
      putchar('\n');
    }
  }

  return 0;
}