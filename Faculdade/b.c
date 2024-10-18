#include <stdio.h>

int main() {
    int n, items[1100], i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }

    for ( i = n - 1; i>= 0; i--){
        printf("%d ", items[i]);
    }
    printf("\n");

    return 0;
}