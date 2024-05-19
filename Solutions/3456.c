#include <stdio.h>

typedef long long int lli;

int main() {
  lli entrada, resto, divisao;
  
  scanf("%lld", &entrada);

  if (entrada < 10) {
    printf("%lld\n", entrada);
    return 0;
  }
  
  printf("%lld\n", entrada);
  while (entrada >= 10) {
    resto = entrada % 10;
    divisao = entrada / 10;
    entrada = (divisao * 3) + resto;
    printf("%lld\n", entrada);
  }

  return 0;
}
