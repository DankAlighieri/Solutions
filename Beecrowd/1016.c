#include <stdio.h>

int main() 
{
    int vm, t, d;
    float gasto;
    scanf("%d", &t);
    scanf("%d", &vm);
    d = t * vm;
    gasto = (float) d/12;
    printf("%.3f\n", gasto);
}