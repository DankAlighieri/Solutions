#include <stdio.h>
#include <stdlib.h>

#define MAX 500

/* TAD fila*/
typedef struct {
  int indMemoria;
  int indInformacao;
} DADOS;
typedef struct _nodo {
  DADOS inf;
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
void ins(fila f, DADOS inf) {
  NODO *novo = (NODO *)malloc(sizeof(NODO));
  if (!novo)
    return;

  novo->inf = inf;
  novo->next = NULL;
  if (!(f->inicio)) {
    f->inicio = novo;
  } else {
    f->fim->next = novo;
  }
  f->fim = novo;
}
DADOS cons_ret(fila f) {
  if (!(f->inicio)) {
    puts("Empty");
  } else {
    DADOS aux = f->inicio->inf;
    NODO *aux2 = f->inicio;
    f->inicio = aux2->next;
    if (!(f->inicio)) {
      f->fim = NULL;
    }
    free(aux2);
    return (aux);
  }
}

/* TAD Grafo */

typedef struct {
  int inf, point, next, livre;
  int pai, distancia;
  char cor;

} nodeGraph;

typedef nodeGraph listaDeNodos[MAX];

void inicializarGrafo(listaDeNodos l, int *graph);
void criaListaDeNodosVazios(int *listaDeNodosVazios, listaDeNodos node);
int getnode(int *listaDeNodosVazios, listaDeNodos node);
void freenode(int *listaDeNodosVazios, listaDeNodos node, int r);
void joinwt(listaDeNodos node, int *listaDeNodosVazios, int origem,
            int apontado, int wt);
void join(listaDeNodos node, int *listaDeNodosVazios, int origem, int apontado);
void remv(listaDeNodos node, int *listaDeNodosVazios, int origem, int apontado);
void remvwt(listaDeNodos node, int *listaDeNodosVazios, int origem,
            int apontado, int weight);
char adjacent(listaDeNodos node, int origem, int apontado);
int findnode(listaDeNodos node, int graph, int x);
int addnode(listaDeNodos node, int *listaDeNodosVazios, int *pgraph, int x);
int remvnode(int *listaDeNodosVazios, listaDeNodos node, int *graph, int p);
void buscaEmLargura(listaDeNodos node, int pgraph, int origem);
void imprimirCaminho(listaDeNodos node, int origem, int destino);

void inicializarGrafo(listaDeNodos l, int *graph) {
  for (int i = 0; i < MAX; i++) {
    l[i].livre = 1;
  }
  *graph = 0;
}

void criaListaDeNodosVazios(int *listaDeNodosVazios, listaDeNodos node) {
  int i;
  for (i = 1; i < MAX; i++) {
    node[i - 1].next = i;
  }
  node[i - 1].next = -1;
  *listaDeNodosVazios = 0;
}

int getnode(int *listaDeNodosVazios, listaDeNodos node) {
  int i = *listaDeNodosVazios;
  if (i != -1) {
    *listaDeNodosVazios = node[*listaDeNodosVazios].next;
    return i;
  }
  puts("Vetor cheio");
  exit(1);
}

void freenode(int *listaDeNodosVazios, listaDeNodos node, int r) {
  node[r].next = *listaDeNodosVazios;
  *listaDeNodosVazios = r;
}

void joinwt(listaDeNodos node, int *listaDeNodosVazios, int origem,
            int apontado, int wt) {
  int current = node[origem].point, previous = -1;

  while (current >= 0 && node[current].point != apontado) {
    previous = current;
    current = node[current].next;
  }

  if (current >= 0) {
    node[current].inf = wt;
    return;
  }

  current = getnode(listaDeNodosVazios, node);
  node[current].point = apontado;
  node[current].inf = wt;
  node[current].next = -1;

  if (previous < 0) {
    node[origem].point = current;
  } else {
    node[previous].next = current;
  }
}

void join(listaDeNodos node, int *listaDeNodosVazios, int origem,
          int apontado) {
  int current = node[origem].point, previous = -1;

  while (current >= 0 && node[current].point != apontado) {
    previous = current;
    current = node[current].next;
  }

  if (current < 0) {
    current = getnode(listaDeNodosVazios, node);
    node[current].point = apontado;
    node[current].next = -1;

    if (previous < 0)
      node[origem].point = current;
    else
      node[previous].next = current;
  }
}

void remvwt(listaDeNodos node, int *listaDeNodosVazios, int origem,
            int apontado, int weight) {
  int current = node[origem].point, previous = -1;

  while (current >= 0 && node[current].point != apontado) {
    previous = current;
    current = node[current].next;
  }

  if (current) {
    if (previous < 0)
      node[origem].point = node[current].next;
    else
      node[previous].next = node[current].next;

    node[current].inf = weight;
    freenode(listaDeNodosVazios, node, current);
  }
}

void remv(listaDeNodos node, int *listaDeNodosVazios, int origem,
          int apontado) {
  int current = node[origem].point, previous = -1;

  while (current >= 0 && node[current].point != apontado) {
    previous = current;
    current = node[current].next;
  }

  if (current) {      // existe vertice
    if (previous > 0) // primeiro nodo na lista de vertices
      node[origem].point = node[current].next;
    else
      node[previous].next = node[current].next;
    freenode(listaDeNodosVazios, node, current);
  }
}

char adjacent(listaDeNodos node, int origem, int apontado) {
  int aresta = node[origem].point;

  while (aresta >= 0) {
    if (node[aresta].point == apontado) {
      return 1;
    }
    aresta = node[aresta].next;
  }
  return 0;
}

int findnode(listaDeNodos node, int graph, int x) {
  int verticeAux = graph;
  while (verticeAux >= 0) {
    if (node[verticeAux].inf == x) {
      return verticeAux;
    }
    verticeAux = node[verticeAux].next;
  }
  return -1;
}

int addnode(listaDeNodos node, int *listaDeNodosVazios, int *pgraph, int x) {
  int novo = getnode(listaDeNodosVazios, node);

  node[novo].inf = x;
  node[novo].point = -1;
  node[novo].next = *pgraph;
  *pgraph = novo;
  return novo;
}

int remvnode(int *listaDeNodosVazios, listaDeNodos node, int *graph, int rem) {
  int verticeAtual, verticeAnt, retorno = 0;
  verticeAtual = verticeAnt = *graph;

  while (verticeAtual >= 0) {
    if (verticeAtual == rem) {
      int arestaAux, arestaAux2;
      if (verticeAtual == *graph)
        *graph = node[verticeAtual].next;
      else
        node[verticeAnt].next = node[verticeAtual].next;

      arestaAux = node[verticeAtual].point;

      while (arestaAux >= 0) {
        arestaAux2 = arestaAux;
        arestaAux = node[arestaAux].next;
        freenode(listaDeNodosVazios, node, arestaAux2);
      }
      freenode(listaDeNodosVazios, node, rem);
      retorno = 1;
    } else {
      int arestaAtual, arestaAnterior, aux;
      arestaAtual = arestaAnterior = node[verticeAtual].point;

      while (arestaAtual >= 0) {
        if (node[arestaAtual].point == rem) {
          if (arestaAtual == arestaAnterior) {
            node[verticeAtual].point = node[arestaAtual].next;
          } else {
            node[arestaAnterior].next = node[arestaAtual].next;
          }
          aux = arestaAtual;
          arestaAnterior = arestaAtual;
          arestaAtual = node[arestaAtual].next;
          freenode(listaDeNodosVazios, node, aux);
        } else {
          arestaAnterior = arestaAtual;
          arestaAtual = node[arestaAtual].next;
        }
      }
    }
    verticeAnt = verticeAtual;
    verticeAtual = node[verticeAtual].next;
  }
  return retorno;
}

void buscaEmLargura(listaDeNodos node, int pgraph, int origem) {
  int u, v, indice, numVertices = 0, *distancia = NULL, *pai = NULL,
                    *listaVertices = NULL;
  char *cor = NULL;
  DADOS aux;
  fila f;

  u = pgraph;

  while (u >= 0) {
    numVertices++;

    distancia = (int *)realloc(distancia, numVertices * sizeof(int));
    listaVertices = (int *)realloc(listaVertices, numVertices * sizeof(int));
    pai = (int *)realloc(pai, numVertices * sizeof(int));
    cor = (char *)realloc(cor, numVertices * sizeof(int));

    if (u != origem) {
      cor[numVertices - 1] = 'B';
      distancia[numVertices - 1] = -1;
      pai[numVertices - 1] = -1;
      listaVertices[numVertices - 1] = node[u].inf;
    } else {
      indice = numVertices - 1;
      cor[numVertices - 1] = 'C';
      distancia[numVertices - 1] = 0;
      pai[numVertices - 1] = -1;
      listaVertices[numVertices - 1] = node[u].inf;
    }
    u = node[u].next;
  }

  cria_fila(&f);
  aux.indInformacao = origem;
  aux.indMemoria = indice;
  ins(f, aux);

  while (!eh_vazia(f)) {
    aux = cons_ret(f);
    // Recuperando o endereco do nodo inserido na fila
    u = aux.indInformacao;
    v = pgraph;
    indice = -1;

    while (v >= 0) {
      indice++;
      if (adjacent(node, u, v)) {
        if (cor[indice] == 'B') {
          DADOS aux2;
          cor[indice] = 'C';
          // distancia[indice] = distancia[u] + 1; ?
          distancia[indice] = distancia[aux.indInformacao] + 1;
          pai[indice] = u;
          aux2.indInformacao = v;
          aux2.indMemoria = indice;
          ins(f, aux2);
        }
      }
      v = node[v].next;
    }
    cor[aux.indMemoria] = 'P';
  }
}

void buscaEmLargura2(listaDeNodos node, int pgraph, int origem) {
  int verticeAtual, arestaAtual, indice;
  fila f;

  verticeAtual = pgraph;

  while (verticeAtual != 0) {
    node[verticeAtual].cor = 'B';
    node[verticeAtual].distancia = -1;
    node[verticeAtual].pai = -1;

    verticeAtual = node[verticeAtual].next;
  }

  node[origem].cor = 'C';
  node[origem].distancia = 0;
  node[origem].pai = -1;

  cria_fila(&f);
  ins(f, (DADOS){origem, 0});

  while (!eh_vazia(f)) {
    verticeAtual = cons_ret(f).indMemoria;

    arestaAtual = node[verticeAtual].point;

    while (arestaAtual >= 0) {
      if (node[node[arestaAtual].point].cor == 'B') {
        node[node[arestaAtual].point].cor = 'C';
        node[node[arestaAtual].point].pai = verticeAtual;
        node[node[arestaAtual].point].distancia = node[verticeAtual].distancia + 1;
        ins(f, (DADOS) {node[arestaAtual].point, 0});
      }
      arestaAtual = node[arestaAtual].next;
    }
    node[verticeAtual].cor = 'P';
  }
}

void imprimirCaminho(listaDeNodos node, int origem, int destino) {
  if (origem == destino) {
    printf("%c ", node[origem].inf);
  } else {
    if (node[destino].pai < 0) {
      printf("Nao existe caminho");
    } else {
      imprimirCaminho(node, origem, node[destino].pai);
      printf("%c ", node[destino].inf);
    }
  }
}

int main() {}