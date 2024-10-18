#include <stdio.h>

int main() {
  int estudantes, litros, ml, minimo, divisor;

  scanf("%d", &estudantes);
  scanf("%d", &litros);
  scanf("%d", &ml);
  
  litros *= 1000;
  divisor = (estudantes * ml) / litros;

  if ((estudantes*ml)%litros) divisor++;

  litros /= 1000;

  printf("%d\n", divisor * litros);

  return 0;
}
