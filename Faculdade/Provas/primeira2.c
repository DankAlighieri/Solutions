/*
	Implemente uma estrutura para armazenar informações sobre produtos em um estoque 
	(código, descrição, quantidade em estoque, quantidade de vendas, preço).

	Escreva funções que receba um vetor de produtos e exiba: 
	a) os produtos com quantidade em estoque menor do que um valor fornecido pelo usuário; 

	b) o valor total do estoque; 

	c) o produto mais vendido (desconsidere empates). 

	Teste seu programa para N = 6. 

	O vetor da função main deve ser alocado dinamicamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 2

typedef struct {
	int COD, QUANT_ESTO, QUANT_VENDAS;
	float PRECO;
	char DESCRICAO[100];
	
} PRODUTO;

void inicializarEstoque(PRODUTO *produto) {
	int i;
	printf("\n");
	for(i = 0; i < n; i++) {
		printf("Insira o codigo do %d produto: ", i+1);
		scanf("%d", &produto[i].COD);
		setbuf(stdin, NULL);
		printf("Insira a descricao do %d produto: ", i+1);
		scanf("%99[^\n]", produto[i].DESCRICAO);
		printf("Insira a quantidade em estoque do %d produto: ", i+1);
		scanf("%d", &produto[i].QUANT_ESTO);
		printf("Insira a quantidade vendida do %d produto: ", i+1);
		scanf("%d", &produto[i].QUANT_VENDAS);
		printf("Insira o preco do %d produto: ", i+1);
		scanf("%f", &produto[i].PRECO);
	}
}

void imprimirEstoque(PRODUTO *produto) {
	int i;
	printf("\n");
	for(i = 0; i < n; i++) {
		printf("--- PRODUTO %d ---\n", i+1);
		printf("Codigo: %d\n", produto[i].COD);
		printf("Descricao: %s\n", produto[i].DESCRICAO);
		printf("Quantidade em estoque: %d\n", produto[i].QUANT_ESTO);
		printf("Quantidade vendida: %d\n", produto[i].QUANT_VENDAS);
		printf("Preco do produto: %.2f\n", produto[i].PRECO);
	}
}

void imprimirProduto(PRODUTO *produto, int i) {
	printf("--- PRODUTO %d ---\n", i+1);
	printf("Codigo: %d\n", produto[i].COD);
	printf("Descricao: %s\n", produto[i].DESCRICAO);
	printf("Quantidade em estoque: %d\n", produto[i].QUANT_ESTO);
	printf("Quantidade vendida: %d\n", produto[i].QUANT_VENDAS);
	printf("Preco do produto: %.2f\n", produto[i].PRECO);
}

void produtosComQuantMenor(PRODUTO *produto, int quant) {
	int i;
	for(i = 0; i < n; i++){
		if(produto[i].QUANT_ESTO < quant) {
			imprimirProduto(produto, i);
		}
	}
}

float valorTotalEstoque(PRODUTO *produto) {
	int k;
	float soma = 0.0;
	for (k = 0; k < n; k++) {
		soma += produto[k].QUANT_ESTO * produto[k].PRECO;
	}

	return soma;
}

void produtoMaisVendido(PRODUTO *produto) {
	int i, maisVendas = produto[0].QUANT_VENDAS, j = 0;
	for(i = 1; i < n; i++){
		if(produto[i].QUANT_VENDAS > maisVendas) {
			j = i;
			maisVendas = produto[i].QUANT_VENDAS;
		}
	}
	puts("Produto mais vendido: ");
	imprimirProduto(produto, j);
}

int main() {
	PRODUTO *produto = NULL;
	int quant;
	
	produto = (PRODUTO *) realloc(produto, n*sizeof(PRODUTO));
	if(!produto) {
		puts("Erro de memoria!");
		exit(1);
	}
	inicializarEstoque(produto);

	puts("Digite a quantidade que vc quer: ");
	scanf("%d", &quant);
	// Questao a
	produtosComQuantMenor(produto, quant);

	// Questao b
	printf("Valor total do estoque: %.2f", valorTotalEstoque(produto));
	// Questao c
	produtoMaisVendido(produto);

	return 0;
}

/*
	Estoque 1:
	1
	Produto aleatorio 1
	1
	1
	1
	
	Estoque 2:
	2
	Produto aleatorio 2
	2
	2
	2
*/