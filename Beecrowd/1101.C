#include <stdio.h>

int main() {
    int a, b, soma, aux;

while (scanf("%d %d", &a, &b), a > 0 && b > 0) {
    soma = 0;

    if (a > b) {
        aux = a;
        a = b;
        b = aux;
    }
    
    for (int i = a; i<=b; i++){
        printf("%d ", i);
        soma += i;
    }
    printf("Sum=%d\n", soma);
}

    return 0;
}