#include <stdio.h>
#include <stdlib.h>

typedef struct chaveNodo {
  int inf;
  struct chaveNodo *nextChave;
} chaveNodo;

typedef struct nodo {
  int end;
  struct nodo *nextEnd;
  chaveNodo *chaves;
} nodo;

typedef nodo *tabela;

void criaTabela(tabela *t, int n) {
  tabela tail;

  for (int i = 0; i < n; i++) {
    tabela end = (nodo *)malloc(sizeof(nodo));
    end->end = i;
    end->chaves = NULL;
    end->nextEnd = NULL;

    if (i == 0) {
      *t = end;
    } else {
      tail->nextEnd = end;
    }
    tail = end;
  }
}

void inserirChave(tabela *t, int c, int m) {
  int pos, val;

  while (c--) {
    tabela aux = *t;
    scanf("%d", &val);
    pos = val % m;

    chaveNodo *newChave = (chaveNodo *)malloc(sizeof(chaveNodo));
    if (!newChave) {
      puts("Mem err");
      return;
    }
    newChave->inf = val;
    newChave->nextChave = NULL;
    // procurando pelo endereco
    for (int i = 0; i < pos; i++, aux = aux->nextEnd)
      ;
    // lista de chaves vazia
    if (!aux->chaves) {
      aux->chaves = newChave;
    } else {
      // lista de chaves nao vazia
      chaveNodo *auxChave = aux->chaves;
      while (auxChave->nextChave) {
        auxChave = auxChave->nextChave;
      }
      auxChave->nextChave = newChave;
    }
  }
}
void destruir(tabela *t) {
  while (*t) {
    tabela aux = *t;
    *t = (*t)->nextEnd;

    // destruir lista de chaves
    chaveNodo *chaveAux = aux->chaves;
    while (chaveAux) {
      chaveNodo *temp = chaveAux;
      chaveAux = chaveAux->nextChave;
      free(temp);
    }

    free(aux);
  }
}

int main() {
  int n, m, c;
  scanf("%d", &n);
  while (n) {
    tabela t = NULL;
    scanf("%d %d", &m, &c);
    criaTabela(&t, m);
    inserirChave(&t, c, m);

    tabela temp = t;
    while (temp) {
      if (!temp->chaves) {
        printf("%d -> \\", temp->end);
      } else {
        printf("%d ->", temp->end);
        for (; temp->chaves; temp->chaves = temp->chaves->nextChave) {
          printf(" %d ->", temp->chaves->inf);
        }
        printf(" \\");
      }
      printf("\n");
      temp = temp->nextEnd;
    }
    if (n > 1) {
      printf("\n");
    }
    destruir(&t);
    n--;
  }

  return 0;
}