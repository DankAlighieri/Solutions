#include <stdio.h>
#define tam 5

/*
 * Implemente um programa que preencha uma matriz 5x5 de números reais.
 * A seguir, o programa deverá multiplicar cada linha pelo elemento da 
 * diagonal principal daquela linha. Mostre a matriz antes e após as 
 * multiplicações.
 */

int main() {
  int matriz[tam][tam], i, j, *p, *k, soma, diagonais[tam], ultimo_num, count = 0;
  

  for(i = 0, p = &matriz[0][0]; i < tam * tam; i++, p++) scanf("%d", p);

  puts("Matriz antes da multiplicacao");
  
  ultimo_num = matriz[tam - 1][tam -1];
  
  while (ultimo_num) {
    ultimo_num /= 10;
    count++;
  }

  for(i = 0, p = &matriz[0][0]; i < tam; i++) {     
    for (j = 0; j < tam ; j++, p++) {
      if (j == 0) {
        printf("| %*d", count, *p);
      } else if(j == 4) {
        printf("%*d |", count, *p);
      } else {
        printf(" %*d ", count, *p);
      }
    }
    printf("\n");
  }
 
  for (i = 0, p = &matriz[0][0], k = diagonais; i < tam; p += tam + 1, i++, k++) {
    *k = *p;
  }

  for (i = 0, p = &matriz[0][0]; i < tam; i++) {
    for (j = 0; j < tam; j++) {
      // acessando o conteudo de p, multiplicando pelo conteudo em k
      *p *= diagonais[i];
      p++;
    }
  }
  
  ultimo_num = matriz[tam - 1][tam -1];
  count = 0;

  while (ultimo_num) {
    ultimo_num /= 10;
    count++;
  }


 puts("Matriz apos a multiplicacao.");
  for(i = 0, p = &matriz[0][0]; i < tam; i++) {     
    for (j = 0; j < tam ; j++, p++) {
      if (j == 0) {
        printf("| %*d", count, *p);
      } else if(j == 4) {
        printf("%*d |", count,*p);
      } else {
        printf(" %*d ", count,*p);
      }
    }
    printf("\n");
  }

  return 0;
}
