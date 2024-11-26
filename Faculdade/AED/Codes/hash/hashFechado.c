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
void inserirHashLinear(TabelaHash, int);
int buscarChaveLinear(TabelaHash, int);
void removerChaveLinear(TabelaHash, int);
int buscarChaveQuadratico(TabelaHash, int);
void inserirHashQuadratico(TabelaHash, int);

void removerChaveQuadratico(TabelaHash, int);

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

void inserirHashLinear(TabelaHash t, int chave) {
  int pos = funcaoHashing(chave), i = 0;
  while (i < tam && t[(pos + i) % tam].status == 'O')
    i++;
  if (i < tam) {
    t[(pos + i) % tam].chave = chave;
    t[(pos + i) % tam].status = 'O';
  } else {
    puts("Tabela cheia");
  }
}

void inserirHashQuadratico(TabelaHash t, int chave) {
  int pos = funcaoHashing(chave), i = 0;
  while (i < tam && t[pos].status == 'O') {
    pos = (pos + i) % tam;
    i++;
  }
  if (i < tam) {
    t[pos].chave = chave;
    t[pos].status = 'O';
  } else {
    puts("Tabela cheia");
  }
}

int buscarChaveLinear(TabelaHash t, int chave) {
  int pos = funcaoHashing(chave), i = 0;
  while (i < tam && t[(pos + i) % tam].status != 'L' &&
         t[(pos + i) % tam].chave != chave) {
    i++;
  }
  return (t[(pos + i) % tam].chave == chave && t[(pos + i) % tam].status == 'O')
             ? (pos + i) % tam
             : tam;
}

int buscarChaveQuadratico(TabelaHash t, int chave) {
  int pos = funcaoHashing(chave), i = 0;
  while (i < tam && t[pos].status != 'L' && t[pos].chave != chave) {
    pos = (pos + i) % tam;
    i++;
  }
  return (t[pos].chave == chave && t[pos].status == 'O') ? pos : tam;
}

void removerChaveLinear(TabelaHash t, int chave) {
  int pos = buscarChaveLinear(t, chave);
  if (pos < tam) {
    t[pos].status = 'R';
  } else {
    puts("Chave nao existe");
  }
}

void removerChaveQuadratico(TabelaHash t, int chave) {
  int pos = buscarChaveQuadratico(t, chave);
  pos < tam ? t[pos].status = 'R' : puts("Chave nao existe");
}