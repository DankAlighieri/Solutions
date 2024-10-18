#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int inf;
    struct node *next;
} node;

typedef node * lista;

void cria(lista *l, int n) {
    lista tail;

    for(int i = 2; i<=n; i++) {
        lista novo = (lista) malloc(sizeof(node));
        novo->inf = i;

        if (i == 2) {
            *l = novo;
        } else {
            tail->next = novo;
        }
        tail = novo;
    }
    tail->next = *l;
	*l = tail;
}

lista ret(lista antRem){
	lista aux = antRem->next, adj = aux->next;
	
	// removendo nodo aux
	antRem->next = adj;
	free(aux);
	
	return antRem;
}

/* 
	- Remover ate o ultimo 
	- Se 13 nao for o ultimo
		- Repetir
		- Incrementar o salto
*/

int solve(lista l, int n, int k) {
	
	// Removendo ate o ultimo elemento
	while (n > 1) {
		for(int temp = 1; temp < k; l = l->next, temp++);
		l = ret(l);
		n--;
	}
	// Retornando o valor do ultimo elemento;
	
	return l->inf;
}

int main() {
    int n, k, inf;
	lista l;
    
	while(scanf("%d", &n), n) {
		k = 0;
		do {
			k++;
			cria(&l, n);
			inf = solve(l, n-1, k);
		} while(inf != 13);
		printf("%d\n", k);
	}
	
	return 0;
}