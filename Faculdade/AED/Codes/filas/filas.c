#include <stdio.h>

#define max 100

typedef struct {
  int N;
  int inicio;
  int fim;
  int val[max];
} fila;

void cria_fila(fila *f) {
  f->N = f->inicio = 0;
  f->fim = -1;
}

int vazia(fila *f) { return !f->N; }

int tam(fila *f) { return f->N; }

void ins(fila *f, int v) {
  if (f->N == max) {
    puts("Fila cheia");
  } else {
    f->fim = (f->fim + 1) % max;
    f->val[f->fim] = v;
    f->N++;
  }
}

int cons(fila *f) {
  if (!f->N) {
    puts("Lista vazia");
  } else {
    return f->val[f->inicio];
  }
}

void ret(fila *f) {
  if (!(f->N)) {
    puts("lista vazia");
  } else {
    // Ao inves de atualizar a referencia do fim e mover todos os elementos uma
    // casa a esquerda Basta apenas atualizar a refrencia do inicio e
    // decrementar a quantidade de elementos, pois O valor no antigo inicio ira
    // ser perdido.
    f->inicio = (f->inicio + 1) % max;
    f->N--;
  }
}

int cons_ret(fila *f) {
  if (!(f->N)) {
    puts("lista vazia");
  } else {
    int v = f->val[f->inicio];
    f->inicio = (f->inicio + 1) % max;
    f->N--;
    return v;
  }
}

// Gera uma fila de inteiros no intervalo [m,n]
void gera_fila(fila *f, int m, int n) {
  if (m > n) {
    return;
  }
  if (m == n) {
    cria_fila(f);
    ins(f, m);
  } else {
    // // Gera fila decrescente
    // gera_fila(f, m+1, n);
    // ins(f, m);

    // Gera fila crescente
    gera_fila(f, m, n-1);
    ins(f, n);
  }
}

int main() {
  fila f;
  //   cria_fila(&f);
  //   printf("%s\n", vazia(&f) ? "Fila vazia" : "Fila nao vazia");
  //   for (int i = 1, v = 10; i <= 5; i++, ins(&f, v), v += 10)
  //     ;
  gera_fila(&f, 1, 10);
  for (; f.N; printf("%d ", cons_ret(&f)))
    ;
  printf("\n");
  return 0;
}