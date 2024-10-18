#include <stdio.h>
#define nm 6

int main() {
    /*Faca uma funca em C que receb, por parametro, uma matriz A(6,6) e retorna a soma dos elementos da sua diagonal principal*/
    
    int matriz[nm][nm], i, j, somatorio = 0;

    for (i = 0; i < nm; i++) {
        for (j = 0; j < nm; j ++) {
            scanf("%d", &matriz[i][j]);
            if (i == j) {
                somatorio += matriz[i][j];
            }
        }
    }

    printf("%d", somatorio);

    return 0;
}