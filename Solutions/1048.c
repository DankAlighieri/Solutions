#include <stdio.h>

int main() {
    double s, r;
    scanf("%lf", &s);

    if ( s > 2000.00){
        r = s * 0.04;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d %%\n", (s+r), r, 4);
        return 0;
    } else if (s > 1200.00 && s <= 2000.00) {
        r = s * 0.07;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d %%\n", (s+r), r, 7);
        return 0;
    } else if (s > 800.00 && s <= 1200.00) {
        r = s * 0.10;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d %%\n", (s+r), r, 10);
        return 0;
    } else if (s > 400.00 && s <= 800.00) {
        r = s * 0.12;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d %%\n", (s+r), r, 12);
        return 0;
    } else if (s <= 400) {
        r = s * 0.15;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d %%\n", (s+r), r, 15);
        return 0;
    }

    return 0;
}