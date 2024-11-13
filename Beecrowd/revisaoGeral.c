#include <stdio.h>
#include <stdlib.h>

/*
////////////////////////////////////////////////////////////////
							ARVORE
////////////////////////////////////////////////////////////////
*/

typedef struct _nodoArv {
	int info, alte, altd;
	struct _nodoArv *father, *left, *right;
} nodoArv;

typedef nodoArv *arv;

/*
////////////////////////////////////////////////////////////////
							PILHA
////////////////////////////////////////////////////////////////
*/

typedef struct _nodoPilha {
	int info;
	struct _nodoPilha *next;
} nodoPilha;
typedef nodoPilha *pilha;

/*
////////////////////////////////////////////////////////////////
							FILA
////////////////////////////////////////////////////////////////
*/

typedef struct _nodoFila {
	arv leaf;
	struct _nodoFila *next;
} nodoFila;

typedef struct {
	nodoFila *inicio;
	nodoFila *fim;
} descritor;

typedef descritor *fila;

/*
////////////////////////////////////////////////////////////////
						 PILHA DEFINICAO
////////////////////////////////////////////////////////////////
*/

void createPilha(pilha *p) {
	*p = NULL;
}

int is_empty(pilha p) {
	return !p;
}

void push (pilha *p, int x) {
	pilha novo = (nodoPilha *) malloc(sizeof(nodoPilha));
	if (!novo) return;
	novo->info = x;
	novo->next = *p;
	*p = novo;
}

int top(pilha p){
	if(!p) {
		puts("Pilha vazia");
		exit(0);
	}
	return p->info;
}

void pop(pilha *p){
	if(!(*p)) {
		puts("Pilha vazia");
		exit(0);
	}
	pilha aux = *p;
	(*p) = (*p)->next;
	free(aux);
}

int top_pop(pilha *p){
	if(!(*p)) {
		puts("Pilha vazia");
		exit(0);
	}
	int v = (*p)->info;
	pilha aux = *p;
	(*p) = (*p)->next;
	free(aux);
	return v;
}
void destroy(pilha p){
	pilha aux;
	while(p) {
		aux = p;
		p = p->next;
		free(aux);
	}
}

/*
////////////////////////////////////////////////////////////////
						  FILA DEFINICAO
////////////////////////////////////////////////////////////////
*/

void createFila(fila *f) {
	*f = (descritor *) malloc(sizeof(descritor));
	if(!(*f)) return;
	(*f)->inicio = (*f)->fim = NULL;
}

int eh_vazia(fila f) {
	return !(f->inicio);
}

//int tam(fila f) {
//	return f->inicio->info;
//}

void insFila(fila f, arv leaf) {
	nodoFila *novo = (nodoFila *) malloc(sizeof(nodoFila));
	if(!novo) return;
	novo->leaf = leaf;
	novo->next = NULL;
	if(!(f->inicio)){
		f->inicio = novo;
	} else {
		f->fim->next = novo;
	}
	f->fim = novo;
}

arv cons(fila f) {
	if(!(f->inicio)) return NULL;
	return f->inicio->leaf;
}

void ret(fila f) {
	if(!(f->inicio)) return;
	nodoFila *aux = f->inicio;
	f->inicio = f->inicio->next;
	if(!(f->inicio)) f->fim = NULL;
	free(aux);
}

arv consRet(fila f){
	if(!(f->inicio)) return NULL;
	arv leaf = f->inicio->leaf;
	nodoFila *aux = f->inicio;
	f->inicio = f->inicio->next;
	if(!(f->inicio)) f->fim = NULL;
	free(aux);
	return leaf;
}

void destruir(fila f) {
	nodoFila *aux;
	while(f->inicio) {
		aux = f->inicio;
		f->inicio = f->inicio->next;
		free(aux);
	}
	free(f);
}

/*
////////////////////////////////////////////////////////////////
						 ARVORE DEFINICAO
////////////////////////////////////////////////////////////////
*/

