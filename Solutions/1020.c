#include <stdio.h>

int main (void) 
{
    int ind, y, m, d;
    scanf("%d", &ind);
    y = ind/365;
    ind%=365;
    m = ind/30;
    ind%=30;
    printf("%d ano(s)\n", y); 
    printf("%d mes(es)\n", m); 
    printf("%d dia(s)\n", ind); 

    return 0;
}