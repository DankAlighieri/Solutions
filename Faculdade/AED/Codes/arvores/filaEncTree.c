#include "arvoreBin.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void cria(fila *f) {
  (*f) = (fila)malloc(sizeof(node));
  if (!(*f)) {
    puts("Mem err");
  } else {
    (*f)->inicio = (*f)->fim = NULL;
  }
}

int vazia(fila f) { return !f->inicio; }

void ins(fila f, arvoreBin leaf) {
  node *novo = (node *)malloc(sizeof(node));
  if (!novo) {
    puts("Mem err");
  } else {
    novo->leaf = leaf;
    novo->next = NULL;
    if (!(f->inicio)) {
      f->inicio = novo;
    } else {
      f->fim->next = novo;
    }
    f->fim = novo;
  }
}

arvoreBin cons(fila f) {
  if (!(f->inicio)) {
    puts("Fila vazia");
  } else {
    return f->inicio->leaf;
  }
}

void ret(fila f) {
  if (!(f->inicio)) {
    puts("Fila vazia");
  } else {
    node *aux = f->inicio;
    f->inicio = f->inicio->next;
    if (!f->inicio) {
      f->fim = NULL;
    }
    free(aux);
  }
}

arvoreBin cons_ret(fila f) {
  if (!(f->inicio)) {
    puts("Fila vazia");
  } else {
    arvoreBin leaf = f->inicio->leaf;
    ret(f);
    return leaf;
  }
}

void destruir(fila f) {
  node *aux;
  while (f->inicio) {
    aux = f->inicio;
    f->inicio = f->inicio->next;
    free(aux);
  }
}

// void geraFila(fila *f, int m, int n) {
//   if (m > n) {
//     return;
//   }
//   if (m == n) {
//     cria(f);
//     ins(*f, m);
//   } else {
//     geraFila(f, m, n-1);
//     ins(*f, n);
//   }
// }

int main() {
  // fila f;
  // // cria(&f);
  // // for (int i = 1, v = 10; i <= 10; i++, ins(f, v), v += 10);
  // geraFila(&f, 1, 10);
 
  // for (; f->inicio->next; printf("%d ", cons_ret(f)))
  //   ;
  // putchar('\n');
  // printf("%d\n", cons(f));
  // printf("%s\n", !f->inicio ? "Fila vazia" : "Nao vazia");
  // destruir(f);
  // printf("%s\n", !f->inicio ? "Fila vazia" : "Nao vazia");
  return 0;
}