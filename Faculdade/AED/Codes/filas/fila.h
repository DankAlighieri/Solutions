#ifndef FILA_H
#define FILA_H

typedef struct node {
    int inf;
    struct node *next;
} node;

typedef struct {
    node *inicio;
    node *fim;
} descritor;

typedef descritor * fila;

void cria(fila *);
int vazia(fila);
void ins(fila, int);
int cons(fila);
void ret(fila);
int cons_ret(fila);
void destruir(fila);
void geraFila(fila *, int, int);
#endif