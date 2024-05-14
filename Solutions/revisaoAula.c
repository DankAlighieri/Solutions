/*
Construa um programa, na linguagem C, que declare uma matriz 5x5 de números naturais, a inicialize com valores fornecidos pelo usuário, através da entrada padrão, e, após a inicialização, efetue uma pesquisa nos elementos retornando na saída padrão a soma dos elementos localizados abaixo da diagonal principal.
*/

#include <stdio.h>

int main() {
    int matriz[5][5], 
        i, j, acumulador = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &matriz[i][j]);

        }
        
    }

    for (i = 0; i < 5; i ++) {
        for (j = 0; j < 5; j++) {
            if (i > j) acumulador += matriz[i][j];
        }
    }
    printf("%d\n", acumulador);

    return 0;
}