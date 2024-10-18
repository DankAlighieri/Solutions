#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int A, M, C, esp = 0;
    
    scanf("%d%d%d", &A,&M,&C);
    do {
        if (A < 2) {
            break;
        } else if (M < 3) {
            break;
        } else if (C < 5) {
            break;
        } else {
            esp++;
            A-=2;
            M-=3;
            C-=5;
        }
    } while(esp!=0);
    printf("%d\n", esp);

    return 0;
}