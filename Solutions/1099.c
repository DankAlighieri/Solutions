#include <stdio.h>

int main() {
    int n, a, b, temp, soma, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        soma = 0;
        scanf("%d %d", &a, &b);
        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }

        for(j = a + 1; j < b; j++) {
            if(j%2) soma+=j;
        }
        printf("%d\n", soma);
    }

    return 0;
}