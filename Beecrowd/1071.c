#include <stdio.h>

int main() {
    int a,b,temp,soma = 0;
    scanf("%d %d", &a, &b);
    
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    for (int i = a + 1; i < b; i++) {
        if (i%2) soma += i;
    }

    printf("%d\n", soma);
    return 0;
}