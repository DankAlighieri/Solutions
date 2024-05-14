#include <stdio.h>

int main() {
    int mesesContrato, i, tempoTotal = 0;
    float celtinhaValor, dinheiroGuardado, somatorio = 0;

    scanf("%d %f", &mesesContrato, &celtinhaValor);

    for (i = 1; i<=mesesContrato; i++) {
        scanf("%f", &dinheiroGuardado);
        somatorio += dinheiroGuardado;
        if (!tempoTotal) {
            if (somatorio >= celtinhaValor) {
                tempoTotal += i;
                somatorio -= celtinhaValor;
            }
        }
    }

    if (tempoTotal) {
        printf("%d %.2f", tempoTotal, somatorio);
        return 0;
    }

    printf("%d %.2f", 0, somatorio);
    return 0;
}