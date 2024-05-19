#include <stdio.h>

int main() {
  char entrada[8];
  int i, soma = 0, casos = 0;

  while (casos < 3) {
    scanf(" %[^\n]", entrada);
    if (entrada[0] != 'c') {
      for (i = 0; i < 3; i++) {
        if (entrada[i] == '*') {
          switch (i) {
          case 0:
            soma += 4;
            break;
          case 1:
            soma += 2;
            break;
          case 2:
            soma += 1;
            break;
          }
        }
      }
    } else {
      printf("%d\n", soma);
      soma = 0;
      casos++;
    }
  }

  return 0;
}
