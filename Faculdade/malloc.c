#include <stdio.h>
#include <stdlib.h>

int main() {
    int n_lin, n_col, i;
    float *p;

    // Em uma matriz, a divisao inteira pelo numero de colunas retorna o numero de linhas
    // Em uma matriz, o resto da divisao inteira pelo numero de colunas retorna o numero de colunas

    printf("\nInsira o numero de linhas: ");
    scanf("%d", &n_lin);
    printf("\nInsira o numero de colunas: ");
    scanf("%d", &n_col);

    p = (float *) malloc(n_lin*n_col*sizeof(float));

    if (!p) {
        puts("Erro na memoria");
        exit(1);
    }

    for (i = 0 ; i < n_lin*n_col; i++) {
        scanf("%f", p+i);
    }

   for (i = 0 ; i < n_lin*n_col; i++) {
            // operador ! tem precedencia. Utilizar parentesis p/ eliminar ambiguidade
        if (!(i%n_col)) {
            printf("|%5.2f", p[i]);
        } else if (i%n_col == n_col - 1) {
            printf("%5.2f|\n", p[i]);
        } else {
            printf(" %5.2f ", p[i]);
        }
    }

    return 0;
}