#include <stdio.h>

#define max 100

typedef struct {
  int topo;
  int val[max];
} pilha;

void cria(pilha *p) { p->topo = -1; }

int vazia(pilha *p) { return p->topo == -1; }

void push(pilha *p, int v) {
  if (p->topo == max - 1) {
    puts("Pilha cheia");
  } else {
    p->topo++;
    p->val[p->topo] = v;
  }
}

int top(pilha *p) {
  if (p->topo == -1) {
    puts("Pilha vazia");

    return p->val[p->topo];
  }
}

void pop(pilha *p) {
  if (p->topo == -1) {
    puts("Pilha vazia");
  } else {
    p->topo--;
  }
}

int top_pop(pilha *p) {
  if (p->topo == -1) {
    puts("Pilha vazia");
  } else {
    int v = p->val[p->topo];
    p->topo--;
    return v;
  }
}

int main() {
  pilha p;
  cria(&p);
  for (int i = 1, v = 10; i <= 10; push(&p, v), v += 10, i++)
    ;
  for (; p.topo > 0; printf("%d ", top_pop(&p)))
    ;
  putchar('\n');
  printf("%d\n", top_pop(&p));
  return 0;
}