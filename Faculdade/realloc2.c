#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor=NULL, entrada, i = 0, j, count = 0;

    do {
        i = 0;
        do {
            scanf("%d", &entrada);
            if (entrada) {
                i++;
                count = 0;
                vetor = (int *) realloc(vetor, i*sizeof(int));
                if (!vetor) {
                    printf("Erro de memoria");
                    exit(1);
                }
                vetor[i-1] = entrada;
            } else {
                count++;
                if (count == 1) {
                    for (j = 0; j < i; j++) {
                        printf("Elemento Vetor[%d] = %d\n", j+1, vetor[j]);
                    }
                    free(vetor);
                    vetor = NULL;
                }
            }
        } while (entrada);
    } while (count < 2);

    free(vetor);
    return 0;
}