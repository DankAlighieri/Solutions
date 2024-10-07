#ifndef FILA_H
#define FILA_H
#include "arvoreBin.h"

typedef struct node {
    arvoreBin leaf;
    struct node *next;
} node;

typedef struct {
    node *inicio;
    node *fim;
} descritor;

typedef descritor * fila;

void cria(fila *);
int vazia(fila);
void ins(fila, arvoreBin);
arvoreBin cons(fila);
void ret(fila);
arvoreBin cons_ret(fila);
void destruir(fila);
#endif