#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _nodeType {
  int inf;
  struct _nodeType *next, *point;

  // bfs
  char cor;
  int distancia;
  struct _nodeType *pai;
} nodeType;

typedef nodeType *TADgraph;

/*TAD fila*/

typedef struct _nodo {
  nodeType *vertice;
  struct _nodo *next;
} NODO;

typedef struct {
  NODO *inicio;
  NODO *fim;
} DESCRITOR;

typedef DESCRITOR *fila;

void cria_fila(fila *f) {
  if (!(*f = (DESCRITOR *)malloc(sizeof(NODO))))
    return;
  (*f)->inicio = (*f)->fim = NULL;
}
int eh_vazia(fila f) { return !f->inicio; }
void ins(fila f, nodeType *inf) {
  NODO *novo = (NODO *)malloc(sizeof(NODO));
  if (!novo)
    return;

  novo->vertice = inf;
  novo->next = NULL;
  if (!(f->inicio)) {
    f->inicio = novo;
  } else {
    f->fim->next = novo;
  }
  f->fim = novo;
}
nodeType *cons_ret(fila f) {
  if (!(f->inicio)) {
    puts("Empty");
  } else {
    nodeType *aux = f->inicio->vertice;
    NODO *aux2 = f->inicio;
    f->inicio = aux2->next;
    if (!(f->inicio)) {
      f->fim = NULL;
    }
    free(aux2);
    return (aux);
  }
}

void inicializaGrafo(TADgraph *pgraph);
void joinwt(nodeType *origem, nodeType *apontado, int weight);
void join(nodeType *origem, nodeType *apontado);
void remvwt(nodeType *origem, nodeType *apontado, int weight);
void remv(nodeType *origem, nodeType *apontado);
char adjacent(nodeType *origem, nodeType *apontado);
nodeType *findNode(TADgraph graph, int);
nodeType *addNode(TADgraph *pgraph, int);
int removNode(TADgraph *pgraph, nodeType *aRemover);
void buscaEmLargura(TADgraph graph, nodeType *origem);
void freeGraph(TADgraph graph);

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

  current = (nodeType *)malloc(sizeof(nodeType));
  if (!current)
    return;
  current->inf = weight;
  current->point = apontado;
  current->next = NULL;

  if (!previous)
    origem->point = current;
  else
    previous->next = current;
}

void join(nodeType *origem, nodeType *apontado) {
  nodeType *current = origem->point, *previous = NULL;

  while (current && current->point != apontado) {
    previous = current;
    current = current->next;
  }

  if (!current) {
    current = (nodeType *)malloc(sizeof(nodeType));
    if (!current)
      return;

    current->point = apontado;
    current->next = NULL;

    if (!previous)
      origem->point = current;
    else
      previous->next = current;
  }
}

void remvwt(nodeType *origem, nodeType *apontado, int weight) {
  nodeType *current = origem->point, *previous = NULL;

  while (current && current->point != apontado) {
    previous = current;
    current = current->next;
  }

  // Existe aresta
  if (current) {
    if (!previous)
      origem->point = current->next;
    else
      previous->next = current->next;
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

  // Existe aresta
  if (current) {
    if (!previous)
      origem->point = current->next;
    else
      previous->next = current->next;
    free(current);
  }
}

char adjacent(nodeType *origem, nodeType *apontado) {
  nodeType *arestaAux = origem->point;

  while (arestaAux) {
    if (arestaAux->point == apontado) {
      return 1;
    }
    arestaAux = arestaAux->next;
  }

  return 0;
}

nodeType *findNode(TADgraph graph, int inf) {
  nodeType *verticeAux = graph;

  while (verticeAux) {
    if (verticeAux->inf == inf) {
      // Encontrado
      return verticeAux;
    }
    verticeAux = verticeAux->next;
  }

  // Nao encontrado
  return NULL;
}

int removNode(TADgraph *pgraph, nodeType *aRemover) {
  nodeType *verticeAtual, *verticeAnt;
  int retorno = 0;

  verticeAtual = verticeAnt = *pgraph;

  while (verticeAtual) {
    if (verticeAtual == aRemover) {
      nodeType *arestaAux, *arestaAux2;
      if (verticeAtual == *pgraph) {
        *pgraph = verticeAtual->next;
      } else {
        verticeAnt->next = verticeAtual->next;
      }

      arestaAux = verticeAtual->point;
      while (arestaAux) {
        arestaAux2 = arestaAux;
        arestaAux = arestaAux->next;
        free(arestaAux2);
      }
      free(verticeAtual);
      retorno = 1;
    } else {
      nodeType *arestaAtual, *arestaAnt, *nodoAux;
      arestaAtual = arestaAnt = verticeAtual->point;
      if (arestaAtual->point == aRemover) {
        if (arestaAtual == arestaAnt)
          verticeAtual->point = arestaAtual->next;
        else
          arestaAnt->next = arestaAtual->next;
        nodoAux = arestaAtual;
        arestaAnt = arestaAtual;
        arestaAtual = arestaAtual->next;
        free(nodoAux);
      } else {
        arestaAnt = arestaAtual;
        arestaAtual = arestaAtual->next;
      }
    }
    verticeAnt = verticeAtual;
    verticeAtual = verticeAtual->next;
  }
  return retorno;
}

void buscaEmLargura(TADgraph graph, nodeType *origem) {
  nodeType *temp;

  while (temp) {
    temp->cor = 'B';
    temp->distancia = INT_MAX;
    temp->pai = NULL;
    temp = temp->next;
  }

  origem->cor = 'C';
  origem->distancia = 0;
  origem->pai = NULL;

  fila f;
  cria_fila(&f);
  ins(f, origem);

  while (!eh_vazia(f)) {
    nodeType *u = cons_ret(f);

    // acessar lista de adjacencia de u
    nodeType *v = u->point;

    while (v) {
      if (v->cor == 'B') {
        v->cor = 'C';
        v->distancia = u->distancia + 1;
        v->pai = u;
        ins(f, v);
      }
      v = v->next;
    }
    u->cor = 'P';
  }
}

int main() { return 0; }