#include <stdio.h>

void cedulas(int entrada, int div, int *c, int *r) {
    *r = entrada % div;
    *c = entrada / div;
}

int main() { 
    int reais, centavos, resto, c, r;
    scanf("%d.%d", &reais, &centavos);
    
    printf("NOTAS:");
    cedulas(reais, 100, &c, &r);
    printf("\n%d nota(s) de R$ 100.00", c);
    cedulas(r, 50, &c, &r);
    printf("\n%d nota(s) de R$ 50.00", c);
    cedulas(r, 20, &c, &r);
    printf("\n%d nota(s) de R$ 20.00", c);
    cedulas(r, 10, &c, &r);
    printf("\n%d nota(s) de R$ 10.00", c);
    cedulas(r, 5, &c, &r);
    printf("\n%d nota(s) de R$ 5.00", c);
    cedulas(r, 2, &c, &r);
    printf("\n%d nota(s) de R$ 2.00\n", c);
    printf("MOEDAS:");
    cedulas(r, 1, &c, &r);
    printf("\n%d moeda(s) de R$ 1.00", c);
    cedulas(centavos, 50, &c, &r);
    printf("\n%d moeda(s) de R$ 0.50", c);
    cedulas(r, 25, &c, &r);
    printf("\n%d moeda(s) de R$ 0.25", c);
    cedulas(r, 10, &c, &r);
    printf("\n%d moeda(s) de R$ 0.10", c);
    cedulas(r, 5, &c, &r);
    printf("\n%d moeda(s) de R$ 0.05", c);
    cedulas(r, 1, &c, &r);
    printf("\n%d moeda(s) de R$ 0.01\n", c);
    
    return 0;
}