#include <stdio.h>
#include <math.h>

double somatorio(double x) {
    double somatorio = 0;
    int i;

    for (i = 1; i < 25; i++){
        if (i == 1) {
            somatorio += pow(x, 2)/i - pow(x, 2)/(i+1);
        }
        else {
            if (i%2!=0) {
                somatorio -= pow(x, 2)/(i+1);
            } else {
                somatorio += pow(x, 2)/(i+1);
            }
        }
    }

    return somatorio;
}

int main() {
    double x;
    
    scanf("%lf", &x);
    printf("%.2lf", somatorio(x));

    return 0;
}