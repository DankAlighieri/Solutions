#include <stdio.h>
#define tam 1000

int main() {
  int N, paisagem[tam], i, j, pico = 0, vale = 0;

  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    scanf("%d", &paisagem[i]);
  }

  if (N == 1) {
    printf("%d\n", 1);
    return 0;
  }

  for (i = 1, j = i - 1; i <= N - 1; i++, j++) {
    if (paisagem[j] == paisagem[i]) {
      printf("%d\n", 0);
      return 0;
    } else if (paisagem[j] > paisagem[i] && !pico) {
      pico++;
      vale = 0;
    } else if (paisagem[j] < paisagem[i] && !vale) {
      vale++;
      pico = 0;
    } else if (paisagem[j] < paisagem[i] && vale != 0) {
      vale = 0;
      pico = 0;
      break;
    } else if (paisagem[j] > paisagem[i] && pico != 0) {
      vale = 0;
      pico = 0;
      break;
    }
  }

  if (vale == 0 && pico == 0) {
    printf("%d\n", 0);
  } else {
    printf("%d\n", 1);
  }

  return 0;
}
