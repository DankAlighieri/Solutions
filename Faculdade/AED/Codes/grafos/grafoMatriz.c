#include <stdio.h>

#define MAXNODE 6

typedef struct {
  // informacoes associadas ao no
} node;

typedef struct {
  int adj;
  int peso;
} arc;

typedef struct {
  node nodes[MAXNODE];
  arc arcs[MAXNODE][MAXNODE];
} Graph;

void inicializarGrafo(Graph *g) {
  for (int i = 0; i < MAXNODE; i++) {
    for (int j = 0; j < MAXNODE; j++) {
      g->arcs[i][j].adj = 0;
      g->arcs[i][j].peso = 0;
    }
  }
}

void ligar(Graph *g, int node1, int node2) { g->arcs[node1][node2].adj = 1; }

void remover(Graph *g, int node1, int node2) { g->arcs[node1][node2].adj = 0; }

int adjacente(Graph *g, int node1, int node2) {
  return g->arcs[node1][node2].adj;
}

void ligarP(Graph *g, int node1, int node2, int peso) {
  g->arcs[node1][node2].adj = 1;
  g->arcs[node1][node2].peso = peso;
}

void removerP(Graph *g, int node1, int node2, int peso) {
  g->arcs[node1][node2].adj = 0;
  g->arcs[node1][node2].peso = peso;
}

int adjacenteP(Graph *g, int node1, int node2) {
  return g->arcs[node1][node2].adj;
}

void mostrarHash(Graph *g) {
  for (int i = 0; i < MAXNODE; i++) {
    for (int j = 0; j < MAXNODE; j++) {
      printf("%d ", g->arcs[i][j].adj);
    }
    putchar('\n');
  }
}

int procurarCaminho(Graph *g, int node1, int node2, int nr) {
  if (nr == 1) {
    return adjacente(g, node1, node2);
  }
  for (int c = 0; c < MAXNODE; c++) {
    if (adjacente(g, node1, c) && procurarCaminho(g, c, node2, nr - 1)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  Graph g;
  inicializarGrafo(&g);
  ligar(&g, 0, 1);
  ligar(&g, 0, 2);
  ligar(&g, 0, 3);
  ligar(&g, 3, 4);

  mostrarHash(&g);

  printf("%s\n", procurarCaminho(&g, 0, 4, 2) ? 
    "Existe um caminho" : 
    "Nao existe um caminho");

  return 0;
}