#include <stdio.h>
#include <stdlib.h>

#define numEntradas 8
typedef struct _Hash {
  int chave;
  struct _Hash *prox;
} Hash;

typedef Hash *Tabela[numEntradas];

void inicializarHash(Tabela);
int funcaoHashing(int);
void inserirHash(Tabela, int);
void mostrarHash(Tabela);
Hash *localizarHash(Tabela, int, Hash **);
void excluirHash(Tabela, int);
void liberarMemoria(Tabela);

int main() {
  Tabela t;
  Hash *prev = NULL, *resultado;
  inicializarHash(t);
  for (int i = 1; i < 10; i++) {
    inserirHash(t, i);
  }
  // mostrarHash(*t);
  // resultado = localizarHash(t, 1, &prev);
  // printf("Hash 2 em 1 = %d\nHash anterior = %d\n",
  //        resultado->chave, 
  //        prev ? prev->chave : -1);
  excluirHash(t, 9);
  mostrarHash(t);
  return 0;
}

void inicializarHash(Tabela t) {
  for (int i = 0; i < numEntradas; i++) {
    t[i] = NULL;
  }
}

int funcaoHashing(int chave) { return chave % numEntradas; }

void inserirHash(Tabela t, int chave) {
  int hash = funcaoHashing(chave);
  Hash *novo = (Hash *)malloc(sizeof(Hash));

  if (!novo)
    return;

  novo->chave = chave;
  novo->prox = t[hash];
  t[hash] = novo;
}

Hash *localizarHash(Tabela t, int chave, Hash **prev) {
  int hash = funcaoHashing(chave);
  Hash *curr = t[hash];
  *prev = NULL;
  while (curr) {
    if (curr->chave == chave) {
      return curr;
    }
    *prev = curr;
    curr = curr->prox;
  }
  return NULL;
}

void excluirHash(Tabela t, int chave) {
  Hash *prev = NULL;
  Hash *rem = localizarHash(t, chave, &prev);

  if (!rem) {
    // Lista vazia
    return;
  }

  if (prev == NULL) {
    // Primeiro Hash na lista
    int hash = funcaoHashing(chave);
    t[hash] = rem->prox;
  } else {
    // Resto dos casos
    prev->prox = rem->prox;
  }
  free(rem);
}

void mostrarHash(Tabela t) {
  puts("Mostrando hash");
  for (int i = 0; i < numEntradas; i++) {
    printf("Hash %d -> ", i);
    while (t[i] != NULL) {
      // printf("Hash %d -> ", i);
      printf("%d -> ", t[i]->chave);
      t[i] = t[i]->prox;
    }
    puts("NULL");
  }
}

void liberarMemoria(Tabela t) {
  for (int i = 0; i < numEntradas; i++) {
    Hash *aux;
    while (t[i]) {
      aux = t[i];
      t[i] = t[i]->prox;
      free(aux);
    }
  }
}