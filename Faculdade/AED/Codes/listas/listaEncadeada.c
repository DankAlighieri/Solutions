#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *next; // Devido a essa chamada da struct "nodo" se faz necessaria
                     // a nomeacao do struct no inicio da declaracao
} NODO;

typedef NODO *lista; // lista sera um ponteiro para o struct nodo, logo, todo
                     // indice da lista sera por si so um ponteiro

void cria_lista(lista *pl) { // *pl eh um ponteiro para o primeiro ponteiro da
                             // lista (referencia externa)
  *pl = NULL;
}

int eh_vazia(lista l) { return (l == NULL); }

int tam(lista l) {
  int i = 0;
  while (l != NULL) {
	i++;
	l = l->next;
  }

  return i;
}

void ins(lista *pl, int v, int k) {
  int i;
  NODO *novo;

  // validando a posicao de insercao
  if (k < 1 || k > tam(*pl) + 1) {
    puts("pos invalida");
    exit(1);
  }

  // alocando memoria para um novo nodo
  novo = (NODO *)malloc(sizeof(NODO));
  if (!novo) {
    puts("Erro de memoria!");
    exit(2);
  }

  // Duas possibilidades: Ser o primeiro ou nao

  if (k == 1) {
    // next node will be the previous first node
    novo->next = *pl;
    // new first node will be the new node
    *pl = novo;
  } else {
    lista aux;

    // Encontrando no antecessor a posicao a ser inserida (Ver excalidraw para
    // melhor compreensao)
    for (aux = *pl; k > 2; k--) {
      aux = aux->next;
    }

    novo->next = aux->next;
    aux->next = novo;
  }
}

void ins2(lista *pl, int v, int k) {
  NODO *novo;
  
  // verificiar se posicao de inservao eh valida
  if (k < 1 || k > tam(*pl) + 1) {
    puts("Posicao de insercao invalida");
    exit(1);
  }

  novo = (NODO *) malloc(sizeof(NODO));
  if (!novo) {
    puts("problema ao alocar memoria");
    exit(2);
  }
  
  novo->inf = v;

  if (k == 1) {
    novo->next = *pl;
    *pl = novo;
  } else {
    lista aux;

    for(aux = *pl; k>2; aux=aux->next, k--);
    novo->next = aux->next;
    aux->next = novo;
  }
}

void insRec(lista *pl, int v, int k){
	if (k < 1 || k > (tam(*pl) + 1)) {
		puts("Posicao de insercao invalida");
		exit(1);
	} else if (k == 1) {
		NODO *novo;
		novo = (NODO *) malloc(sizeof(NODO));
		if(!novo) {
			puts("Erro de memoria!");
			exit(2);
		}
		novo->inf = v;
		novo->next = *pl;
		*pl = novo;
	}
	insRec(&((*pl)->next), v, k-1);
}

int recup (lista l, int k) {
	if (k < 1 || k > tam(l)) {
		puts("Posicao invalida");
		exit(1);
	}
	for(; k > 1;k--)
		l = l->next;
	return (l->inf);
}

int main() { 
	lista l;
	cria_lista(&l);
	ins2(&l, 10, 1);
	printf("Tamanho da lista: %d\n", tam(l));
	printf("Valor: %d\n", recup(l, 1));
	return 0; 
}
