#include <stdio.h>

int main() {
  int N, x[1000], i, menor, posicao;
  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    scanf("%d", &x[i]);
  }

  menor = x[0];

  for (i = 0; i < N; i++) {
    if (x[i] < menor) {
      menor = x[i];
      posicao = i;
    }
  }

  printf("Menor valor: %d\n", menor);
  printf("Posicao: %d\n", posicao);

  return 0;
}
