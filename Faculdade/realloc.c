#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p=NULL, a, count = 0, i;

    do {
        printf("\nLendo inteiro no indice %d: ", count+1);
        scanf("%d", &a);
        if (a) {
            p = (int *) realloc(p, a*sizeof(int));
            if (!p) {
                printf("\nErro na memoria");
                exit(1);
            }
            p[count] = a;
        }
        count++;
    }while (a);

    for (i = 0; i < count - 1; i++) {
        printf("\nElemento no Vetor[%d] = %d ",i+1, p[i]);
    }
    printf("\n");

    free(p);
    return 0;
}