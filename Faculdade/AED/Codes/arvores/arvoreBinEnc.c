#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *left;
    struct nodo *right;
    struct nodo *father;
} nodo;

typedef nodo * arvore;

void criaArvore(arvore *a, int x){
    *a = (arvore) malloc(sizeof(nodo));
    if (!(*a)) {
        puts("Mem err");
        return;
    }
    (*a)->info = x;
    (*a)->left = (*a)->right = (*a)->father = NULL;
}

void setLeft(arvore a, int x){
    a->left = (arvore) malloc(sizeof(nodo));
    if (!(a->left)) {
        puts("mem err");
        return;
    }
    a->left->info = x;
    a->left->left = NULL;
    a->left->right = NULL;
    a->left->father = a;
}

void setLeft(arvore a, int x){
    a->right = (arvore) malloc(sizeof(nodo));
    if (!(a->right)) {
        puts("mem err");
        return;
    }
    a->right->info = x;
    a->right->left = NULL;
    a->right->right = NULL;
    a->right->father = a;
}

int info(arvore a) {
    return a->info;
}

arvore left(arvore a) {
    return a->left;
}

arvore right(arvore a) {
    return a->right;
}

arvore father(arvore a) {
    return a->father;
}

int isLeft(arvore a) {
    nodo *q = a->father;
    if (!q) return 0;
    if (q->left == a) return 1;
    return 0;
}

int isRight(arvore a) {
    if (a->father) {
        return (!isLeft(a));
    }
    return 0;
}

arvore brother(arvore a) {
    if (a->father) {
        if (isLeft(a)) return (a->father)->right;
        else return (a->father)->left;
    }
}

int main() {

    return 0;
}