#include <stdio.h>
#define n 10

int main() {
    int i, j, aux, vetor[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if(vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}