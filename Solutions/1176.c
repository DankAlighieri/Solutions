#include <stdio.h>

unsigned long long int fibo(int fiboTerm) {
    unsigned long long int a = 1, b = 1, aux;
    int i;
    if (!fiboTerm) return 0;
    for(i = 1; i < fiboTerm; i++) {
        aux = b; 
        b += a;
        a = aux;
    }

    return a;
}

int main(){
    unsigned long long int b;
    int  testCases, fiboTerm, i;
    scanf("%d", &testCases);
    for (i = 0; i < testCases; i++) {
        scanf("%d", &fiboTerm);
        b = fibo(fiboTerm);
        printf("Fib(%d) = %lli\n", fiboTerm, b);
    }

    return 0;
}