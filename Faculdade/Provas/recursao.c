#include <stdio.h>

int mult(int x, int n) {
    if (n == 1) return x;
    return x + mult(x, n-1);
}

int main() {
    int x , n;
    scanf("%d %d", &x, &n);
    printf("%d",mult(x, n));
    return 0;
}