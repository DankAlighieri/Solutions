#include <stdio.h>
#define tam 10

typedef struct {
    char NOME[21];
    int VALIDADE;
} carne;

int main () {
    carne carnes[tam], temp;
    int n, i, j;

    while (~scanf("%d", &n)) {
        // inicializar vetor
        for (i = 0; i < n; i++) {
            scanf(" %s %d", carnes[i].NOME, &carnes[i].VALIDADE);
        }

        // bubble sort
        for (i = 0; i < n - 1; i++) {
            for(j = 0; j < n - i - 1; j++) {
                if (carnes[j].VALIDADE > carnes[j+1].VALIDADE) {
                    temp = carnes[j];
                    carnes[j] = carnes[j + 1];
                    carnes[j + 1] = temp;
                }
            }
        }

        for (i = 0; i < n - 1; i++) {
            printf("%s ", carnes[i].NOME);
        }
        printf("%s\n", carnes[i].NOME);
    }

    return 0;
}