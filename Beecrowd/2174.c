#include <stdio.h>
#include <string.h>
#define poke 1000

int main() {
  int n, i, j, diff, counterDiff = 0;
  char pokemons[poke][1001];
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s", pokemons[i]);
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
      if (!strcmp(pokemons[i], pokemons[j]))
        break;
    }
    if (i == j)
      counterDiff++;
  }

  printf("Falta(m) %d pomekon(s).\n", 151 - counterDiff);

  return 0;
}
