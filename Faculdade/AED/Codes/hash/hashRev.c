#include <stdio.h>
#include <stdlib.h>

/*HASH aberto*/

#define MAX 8

typedef struct _Hash {
  int inf;
  struct _Hash *prox;
} HASH;
typedef HASH *Tabela[MAX];

void inicializarHash(Tabela);
int funcaoHashing(int);
void inserirHash(Tabela, int);
void mostrarHash(Tabela);
HASH *localizarHash(Tabela, int);
void excluirHash(Tabela, int);
void liberarMemoria(Tabela);

void inicializarHash(Tabela t) {
  for (int i = 0; i < MAX; i++) {
    t[i] = NULL;
  }
}

int funcaoHashing(int chave) { return chave % MAX; }

void inserirHash(Tabela t, int chave) {
  HASH *novo = (HASH *)malloc(sizeof(HASH));
  int pos = funcaoHashing(chave);
  if (!novo)
    return;

  novo->inf = chave;
  novo->prox = t[pos];
  t[pos] = novo;
}

void mostrarHash(Tabela t) {
  for (int i = 0; i < MAX; i++) {
    while (t[i]) {
      printf("%d -> ", t[i]->inf);
      t[i] = t[i]->prox;
    }
  }
}

HASH *localizarHash(Tabela t, int chave) {
  int hash = funcaoHashing(chave);

  while (t[hash]) {
    if (t[hash]->inf == chave)
      return t[hash];
    else
      t[hash] = t[hash]->prox;
  }
  return NULL;
}

void excluirHash(Tabela t, int chave) {
  int hash = funcaoHashing(chave);
  HASH *prev = NULL, *aux = t[hash];

  if (t[hash] && t[hash]->inf == chave) {
    t[hash] = t[hash]->prox;
    free(aux);
    return;
  } else {
    prev = aux;
    aux = aux->prox;
    while (aux) {
      if (aux->inf == chave) {
        prev->prox = aux->prox;
        free(aux);
        return;
      } else {
        prev = aux;
        aux = aux->prox;
      }
    }
  }
  puts("Chave nao existe");
}

void liberarMemoria(Tabela t) {
  for (int i = 0; i < MAX; i++) {
    HASH *aux;
    while (t) {
      aux = t[i];
      t[i] = t[i]->prox;
      free(aux);
    }
  }
}

/* HASH fechado */

typedef struct {
  int chave;
  char status; // L: Livre; O: Ocupado; R: Removido
} HASHFECHADO;
typedef HASHFECHADO TabelaHash[MAX];

void inicializarHashFechado(TabelaHash);
void mostrarHashFechado(TabelaHash);

// Abordagem linear
void inserirHashLinear(TabelaHash, int);
int buscarChaveLinear(TabelaHash, int);
void removerChaveLinear(TabelaHash, int);

// Abordagem quadratica
void inserirHashQuadratico(TabelaHash, int);
int buscarChaveQuadratico(TabelaHash, int);
void removerChaveQuadratico(TabelaHash, int);

void inicializarHashFechado(TabelaHash t) {
  for (int i = 0; i < MAX; i++) {
    t[i].status = 'L';
  }
}

void mostrarHashFechado(TabelaHash t) {
  for (int i = 0; i < MAX; i++) {
    if (t[i].status == 'O') {
      printf("Hash %d: %d\n", i, t[i].chave);
    }
  }
}

void inserirHashLinear(TabelaHash t, int chave) {
  int hash = funcaoHashing(chave), i = 0;

  // Se o status nao for nem L nem R, pular
  while (i < MAX && t[(hash + i) % MAX].status != 'L' && t[(hash + i) % MAX].status != 'R') {
    i++;
  }

  // Existe espaco no hash
  if (i < MAX) {
    int pos = (i + hash) % MAX;
    t[pos].chave = chave;
    t[(i + hash) % MAX].status = 'O';
  } else {
    puts("Hash cheio");
  }
}

int buscarChaveLinear(TabelaHash t, int chave) {
  int hash = funcaoHashing(chave), i = 0;

  // Verifica se esta ocupado L e se a chave e diferente da desejada

  while (i < MAX && t[(i + hash) % MAX].status != 'L' &&
         t[(i + hash) % MAX].chave != chave) {
    i++;
  }

  // Hash ocupado e chave desejada
  if (t[(i + hash) % MAX].status == 'O' && t[(i + hash) % MAX].chave == chave) {
    return (i + hash) % MAX;
  } else {
    return MAX;
  }
}

void removerChaveLinear(TabelaHash t, int chave) {
  int hash = buscarChaveLinear(t, chave);

  if (hash < MAX) {
    t[hash].status = 'R';
  } else {
    puts("Hash nao existe");
  }
}

void inserirHashQuadratico(TabelaHash t, int chave) {
    int hash = funcaoHashing(chave), i = 1;

    while (i < MAX && t[hash].status == 'O') {
      hash = (hash + i) % MAX;
      i++;
    }

    if (i < MAX) {
      t[hash].chave = chave;
      t[hash].status = 'O';
    } else {
      puts("Hash cheio");
    }

  /* metodo 2 */

  // int hash = funcaoHashing(chave), i = 0;

  // while (i < MAX && t[(i*i + hash) % MAX].status == 'O') {
  //     i++;
  // }

  // if (i < MAX) {
  //     int pos = (i*i + hash) % MAX;
  //     t[pos].chave = chave;
  //     t[pos].status = 'O';
  // } else {
  //     return;
  // }
}

int buscarChaveQuadratico(TabelaHash t, int chave) {
  int hash = funcaoHashing(chave), i = 1;

  while (i < MAX && t[hash].status != 'L' && t[hash].chave != chave) {
    hash = (hash + i) % MAX;
    i++;
  }

  if (i < MAX) {
    return hash;
  } else {
    return MAX;
  }
}

void removerChaveQuadratico(TabelaHash t, int chave) {
  int hash = buscarChaveQuadratico(t, chave);

  if (hash < MAX) {
    t[hash].status = 'R';
  } else {
    puts("Hash nao existe");
  }
}

int main() {
  TabelaHash t;
  inicializarHashFechado(t);

  inserirHashQuadratico(t, 1);
  inserirHashQuadratico(t, 2);
  inserirHashQuadratico(t, 3);
  inserirHashQuadratico(t, 9);

  mostrarHashFechado(t);
  putchar('\n');
//   removerChaveQuadratico(t, 3);

//   mostrarHashFechado(t);

  //     removerChaveQuadratico(t, 9);
  //   mostrarHashFechado(t);

  return 0;
}