#include <stdio.h>
#define tam 3

int main() {
    int armazem[tam][tam], produtos[tam] = {260, 420, 330}, 
        i, j, prodTot[tam], menorArm, k, custoProdArm[tam], 
        custoEstoqArma[tam], custoTotProd[tam];


    for (i = 0; i < tam; i++) {
        prodTot[i] = 0;
        custoProdArm[j] = 0;
        custoEstoqArma[i] = 0;
        for (j = 0; j < tam; j++) {
            // validando entrada para garantir apenas positivos
            do {
                // populando cada armazem
                scanf("%d", &armazem[i][j]);
            } while (armazem[i][j] < 0);

            // salvando estoque total de cada armazem
            prodTot[i] += armazem[i][j];
            // salvando custo total de cada produto do armazem
            custoProdArm[j] = armazem[i][j] * produtos[j];
            printf("Custo do prod %d = %d\n", j+1, custoProdArm[j]);
            // salvando custo total de cada armazem
            custoEstoqArma[i] += custoProdArm[j];
            
            // obtendo armazem com menor quantidade do produto 2
            if (j == 1) {
                if (!i) {
                    menorArm = prodTot[i];
                    k = 0;
                    if (menorArm > prodTot[i]) {
                        menorArm = prodTot[i];
                        k = i;
                    }
                } else {
                    if (menorArm > prodTot[i]) {
                        menorArm = prodTot[i];
                        k = i;
                    }
                }
            }
        }
        printf("Custo total do estoque %d = %d\n", i+1, custoEstoqArma[i]);
        printf("Total de produtos do armazem %d eh %d\n", i+1 ,prodTot[i]);
    }
    
    // Calculando o custo total de cada produto entre todos os armazens
    for (j = 0; j < tam; j++) {
        custoTotProd[j] = 0;
        for (i = 0; i < tam; i++) {
            printf("Produto %d tem quant = %d\n", i, armazem[i][j]);
            custoTotProd[j] += armazem[i][j];
        }
        custoTotProd[j] *= produtos[j];
        printf("Custo total do produto %d eh igual a %d\n", j+1, custoTotProd[j]);
    }

    printf("Armazem com o menor estoque do produto 2 eh o %d", k+1);

    return 0;
}