void makeTree(arv *a, int x) {
	*a = (arv) malloc(sizeof(nodoArv));
	if(!(*a)) return;
	(*a)->info = x;
	(*a)->alte = (*a)->altd = 0;
	(*a)->father = (*a)->right = (*a)->left = NULL;
}

void setLeft(arv a, int x) {
	a->left = (nodoArv *) malloc(sizeof(nodoArv));
	if(!(a->left)) return;
	a->left->info = x;
	a->left->left = a->left->right = NULL;
	a->left->father = a;
	
	// Atributos de AVL
	//a->left->alte = a->left->altd = 0;
}
void setRight(arv a, int x) {
	a->right = (arv) malloc(sizeof(nodoArv));
	if(!(a->right)) {
		printf("Mem err");
		exit(1);
	};
	a->right->info = x;
	a->right->left = a->right->left = NULL;
	a->right->father = a;
	
	// Atributos de AVL
	//a->right->alte = a->left->altd = 0;
}

int info(arv a) {
	if(!a){
		puts("Arvore vazia");
		exit(0);
	}
	return a->info;
}

int isLeft(arv a) {
	if(a) {
		if(a->father) {
			return (a == a->father->left) ?  1 : 0;
		}
	}
	puts("Arvore vazia");
	exit(0);
}

int isRight(arv a) {
	if (a) {
		if(a->father) {
			return !isLeft ? 1 : 0;
		}
	}
	puts("Arvore vazia");
	exit(0);
}

arv left(arv a){
	return a->left;
}
arv right(arv a) {
	return a->right;
}
arv father(arv a) {
	return a->father;
}
arv brother(arv a) {
	if (a->father) {
		if(isLeft(a)) {
			return a->father->right;
		} else return a->father->left;
	}
	return NULL;
}

void insArvore(arv *a, int x) {
	if(!(*a)) {
		makeTree(a, x);
	} else {
		arv aux = *a;
		printf("Inserindo %d\n", x);
		do {
			if(x < aux->info) {
				if(aux->left) aux = aux->left;
				else {
					setLeft(aux, x);
					break;
				}
			} else {
				if(aux->right) {
					aux = aux->right;
					printf("No If dentro do else\n");
				}
				else {
					printf("No Else dentro do else\n");
					setRight(aux, x);
					break;
				}
			}
		} while(1);
	}
}

void percursoPreOrdem(arv a){
	if(a){
		printf("%d ", a->info);
		percursoPreOrdem(a->left);
		percursoPreOrdem(a->right);
	}
}
void percursoInOrdem(arv a){
	if(a){
		percursoInOrdem(a->left);
		printf("%d ", a->info);
		percursoInOrdem(a->right);
	}
}
void percursoPosOrdem(arv a){
	if(a) {
		percursoPosOrdem(a->left);
		percursoPosOrdem(a->right);
		printf("%d ", a->info);
	}
}
void percursoEmLargura(arv a){
	fila f;
	createFila(f);
	if(a) {
		insFila(f, a);
	}
	while(!eh_vazia(f)) {
		printf("%d ", cons(f));
		if(left(cons(f))) {
			insFila(f, left(cons(f)));
		}
		if(right(cons(f))) {
			insFila(f, right(cons(f)));
		}
	}
}

void remocaoPorFusao(arv *a){
	if(a) {
		arv tmp = *a;
		if(!((*a)->right)) {
			if((*a)->left) (*a)->left->father = (*a)->father;
			*a = (*a)->left;
		} else if(!((*a)->left)) {
			(*a)->right->father = (*a)->father;
			*a = (*a)->right;
		} else {
			tmp = (*a)->left;
			while(tmp) {
				tmp = tmp->right;
			}
			tmp->right = (*a)->right;
			tmp = *a;
			*a = (*a)->left;
			(*a)->left->father = (*a)->father;
		}
		free(tmp);
	} else return;
}
void remocaoPorCopia(arv *a){
	if(a) {
		arv tmp = *a;
		if(!((*a)->right)) {
			if((*a)->left) (*a)->left->father = (*a)->father;
			*a = (*a)->left;
		} else if (!((*a)->left)) {
			(*a)->right->father = (*a)->father;
			*a = (*a)->right;
		} else {
			tmp = (*a)->right;
			while (tmp->left) {
				tmp = tmp->left;
			}
			(*a)->info = tmp->info;
			if(tmp->father == *a) {
				tmp->father->right = tmp->right;
				if(tmp->father->right) tmp->father->right->father = tmp->father;
			} else {
				tmp->father->left = tmp->right;
				if(tmp->father->left) tmp->father->left->father = tmp->father;
			}
			tmp = *a;
			*a = tmp;
		}
	} else return;
}

