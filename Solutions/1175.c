#include <stdio.h>
#define ne 20
int main(){
    int input[ne], invertedCopy[ne], i, j;

    for (i = 0, j = ne - 1; i < ne; i++, j--) {
        scanf("%d", &input[i]);
        invertedCopy[j] = input[i];
    }
    for (i = 0; i < ne; i ++) {
        printf("N[%d] = %d\n", i,invertedCopy[i]);
    }

    return 0;
}