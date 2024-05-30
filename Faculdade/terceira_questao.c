#include <stdio.h>
#include <string.h>
#define tam 101

int main() {
  int n, i, size, counter = 0;
  char entrada[tam], saida[tam];

  scanf("%d", &n);
  scanf(" %s", entrada);

  for (i = 0; entrada[i]; i++) {
    if (entrada[i] == '*') {
      counter++;
      sprintf(&saida[i], "%d", counter);
    } else {
      saida[i] = entrada[i];
    }
  }

  if (counter == 7) {
    puts("Pedido realizado");
    puts(saida);
  } else {
    puts("Pedido negado");
  }

  return 0;
}
