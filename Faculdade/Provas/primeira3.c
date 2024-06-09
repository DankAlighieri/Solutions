/*
	Implemente uma estrutura para armazenar informações sobre carros 
	(modelo, marca, ano de fabricação, quantidade de vendas, preço). 
	Escreva funções que receba um vetor de carros e exiba: 
	a) o modelo de carro mais vendido; 
	b) o valor do carro mais caro;
	c) o valor do carro mais barato. Desconsidere empates. 
	
	Teste seu programa para N = 6. 
	
	O vetor da função main deve ser alocado dinamicamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 2

typedef struct {
	char MODELO[30], MARCA[30];
	int ANO_FAB, QUANT_VENDAS;
	float PRECO;
} CARRO;

void inicializarEstoque(CARRO *carro) {
	int i;
	for(i = 0; i < n; i++) {
		setbuf(stdin, NULL);
		printf("\nInsira o modelo do %d carro: ", i+1);
		scanf("%99[^\n]", carro[i].MODELO);
		setbuf(stdin, NULL);
		printf("\nInsira a marca do %d carro: ", i+1);
		scanf("%99[^\n]", carro[i].MARCA);
		printf("\nInsira o ano de fabricacao do %d carro: ", i+1);
		scanf("%d", &carro[i].ANO_FAB);
		printf("\nInsira a quantidade vendida do %d carro: ", i+1);
		scanf("%d", &carro[i].QUANT_VENDAS);
		printf("\nInsira o preco do %d carro: ", i+1);
		scanf("%f", &carro[i].PRECO);
	}
}

void imprimirCarro(CARRO *carro, int i) {
	printf("--- CARRO %d ---", i+1);
	printf("\nModelo: %s\n", carro[i].MODELO);
	printf("Marca: %s\n", carro[i].MARCA);
	printf("Ano de fabricacao: %d\n", carro[i].ANO_FAB);
	printf("Quantidade vendida: %d\n", carro[i].QUANT_VENDAS);
	printf("Preco do produto: %.2f\n", carro[i].PRECO);
}

void carroMaisVendido(CARRO *carro) {
	int i, maisVendas = carro[0].QUANT_VENDAS, j = 0;
	for(i = 1; i < n; i++){
		if(carro[i].QUANT_VENDAS > maisVendas) {
			j = i;
			maisVendas = carro[i].QUANT_VENDAS;
		}
	}
	puts("Carro mais vendido: ");
	imprimirCarro(carro, j);
}

void carroMaisCaro(CARRO *carro){
	int i, maiorValor = carro[0].PRECO, j = 0;
	for(i = 1; i < n; i++){
		if(carro[i].PRECO > maiorValor) {
			j = i;
			maiorValor = carro[i].PRECO;
		}
	}
	puts("Carro mais caro: ");
	imprimirCarro(carro, j);
}

void carroMaisBarato(CARRO *carro){
	int i, menorValor = carro[0].PRECO, j = 0;
	for(i = 1; i < n; i++){
		if(menorValor > carro[i].PRECO) {
			j = i;
			menorValor = carro[i].PRECO;
		}
	}
	puts("Carro mais barato: ");
	imprimirCarro(carro, j);
}

int main() {
	CARRO *carro = NULL;
	
	carro = (CARRO *) realloc(carro, n*sizeof(CARRO));
	if(!carro) {
		puts("Erro de memoria!");
		exit(1);
	}
	inicializarEstoque(carro);

	// Questao a
	carroMaisVendido(carro);
	// Questao b
	carroMaisCaro(carro);
	// Questao c
	carroMaisBarato(carro);

	return 0;
}