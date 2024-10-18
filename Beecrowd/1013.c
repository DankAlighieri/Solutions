#include <stdio.h>
#include <stdlib.h>

int main() {
    int A,B,C, maiorValorAB;
    scanf("%d %d %d", A, B, C);
    maiorValorAB = (A + B + abs(A-B))/2;
    if (maiorValorAB > C) {printf("%d eh o maior\n", maiorValorAB);}
    else {printf("%d eh o maior", C);}

    return 0;
}