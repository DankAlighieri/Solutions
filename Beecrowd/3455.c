#include <stdio.h>
typedef long long int lli;

int main() {
    lli A, B, C, temp;
    char O;
    scanf("%lld %lld %lld", &A, &B, &C);
    scanf(" %c", &O);
    switch (O) {
        case 'A':
            // dinamica para grafos
            A += (B*3)/2;
            // geometria para grafos
            A += (C*5)/2;
            printf("%lld\n", A);
            break;
        case 'B':
            // grafos para dinamica
            B += (A*2)/3;
            // geometria para grafos
            temp = (C*5)/2; 
            // grafos para dinamica
            B += (temp*2)/3;
            printf("%lld\n", B);
            break;
        case 'C':
            // grafos para geometria
            C += (A*2)/5;
            //  dinamica para grafos
            temp = (B*3)/2;
            // grafos para geometria
            C += (temp*2)/5;
            printf("%lld\n", B);
            break;
    }
    return 0;
}