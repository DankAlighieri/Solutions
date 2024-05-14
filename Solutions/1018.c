#include <stdio.h>

int main() 
{ int entrada, cedulas, resto;
    scanf("%d", &entrada);
    resto = entrada % 100;
    cedulas = entrada / 100;
    printf("%d\n", entrada);
    printf("%d nota(s) de R$ 100,00\n", cedulas);
    cedulas = resto / 50;
    resto %= 50;
    printf("%d nota(s) de R$ 50,00\n", cedulas);
    cedulas = resto /20;
    resto %= 20;
    printf("%d nota(s) de R$ 20,00\n", cedulas);
    cedulas = resto / 10;
    resto %= 10;
    printf("%d nota(s) de R$ 10,00\n", cedulas);
    cedulas = resto / 5;
    resto %= 5;
    printf("%d nota(s) de R$ 5,00\n", cedulas);
    cedulas = resto / 2;
    resto %= 2;
    printf("%d nota(s) de R$ 2,00\n", cedulas);
    cedulas = resto / 1;
    resto %= 1;
    printf("%d moeda (s) de R$ 1,00\n", cedulas);
    
    return 0;
}