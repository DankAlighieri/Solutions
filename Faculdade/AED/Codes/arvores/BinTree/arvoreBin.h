#ifndef ARVOREBIN_H
#define ARVOREBIN_H

typedef struct nodo {
    int info;
    struct nodo *left,*right, *father;
} nodo;
typedef nodo *arvoreBin;

void makeTree(arvoreBin *, int);
void setLeft(arvoreBin, int);
void setRight(arvoreBin, int);
int info(arvoreBin);
arvoreBin left(arvoreBin);
arvoreBin right(arvoreBin);
arvoreBin brother(arvoreBin);
arvoreBin father(arvoreBin);
int isLeft(arvoreBin);
int isRight(arvoreBin);
void buscaLargura(arvoreBin);
void preOrder(arvoreBin);
void inOrder(arvoreBin);
void postOrder(arvoreBin);
void ins_ele(arvoreBin *, int);
void fusionRemove(arvoreBin *);
void copyRemoval(arvoreBin *);

#endif