void rotacaoDir(arv *a){
	arv aux1, aux2;
	aux1 = (*a)->left;
	aux2 = aux1->right;
	(*a)->left = aux2;
	aux1->right = *a;
	
	// Ligando pais
	aux1->father = (*a)->father;
	aux2->father = *a;
	(*a)->father = aux1;
	
	//Ajustando alturas
	if((*a)->left == NULL) (*a)->alte == 0;
	else if((*a)->left->alte > (*a)->left->altd) (*a)->altd = (*a)->left->alte + 1;
	else (*a)->alte = (*a)->left->altd + 1;
	if(aux1->right->alte > aux1->right->altd) aux1->alte = aux1->right->alte + 1;
	else aux1->altd = aux1->right->altd + 1;
	*a = aux1;
}
void rotacaoEsq(arv *a){
	arv aux1, aux2;
	aux1 = (*a)->right;
	aux2 = aux1->left;
	aux1->left = *a;
	(*a)->right = aux2;
	
	// Ligando pais
	aux1->father = (*a)->father;
	aux2->father = *a;
	(*a)->father = aux1;
	
	//Ajustando alturas
	
	if((*a)->right == NULL) (*a)->altd == 0;
	else if((*a)->right->alte > (*a)->right->altd) (*a)->altd = (*a)->right->alte + 1;
	else (*a)->altd = (*a)->right->altd + 1;
	if(aux1->left->alte > aux1->left->altd) aux1->alte = aux1->left->alte + 1;
	else aux1->alte = aux1->left->altd + 1;
	*a = aux1;
}
void balanceamento(arv *a){
	int FBp, FBf;
	FBp = (*a)->alte - (*a)->altd;
	if(FBp == 2) {
		FBf = (*a)->right->alte - (*a)->right->altd;
		if(FBf >= 0) {
			rotacaoEsq(a);
		} else {
			rotacaoDir(&((*a)->right));
			rotacaoEsq(a);
		}
	} else if(FBp == -2) {
		FBf = (*a)->left->alte - (*a)->left->altd;
		if(FBf <= 0) {
			rotacaoDir(a);
		} else {
			rotacaoEsq(&((*a)->left));
			rotacaoDir(a);
		}
	}
}

int main() {
    // Testes de Árvore
    printf("TESTES DE ARVORE:\n");
    arv root;
	puts("Criando arvore");
    makeTree(&root, 50);
	//printf("Raiz = %d\n", root->info);
    
    insArvore(&root, 30);
	//printf("Left =  %d\n", root->left->info);
    insArvore(&root, 70);
	//printf("Right =  %d\n", root->right->info);
    insArvore(&root, 20);
	//printf("Left-Left =  %d\n", root->left->left->info);
    insArvore(&root, 40);
	//printf("Left-Right =  %d\n", root->left->right->info);
    insArvore(&root, 60);
	//printf("Right-Left =  %d\n", root->right->left->info);
    insArvore(&root, 80);
	//printf("Right-right =  %d\n", root->right->right->info);
    
    printf("Percurso em pre-ordem: ");
    percursoPreOrdem(root);
    printf("\n");

    printf("Percurso em in-ordem: ");
    percursoInOrdem(root);
    printf("\n");

    printf("Percurso em pos-ordem: ");
    percursoPosOrdem(root);
    printf("\n");

    printf("Percurso em largura: ");
    percursoEmLargura(root);
    printf("\n");

    remocaoPorFusao(&root);
    printf("Percurso apos remocao por fusao: ");
    percursoInOrdem(root);
    printf("\n");

    return 0;
}
