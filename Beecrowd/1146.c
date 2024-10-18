#include <stdio.h>

int main() {
    int x, i;
    
    do {
        scanf(" %d", &x);
        for(i = 1; i <= x; i++ ) {
            if (i == x) {
                printf("%d\n", i);
                break;
            }
            printf("%d ", i);
        }
    } while (x);

    return 0;
}