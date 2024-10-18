#include <stdio.h>
#include <math.h>

int main() {
    double a,b,c,d;
    scanf("%lf %lf %lf", &a, &b, &c);
    d = pow(b,2) - (4*a*c); 
    if (!a || (2*a) == 0 || d < 0) {
        printf("Impossivel calcular\n");
    } else {
        printf("R1 = %.5lf\n", (-b+sqrt(d))/(2*a));
        printf("R2 = %.5lf\n", (-b-sqrt(d))/(2*a));
    }
    return 0;
}