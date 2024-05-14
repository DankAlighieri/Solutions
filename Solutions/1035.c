#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool aceito (int a, int b, int c, int d) {
    if (b<=c) {return false;}
    if (d<=a) {return false;}
    if ((c+d)<(a+b)) {return false;}
    if (c <= 0) {return false;}
    if (d <= 0) {return false;}
    if (a%2 != 0) {return false;}
    return true;
}

int main () {
    int a,b,c,d;
    scanf("%d%d%d%d", &a,&b,&c,&d);

    if (!aceito(a, b, c, d)) {
        printf("Valores nao aceitos\n");
        return 0;
    }

    printf("Valores aceitos\n");
    return 0;
}