#include <stdio.h>
#include <stdlib.h>

typedef struct _nodeType {
  int inf;
  struct _nodeType *next;
  struct _nodeType *point;
} nodeType;

typedef nodeType *TADgraph;

void inicializaGrafo(TADgraph *);
void joinwt(nodeType *, nodeType *, int);
void join(nodeType *, nodeType *);
void remvwt(nodeType *, nodeType *, int);
void remv(nodeType *, nodeType *);
char adjacent(nodeType *, nodeType *);
nodeType *findNode(TADgraph, int);
nodeType *addNode(TADgraph *, int);
int removNode(TADgraph *, nodeType *);
void buscaEmLargura(TADgraph, nodeType *);
void freeGraph(TADgraph);

void inicializaGrafo(TADgraph *pgraph) { *pgraph = NULL; }

void joinwt(nodeType *origem, nodeType *apontado, int weight) {
  nodeType *current = origem->point, *previous = NULL;

  while (current && current->point != apontado) {
    previous = current;
    current = current->next;
  }

  if (current) {
    current->inf = weight;
    return;
  }
  // current == NULL
  current = (nodeType *)malloc(sizeof(nodeType));
  current->point = apontado;
  current->inf = weight;
  current->next = NULL;

  if (!previous) {
    origem->point = current;
  } else {
    previous->next = current;
  }
}

void join(nodeType *origem, nodeType *apontado) {
  nodeType *current = origem->point, *previous = NULL;

  while (current && current->point != apontado) {
    previous = current;
    current = current->next;
  }

  if (current) {
    return;
  }

  current = (nodeType *)malloc(sizeof(nodeType));
  current->point = apontado;
  current->next = NULL;

  if (!previous) {
    origem->point = current;
  } else {
    previous->next = current;
  }
}

void remvwt(nodeType *origem, nodeType *apontado, int weight) {
  nodeType *current, *previous;

  current = origem->point;
  previous = NULL;

  while (current && current->next != apontado) {
    previous = current;
    current = current->next;
  }

  if (current) {
    if (!previous) {
      origem->point = current->next;
    } else {
      previous->next = current->next;
    }
    current->inf = weight;
    free(current);
  }
}

void remv(nodeType *origem, nodeType *apontado) {
  nodeType *current = origem->point, *previous = NULL;

  while (current && current->point != apontado) {
    previous = current;
    current = current->next;
  }

  if (current) {
    if (!previous) {
      origem->point = current->next;
    } else {
      previous->next = current->next;
    }
    free(current);
  }
}

char adjacent(nodeType *origem, nodeType *apontado) {
  nodeType *aresta = origem->next;

  while (aresta && aresta->point != apontado) {
    aresta = aresta->next;
  }

  if (aresta) {
    return 1;
  } else {
    return -1;
  }
}

nodeType *findNode(TADgraph pgraph, int informacao) {
  nodeType *vertice = pgraph;

  while (vertice && vertice->inf != informacao) {
    vertice = vertice->next;
  }

  return vertice;
}

nodeType *addNode(TADgraph *pgraph, int informacao) {
  nodeType *novo = (nodeType *)malloc(sizeof(nodeType));

  if (!novo)
    return NULL;

  novo->inf = informacao;
  novo->point = NULL;
  novo->next = *pgraph;
  *pgraph = novo;

  return novo;
}

int removNode(TADgraph *pgraph, nodeType *nodoRemover) {
  int retorno = 0;
  nodeType *nodoAtual, *nodoAnterior;
  nodoAtual = nodoAnterior = *pgraph;

  while (nodoAtual) {
    if (nodoAtual == nodoRemover) { // Remover aresta
      nodeType *nodoAux, *nodoAux2;
      if (nodoAtual == *pgraph) {
        *pgraph = nodoAtual->next;
      } else {
        nodoAnterior->next = nodoAtual->next;
      }

      // remover vertices do nodo
      nodoAux = nodoAtual->point;
      while (nodoAux) {
        nodoAux2 = nodoAux;
        nodoAux = nodoAux->next;
        free(nodoAux2);
      }
    } else { // Remover vertices que chegam na aresta a ser removida
      nodeType *arestaAtual, *arestaAnterior, *arestaAux;
      arestaAtual = arestaAnterior = nodoAtual->point;

      while (arestaAtual) {
        if (arestaAtual->point == nodoRemover) {
          if (arestaAtual == arestaAnterior) {
            nodoAtual->point = arestaAtual->next;
          } else {
            arestaAnterior->next = arestaAtual->next;
          }
          arestaAux = arestaAtual;
          arestaAtual = arestaAtual->next;
          free(arestaAux);
        } else {
          arestaAnterior = arestaAtual;
          arestaAtual = arestaAtual->next;
        }
      }
    }
    nodoAnterior = nodoAtual;
    nodoAtual = nodoAtual->next;
  }
  return retorno;
}

int main() { return 0; }