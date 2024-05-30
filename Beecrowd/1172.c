#include <stdio.h>
#define ne 10
int main() {
    int x[ne], i;

    for (i = 0 ; i < ne; i++) {
        scanf("%d", &x[i]);
        if (x[i] <= 0) x[i] = 1;
    }
    for (i = 0; i < ne; i++) {
        printf("X[%d] = %d\n", i, x[i]);
    }

    return 0;
}