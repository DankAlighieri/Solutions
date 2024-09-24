#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} NODE;

typedef NODE *lista;
void cria(lista *pl) { *pl = NULL; }
void ins(lista *pl, int N) {
  lista tail;
  for (int i = 1; i <= N; i++) {
    lista novo = (lista)malloc(sizeof(NODE));
    novo->val = i;

    if (!(*pl)) {
      // Inicializando lista
      *pl = novo;
    } else {
      // apontando o antigo ultimo endereço para o novo último
      tail->next = novo;
    }
    // Inserindo novo ultimo endereço
    tail = novo;
  }
  // Linkando último nodo ao primeiro
  tail->next = *pl;
}

int search(lista *l, int k, int n) {
  lista curr = *l;

  while (--n) {
    lista aux;
    int temp;

    // Encontrando antecessor direto
    for (temp = 2; temp < k; temp++)
      curr = curr->next;

    // removendo nodo
    aux = curr->next;
    curr->next = aux->next;

    // Salvando o endereco do proximo elemento na lista
    curr = curr->next;
    free(aux);
  }

  // Colocando ultimo no na referencia externa
  *l = curr;
  return (*l)->val;
}

int main() {
  lista l;
  int NC, n, k, i = 1;

  scanf("%d", &NC);
  while (NC--) {
    scanf("%d %d", &n, &k);
    cria(&l);
    ins(&l, n);
    search(&l, k, n);
    printf("Case %d: %d\n", i++, l->val);
    free(l);
  }

  return 0;
}