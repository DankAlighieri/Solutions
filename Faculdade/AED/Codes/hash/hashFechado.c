#include <stdio.h>

#define tam 8

typedef struct {
  int chave;
  char status;
} Hash;

typedef Hash TabelaHash[tam];

void inicializarHash(TabelaHash *);
int funcaoHashing(int);
void mostrarHash(TabelaHash);
void inserirHash(TabelaHash, int);
int buscarChave(TabelaHash, int);
void removerChave(TabelaHash, int);

int main() { return 0; }

void inicializarHash(TabelaHash *t) {
  for (int i = 0; i < tam; t[i++]->status = 'L')
    ;
}

int funcaoHashing(int chave) { return chave % tam; }

void mostrarHash(TabelaHash t) {
  for (int i = 0; i < tam; printf("%d\n", t[i++].chave))
    ;
}

void inserirHash(TabelaHash t, int chave) {
  int pos = funcaoHashing(chave), i = 0;
  while (i < tam && t[pos + i].status == 'O')
    i++;
  if (i < tam) {
    t[pos + i].chave = chave;
    t[pos + i].status = 'O';
  } else {
    puts("Tabela cheia");
  }
}

int buscarChave(TabelaHash t, int chave) {
    
}