#include <stdio.h>
#define nl 3
#define nc 4

int main() {
    int matriz[nl][nc], *p, i;

    for (i = 0, p = matriz[0]; i < nl*nc; i++) {
        *(p++) = i+1;
    }
    for (i = 0, p = matriz[0]; i < nl*nc; i++) {
        if (i%4 == 0) {
            printf("|%02d ", *(p++));
        } else if (i%4 == 3) {
            printf("%02d|\n", *(p++));
        } else {
            printf("%02d ", *(p++));
        }
    }

    return 0;
}