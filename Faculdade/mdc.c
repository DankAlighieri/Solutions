#include <stdio.h>

int main() {
    int a, b, resto, i;
    do {
    scanf("%d %d", &a, &b);
    } while(a <= 0 && b < 0);

    if (a < b) {
        resto = a;
        a = b;
        b = resto;
    }

    if(!b) {
        if (a) printf("MDC: %d\n", a);
        else printf("+ infinito\n");
        return 0;
    }

    for (resto = a % b; resto; a = b, b = resto, resto = a % b);
    printf("MDC: %d\n", b);
}