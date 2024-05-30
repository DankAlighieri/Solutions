#include <stdio.h>

int main() {
    double n1, n2, m;
    int s;
    while (1){
        do {
            scanf("%lf", &n1);
            if (n1 < 0 || n1 > 10) printf("nota invalida\n");
        } while (n1 < 0 || n1 > 10);

        do {
            scanf("%lf", &n2);
            if (n2 < 0 || n2 > 10) printf("nota invalida\n");
        } while (n2 < 0 || n2 > 10);

        m = (n1 + n2)/2;
        printf("media = %.2lf\n", m);
        
        do {
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d", &s);
            if (s == 2) {
                return 0;
            }
        } while (s < 1 || s > 2);
    }

    return 0;
}