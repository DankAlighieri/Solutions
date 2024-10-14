#ifndef ARVOREAVL_H
#define ARVOREAVL_H

typedef struct nodo {
    int info, altd, alte;
    struct nodo *left, *right;
} nodo;
typedef nodo *arvoreAVL;

void makeTree(arvoreAVL *, int);
void setLeft(arvoreAVL, int);
void setRight(arvoreAVL, int);
int info(arvoreAVL);
arvoreAVL left(arvoreAVL);
arvoreAVL right(arvoreAVL);

// Necessario uma fila
void buscaLargura(arvoreAVL);
void preOrder(arvoreAVL);
void inOrder(arvoreAVL);
void postOrder(arvoreAVL);

void rotacaoDir(arvoreAVL *);
void rotacaoEsq(arvoreAVL *);
void balanceamento(arvoreAVL *);

void ins_ele(arvoreAVL *, int);
void fusionRemove(arvoreAVL *);
void copyRemoval(arvoreAVL *);

#endif