#ifndef FILA_H
#define FILA_H

typedef struct nodo {
    int inf;
    struct nodo *next;
} nodo;

typedef struct {
    nodo *inicio;
    nodo *fim;
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