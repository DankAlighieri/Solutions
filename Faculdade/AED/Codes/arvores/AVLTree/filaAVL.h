#ifndef FILAAVL_H
#define FILAAVL_H

#include "arvoreAVL.h"

typedef struct _queueNode {
    arvoreAVL leaf;
    struct _queueNode *next;
} queueNode;

typedef struct {
    queueNode *inicio;
    queueNode *fim;
} descritor;

typedef descritor * avlQueue;

void cria(avlQueue *);
void ins(avlQueue, arvoreAVL);
arvoreAVL cons(avlQueue);
void ret(avlQueue);
void destroy(avlQueue);

#endif