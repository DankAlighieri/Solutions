#include <stdio.h>

int mdc(int a, int b) {
	int temp;
	if (b > a) {
		temp = a;
		a = b;
		b = temp;
	} 
	if (a%b == 0) return b;
	a = a%b;
	return mdc(a,b);
}

int somaDigitos(int a) {
	if (a > 0) return a % 10 + somaDigitos(a / 10);
}

int somaVetor(int *a, int n) {
	if (n == 0) {
		return 0;
	}
	else return somaVetor(a, n-1) + a[n - 1];
}

int main() {
	int a[] = {1, 2, 3, 4, 5, 6};
	int size = sizeof(a)/sizeof(a[0]);

	///printf("MDC entre %d e %d = %d\n", a, b, mdc(a,b));
	printf("%d", somaVetor(a, size));
	
	return 0;
}