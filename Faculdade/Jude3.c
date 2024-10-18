#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h=0, r, c=0 , t=0;
    scanf("%d", &h);
    for (h; h>0; h--) {
        scanf("%d", &r);
        if (r == 1) {
            t++;
        } else if (r == 2) {
            c++;
        }
    }
    if (c != 0 && t != 0) {
        printf("Equipe Balanceada");
    } else {
        printf("Equipe Desbalanceada");
    }

    return 0;
}