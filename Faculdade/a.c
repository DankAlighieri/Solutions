#include <stdio.h>

int main() {

    int quant, numEsme, i;

    scanf("%d", &quant);

    int numCaix[quant + 1];

    for (i = 0; i < quant; i++) {
        scanf("%d", &numCaix[i]);
    }

    scanf("%d", &numEsme);

    for (i = 0; i < quant; i++) {
        if (numEsme == numCaix[i]) {
            printf("%d", numCaix[i]);
            return 0;
        }
    }

    printf("-1");
    
    return 0;
}