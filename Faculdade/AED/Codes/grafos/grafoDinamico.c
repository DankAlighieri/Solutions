#include <stdio.h>
#include <stdlib.h>

typedef struct _nodeType {
  int info;
  struct _nodeType *point;
  struct _nodeType *next;
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
void freeGraph(TADgraph);

void inicializaGrafo(TADgraph *graph) { *graph = NULL; }

/////////////////////////// WITH WEIGHT //////////////////////////////////

/*
  Adiciona um vertice entre duas arestas e atribui um peso a ele.

  @@*p: Aresta da qual o vertice emana
  @@*q: Aresta para qual o vertice aponta
  @@weight: Peso do vertice
*/
void joinwt(nodeType *p, nodeType *q, int weight) {
  nodeType *r, *r2;
  r2 = NULL;
  r = p->point;
  while (r && r->point != q) {
    r2 = r;
    r = r->next;
  }
  if (r) {
    r->info = weight;
    return;
  }

  r = (nodeType *)malloc(sizeof(nodeType));
  if (!r) {
    exit(1);
  }
  r->point = q;
  r->next = NULL;
  r->info = weight;

  (!r2) ? (p->point = r) : (r2->next = r);
}

/*
  Remove um vertice que liga duas arestas e atribui um peso a ele

  @@*p: Aresta da qual o vertice emana
  @@*q: Aresta para qual o vertice aponta
  @@weight: Peso do arco
*/
void remvwt(nodeType *p, nodeType *q, int weight) {
  nodeType *r = p->point, *r2 = NULL;
  while (r && r->point != q) {
    r2 = r;
    r = r->next;
  }

  if (r) { // Existe arco a ser removido
    if (!r2)
      p->point = r->next;
    else
      r2->next = r->next;
    r->info = weight;
    free(r);
  }
}

/////////////////////////// WEIGHTLESS //////////////////////////////////

/*
  Adiciona um vertice entre duas arestas.

  @@*p: Aresta da qual o vertice emana
  @@*q: Aresta para qual o vertice aponta
*/

void join(nodeType *p, nodeType *q) {
  nodeType *r = p->point, *r2 = NULL;
  while (r && r->point != q) {
    r2 = r;
    r = r->next;
  }

  if (!r) {
    r = (nodeType *)malloc(sizeof(nodeType));
    if (!r) {
      exit(1);
    }
    r->point = q;
    r->next = NULL;
    (!r2) ? (p->point = r) : (r2->next = r);
  }
}

/*
  Remove um vertice que liga duas arestas

  @@*p: Aresta da qual o vertice emana
  @@*q: Aresta para qual o vertice aponta
*/
void remv(nodeType *p, nodeType *q) {
  nodeType *r = p->point, *r2 = NULL;
  while (r && r->point != q) {
    r2 = r;
    r = r->next;
  }

  if (r) { // Existe arco a ser removido
    if (!r2)
      p->point = r->next;
    else
      r2->next = r->next;
    free(r);
  }
}

/*
  Verifica se duas arestas sao adjacentes. Retorna 1 se sim, -1 se nao

  @@*p: Aresta origem
  @@*q: Aresta destino
*/
char adjacent(nodeType *p, nodeType *q) {
  nodeType *r = p->point;
  while (r && r->point != q) {
    r = r->next;
  }
  return (r) ? 1 : -1;
}

/*
  Procura uma aresta no grafo e a retorna

  @@graph: Inicio do grafo
  @@info: Informacao contida no grafo
*/

nodeType *findNode(TADgraph graph, int info) {
  TADgraph r = graph;
  while (r && r->info != info) {
    r = r->next;
  }

  return r;
}

/*
  Adiciona uma aresta ao grafo

  @@*graph: Ponteiro para o primeiro elemento do grafo
  @@info: Informacao da nova aresta
*/

nodeType *addNode(TADgraph *graph, int info) {
  nodeType *aux = *graph;

  nodeType *novo = (nodeType *)malloc(sizeof(nodeType));
  if (!novo) {
    exit(1);
  }
  novo->info = info;
  novo->point = NULL;
  novo->next = *graph;
  *graph = novo;
  return novo;
}

/*
  Remove uma aresta do grafo e retorna um status.
  1 - Bem-sucedido
  -1 - Falha

  @@*graph: Ponteiro para o primeiro elemento do grafo
  @@*aresta: Ponteiro para a aresta a ser removida
*/

int removNode(TADgraph *graph, nodeType *aresta) {
  int retorno = 0;
  nodeType *auxAtual, *auxAnterior;
  auxAtual = auxAnterior = *graph;
  while (auxAtual) {
    // Remover aresta
    if (auxAtual == aresta) {
      nodeType *nodoAux, *nodoAux2;
      if (auxAtual == *graph) {
        *graph = (*graph)->next;
      } else {
        auxAnterior->next = auxAtual->next;
      }

      // Remover vertices que emanam da aresta a ser removida
      nodoAux = auxAtual->point;
      while (nodoAux) {
        nodoAux2 = nodoAux;
        nodoAux = nodoAux->next;
        free(nodoAux2);
      }
      auxAnterior = auxAtual;
      auxAtual = auxAtual->next;
      free(aresta);
      retorno = 1;
    } else {
      // Remover todos os vertices que tem destino final a aresta removida
      nodeType *nodoAtual, *nodoAnterior, *nodoAux;
      nodoAtual = nodoAnterior = auxAtual->point;
      while (auxAtual) {
        if (nodoAtual->point == aresta) {
          if (nodoAtual == nodoAnterior) {
            nodoAtual->point = nodoAtual->next;
          } else {
            nodoAnterior->next = nodoAtual->next;
          }
          nodoAux = nodoAtual;
          nodoAnterior = nodoAtual;
          nodoAtual = nodoAtual->next;
          free(nodoAux);
        } else {
          nodoAnterior = nodoAtual;
          nodoAtual = nodoAtual->next;
        }
      }
    }
    auxAnterior = auxAtual;
    auxAtual = auxAtual->next;
  }
  return retorno;
}

int main() { return 0; }
