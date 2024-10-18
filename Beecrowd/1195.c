#include <stdio.h>
#include <stdlib.h>

typedef struct _treeNode {
  int info;
  struct _treeNode *father, *left, *right;
} treeNode;

typedef treeNode *tree;

void makeTree(tree *t, int v) {
  *t = (treeNode *)malloc(sizeof(treeNode));
  if (!(*t))
    return;
  (*t)->info = v;
  (*t)->father = (*t)->right = (*t)->left = NULL;
}

void setLeft(tree t, int v) {
  t->left = (treeNode *)malloc(sizeof(treeNode));
  if (!(t->left))
    return;
  t->left->info = v;
  t->left->left = t->left->right = NULL;
  t->left->father = t;
}

void setRight(tree t, int v) {
  t->right = (treeNode *)malloc(sizeof(treeNode));
  if (!(t->right))
    return;
  t->right->info = v;
  t->right->left = t->right->right = NULL;
  t->right->father = t;
}

void insEle(tree *t, int v, int first) {
  if (first) {
    makeTree(t, v);
  } else {
    treeNode *aux = *t;
    do {
      if (v < aux->info) {
        if (aux->left) {
          aux = aux->left;
        } else {
          setLeft(aux, v);
          break;
        }
      } else if (v > aux->info) {
        if (aux->right) {
          aux = aux->right;
        } else {
          setRight(aux, v);
          break;
        }
      } else
        break;
    } while (1);
  }
}

void preOrder(tree t) {
  if (t) {
    printf(" %d", t->info);
    preOrder(t->left);
    preOrder(t->right);
  }
}

void inOrder(tree t) {
  if (t) {
    inOrder(t->left);
    printf(" %d", t->info);
    inOrder(t->right);
  }
}

void postOrder(tree t) {
  if (t) {
    postOrder(t->left);
    postOrder(t->right);
    printf(" %d", t->info);
  }
}

void mostrar(tree t, int caso) {
  if (t) {
    printf("Case %d:\n", caso);
    printf("Pre.:");
    preOrder(t);
    putchar('\n');
    printf("In..:");
    inOrder(t);
    putchar('\n');
    printf("Post:");
    postOrder(t);
    putchar('\n');
    putchar('\n');
  }
}

int main() {
  int c, i = 0;
  scanf("%d", &c);
  while (c--) {
    tree t;
    int n, num, first = 1;
    scanf("%d", &n);
    while (n--) {
      scanf("%d", &num);
      insEle(&t, num, first);
      first = 0;
    }
    mostrar(t, ++i);
  }
  return 0;
}