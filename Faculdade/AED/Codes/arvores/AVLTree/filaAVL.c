#include "arvoreAVL.h"
#include "filaAVL.h"
#include <stdlib.h>

void cria(avlQueue *q){
    *q = (avlQueue) malloc(sizeof(queueNode));
    if (!(*q)) return;
    (*q)->inicio = (*q)->fim = NULL;
}

void ins(avlQueue a, arvoreAVL leaf) {
    queueNode * newLeaf = (queueNode *) malloc(sizeof(queueNode));
    if (!newLeaf) return;
    newLeaf->leaf = leaf;
    newLeaf->next = NULL;

    if (!(a->inicio)) {
        a->inicio = newLeaf;
    } else {
        a->fim->next = newLeaf;
    }
    a->fim = newLeaf;
}

arvoreAVL cons(avlQueue q){
    if (!q) return NULL;
    return q->inicio->leaf;
}

void ret(avlQueue q) {
    if(!q) return NULL;
    queueNode *aux = q->inicio;
    q->inicio = q->inicio->next;
    if (!q->inicio) {
        q->fim = NULL;
    }
    free(aux);
}

void destroy(avlQueue q) {
    queueNode *aux;
    while (q->inicio) {
        aux = q->inicio;
        q->inicio = q->inicio->next;
        free(aux);
    }
}