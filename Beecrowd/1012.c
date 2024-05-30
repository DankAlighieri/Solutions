#include <stdio.h>
#include <math.h>

int main() 
{
    double A,B,C;

    scanf("%lf%lf%lf", &A, &B, &C);
    
    printf("%s%.3lf", "TRIANGULO: ", (A*C)/2);
    printf("\n%s%.3lf", "CIRCULO: ", pow(C, 2)*3.14159);
    printf("\n%s%.3lf", "TRAPEZIO: ", ((A+B)*C)/2);
    printf("\n%s%.3lf", "QUADRADO: ", pow(B, 2));
    printf("\n%s%.3lf\n", "RETANGULO: ", A*B);

    return 0;
}