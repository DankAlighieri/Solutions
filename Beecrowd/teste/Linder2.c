#include <stdlib.h>
#include <stdio.h>
typedef struct nodo
{
 int inf;
 struct nodo * next;
}NODO;
typedef NODO* LISTA;
void cria_lista (LISTA*);
int eh_vazia (LISTA);
int tam (LISTA);
void ins (LISTA, int, int);
int recup (LISTA, int);
void ret (LISTA, int);
void destruir (LISTA *);
void mostrar (LISTA);
int main() {
	int o, aux1, aux2;
	LISTA v;
	cria_lista(&v);
		do {
			scanf ("%d", &o);
			switch (o) {
			 case 1: scanf ("%d", &aux1);
				 scanf ("%d", &aux2);
				 ins(v, aux1, aux2);
			 break;
			 case 2: scanf ("%d", &aux1);
			 ret(v, aux1);
			 break;
			 case 3: mostrar(v);
			 break;
			 case 4: scanf ("%d", &aux1);
			 recup(v, aux1);
			 break;
			 case 5: tam(v);
			 break;
			 case 6: destruir(&v);
			 break;
			 }
		 } while (o);
	 return 0;
}
void cria_lista (LISTA *pl)
{
	*pl= (NODO *) malloc (sizeof(NODO));
	if (!(*pl)) {
	printf ("ERRO! Memoria insuficiente!\n");
	exit (0);
	}
	(*pl)->next=NULL;
	(*pl)->inf=0;
}
int eh_vazia (LISTA l) {
	return (!(l->inf));
}
int tam (LISTA l) {
	return (l->inf);
}
void ins (LISTA l, int v, int k) {
	NODO *novo;
	int tamanho = l->inf;
	if (k < 1 || k > tamanho + 1) {
		printf ("ERRO! Posicao invalida para insercao.\n");
		exit (0);
	}
	novo = (NODO *) malloc (sizeof(NODO));
	if (!novo) {
		printf ("ERRO! Memoria insuficiente!\n");
		exit (0);
	}
	novo->inf = v;
	if (l->next == NULL){
		novo->next = novo;
		l->next = novo;
	} 
	else {
		LISTA aux=l->next;
		if (k == tamanho + 1) l->next=novo;
		else for (; k>1; aux=aux->next, k--);
		novo->next = aux->next;
		aux->next = novo;
	}
	l->inf++;
}
int recup (LISTA l, int k)
{
 if (k < 1 || k > tam(l))
 {
 printf ("ERRO! Consulta invalida.\n");
 exit (0);
 }
 for (l=l->next;k>0;k--)
 l=l->next;
 return (l->inf);
}
void ret (LISTA l, int k) {
	int tamanho = l->inf;
	if (k < 1 || k > tamanho) {
		printf ("ERRO! Posicao invalida para retirada.\n");
		exit (0);
	}
	if (tamanho==1) {
		free (l->next);
		l->next = NULL;
	} else {
		LISTA aux, aux2;
		int i;
		for (aux=l, i=k; i>0; i--, aux=aux->next);
		aux2 = aux->next;
		aux->next = aux2->next;
		if (k==tamanho) l->next=aux;
		free (aux2);
	}
}
void destruir (LISTA *l)
{
 if ((*l)->next)
 {
 LISTA aux;
 for (aux=(*l)->next->next; aux!=(*l)->next; aux = aux->next)
 free (aux);
 free (aux);
 free (*l);
 *l=NULL;
 }
}
void mostrar (LISTA v)
{
 if (v->next)
 {
 NODO* aux=v->next;
 for (aux=aux->next; aux!=v->next; aux=aux->next)
 printf ("%d ", aux->inf);
 printf ("%d\n", aux->inf);
 }
else
 printf("Lista vazia!\n");
}