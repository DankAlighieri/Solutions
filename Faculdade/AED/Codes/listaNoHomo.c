#include <stdio.h>
#include <stdlib.>

#define INTGR 1
#define FLT 2
#define STRING 3

typedef struct node {
    int etype;
    union inf {
        int ival;
        float fval;
        char sval[20];
    } element;
    struct node * next;
} NODE;

typedef NODE *lista;

void cria(lista *pl) {
    *pl = NULL;
}

int tam(lista l) {
    int i = 1;
    while (l) {
        i++;
        l= l->next;
    }
}

void ins(lista *pl, union inf param, int k, int etype){
    NODE * novo;
    if (k < 1 || k > tam(*pl)) {
        puts("Pos inv");
        return;
    }

    novo = (NODE *) malloc(sizeof(NODE));
    if (!novo) {
        puts("Mem err");
        return;
    }

    if 
}