/*
	Implemente uma função recursiva para calcular a soma de um vetor. 
	Escreva um programa que chama esta função e imprima os citados valores.
*/
#include <stdio.h>
int somar(int *v, int k) {
	if(k <= 0) return 0;
	return (somar(v, k-1) + v[k-1]);
}

int main() {
	int v[] = {1, 2, 3};
	int n = sizeof(v)/sizeof(v[0]);
	printf("Soma de V = %d", somar(v, n));
	return 0;
}