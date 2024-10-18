#include <stdio.h>

int main() {
    int n, j, acumulador = 0;
    scanf("%d", &n);
    int a[n], b[n];
    for (j = 0; j < n; j++) {
        scanf("%d", &a[j]);
        scanf("%d", &b[j]);
        acumulador += a[j] * b[j];
        printf("%d\n", acumulador);
    }

    return 0;
}