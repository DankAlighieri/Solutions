#include <stdio.h>
#define tam 12

int main(int argc, char *argv[]) {
  char op;
  int matriz[12][12], i, j, soma;

  scanf(" %c", &op);

  for (i = 0; i < tam; i++) {
    for (j = 0; j < tam; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  if (op == 'S') {
    for (i = 0; i < 5; i++) {
      for (j = 0; j < tam; j++) {
        if (j > i) {
          soma += matriz[i][j];
        }
      }
    }
  }
  // soma

  return 0;
}
