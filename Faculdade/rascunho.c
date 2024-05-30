#include <stdio.h>

int main() {
    int a = 1, b = 1, i, aux;

    for (i = 1; i < 4; i++) {
        aux = b;
        b += a;
        a = aux;
    }
    printf("A = %d\nB = %d\nAUX = %d", a, b, aux);

    return 0;
}