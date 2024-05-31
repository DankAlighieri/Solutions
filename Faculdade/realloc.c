#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = NULL, a, count = 0, i;

    do {
        printf("\nLendo inteiro no indice %d: ", count+1);
        scanf("%d", &a);
        if (a) {
            printf("\nRealocando mais %lld de memoria ao vetor de inteiros.", a*sizeof(int));
            realloc(p, a*sizeof(int));
            if (!p) {
                printf("\nErro na memoria");
                exit(1);
            }
            p[count] = a;
        }
        count++;
        printf("\nIncrementar count %d.", count);
    }while (a);

    for (i = 0; i < count; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    return 0;
}