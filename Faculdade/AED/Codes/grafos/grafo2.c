#include <stdio.h>
#include <stdlib.h>

#define MAXNODES 500

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

/* TAD Grafo*/

typedef struct {
  int inf;
  int next;
  int point;
  int livre;
  int distancia;
  int pai;
  char cor;
} tipoNodo;

typedef tipoNodo listaDeNodos[MAXNODES];

void inicializarGrafo(listaDeNodos l, int *graph);
void criaListaDeNodosVazios(int *listaDeNodosVazios, listaDeNodos node);
int getnode(int *listaDeNodosVazios, listaDeNodos node);
void freenode(int *listaDeNodosVazios, listaDeNodos node, int r);
void joinwt(listaDeNodos node, int *listaDeNodosVazios, int p, int q, int wt);
void join(listaDeNodos node, int *listaDeNodosVazios, int p, int q);
void remv(listaDeNodos node, int *listaDeNodosVazios, int p, int q);
void remvwt(listaDeNodos node, int *listaDeNodosVazios, int p, int q, int x);
char adjacent(listaDeNodos node, int p, int q);
int findnode(listaDeNodos node, int graph, int x);
int addnode(listaDeNodos node, int *listaDeNodosVazios, int *pgraph, int x);
int remvnode(int *listaDeNodosVazios, listaDeNodos node, int *graph, int p);

/*
    Inicializa o vetor na memoria que ira armazenar o grafo

    @param l: ponteiro para a lista
    @param *graph: Ponteiro para o primeiro elemento do grafo
*/

void inicializarGrafo(listaDeNodos l, int *graph) {
  for (int i = 0; i < MAXNODES; i++) {
    l[i].livre = 1;
  }
  *graph = -1; // vazio
}

/*
    Criando uma lista de nodos vazios livres para serem utilizados durante as
   operacoes com o grafo

    @param *listaDeNodosVazios: ponteiro para o primeiro elemento da lista de
   nodos vazios
    @param node: Lista de nodos que armazena o grafo
*/

void criaListaDeNodosVazios(int *listaDeNodosVazios, listaDeNodos node) {
  int i;
  for (i = 1; i < MAXNODES; i++) {
    node[i - 1].next = i;
  }
  node[i - 1].next = -1;
  *listaDeNodosVazios = 0;
}

/*
    Recupera o endereco de um nodo vazio


    @param *listaDeNodosVazios: ponteiro para o primeiro elemento da lista de
   nodos vazios
    @param node: Lista de nodos que armazena o grafo
*/

int getNode(int *listaDeNodosVazios, listaDeNodos node) {
  // Salvando endereco do primeiro nodo da lista
  int i = *listaDeNodosVazios;
  if (i != -1) {
    *listaDeNodosVazios = node[*listaDeNodosVazios].next;
    return i;
  }
  puts("Mem insuficiente");
  exit(1);
}

/*
    Recebe o endereco de um nodo para ser liberado da memoria

    @param *listaDeNodosVazios: ponteiro para o primeiro elemento da lista de
   nodos vazios
    @param node: Lista de nodos que armazena o grafo
    @param r: Endereco a ser liberado
*/

void freeNode(int *listaDeNodosVazios, listaDeNodos node, int r) {
  // Adicionado o endereco r a lista de nodos vazios
  // next de r sera o antigo inicio da lista de nodos vazios
  node[r].next = *listaDeNodosVazios;
  // adicionando r ao inicio da lista de nodos vazios
  *listaDeNodosVazios = r;
}

/*
  Cria um arco direcional com peso entre dois vertices dentro de um grafo
  ponderado.

  @param *listaDeNodosVazios: ponteiro para o primeiro elemento da lista de
  nodos vazios

  @param node: Lista de nodos que armazena o grafo

  @param p: vertice a partir do qual o arco esta emanando

  @param q: Vertice que destino do arco

  @para wt: Peso do arco
*/

void joinwt(listaDeNodos node, int *listaDeNodosVazios, int p, int q, int wt) {
  int r = node[p].point, r2 = -1;
  while (r >= 0 && node[r].point != q) {
    r2 = r;
    r = node[r].next;
  }

  if (r >= 0) {
    node[r].inf = wt;
    return;
  }

  r = getNode(listaDeNodosVazios, node);
  node[r].inf = wt;
  node[r].next = -1;
  node[r].point = q;
  (r2 < 0) ? (node[p].point = r) : (node[r2].next = r);
}

/*
  Cria um arco direcional entre dois vertices dentro de um grafo.

  @param *listaDeNodosVazios: ponteiro para o primeiro elemento da lista de
  nodos vazios

  @param node: Lista de nodos que armazena o grafo

  @param p: vertice a partir do qual o arco esta emanando

  @param q: Vertice que destino do arco
*/

void join(listaDeNodos node, int *listaDeNodosVazios, int p, int q) {
  int r = node[p].point, r2 = -1;
  while (r >= 0 && node[r].point != q) {
    r2 = r;
    r = node[r].next;
  }

  if (r >= 0)
    return;
  r = getNode(listaDeNodosVazios, node);
  node[r].next = -1;
  node[r].point = q;

  (r2 < 0) ? (node[p].point = r) : (node[r2].next = r);
}

/*
  Remove uma aresta entre dois vértices e atribui a ela um peso

  @param *listaDeNodosVazios: ponteiro para o primeiro elemento da lista de
  nodos vazios

  @param node: Lista de nodos que armazena o grafo

  @param p: vertice a partir do qual o arco esta emanando

  @param q: Vertice que destino do arc

  @param x: Peso que sera atribuido a aresta
*/

void remvwt(listaDeNodos node, int *listaDeNodosVazios, int p, int q, int x) {
  int r = node[p].point, r2 = -1;
  while (r >= 0 && node[r].point != q) {
    r2 = r;
    r = node[r].next;
  }

  if (r >= 0) {
    (r2 < 0) ? (node[p].point = node[r].next) : (node[r2].next = node[r].next);
    node[r].inf = x;
    freeNode(listaDeNodosVazios, node, r);
  }
}

/*
  Remove uma aresta entre dois vértices

  @param *listaDeNodosVazios: ponteiro para o primeiro elemento da lista de
  nodos vazios

  @param node: Lista de nodos que armazena o grafo

  @param p: vertice a partir do qual o arco esta emanando

  @param q: Vertice que destino do arc
*/

void remv(listaDeNodos node, int *listaDeNodosVazios, int p, int q) {
  int r = node[p].point, r2 = -1;

  while (r >= 0 && node[r].point != q) {
    r2 = r;
    r = node[r].next;
  }

  if (r >= 0) {
    puts("Arco encontrado");
    if (r2 < 0) {
      node[p].point = node[r].next;
    } else {
      node[r2].next = node[r].next;
    }
    freeNode(listaDeNodosVazios, node, r);
    return;
  }
}

/*
  Recebe dois vertices de um grafo e determina se eles são adjacentes ou não
  Retorna 1 caso sejam, 0 caso não.

  @param node: Lista de nodos que armazena o grafo
  @param p: Ponteiro para o vertice do qual emanana a aresta
  @param q: Ponteiro para o vertice que a aresta aponta
*/

char adjacent(listaDeNodos node, int p, int q) {
  int aresta = node[p].point;
  while (aresta >= 0) {
    if (node[aresta].point == q)
      return 1;
    aresta = node[aresta].next;
  }
  return 0;
}

/*
  Recebe um inteiro e verifica se ele esta presenta no grafo.
  Retorna o indice caso exista. Caso contrario, retorna -1.

  @param node: Lista de nodos que armazena o grafo
  @param graph: Ponteiro para o primeiro vertice do grafo
  @param x: Informacao a ser procurado no grafo
*/

int findnode(listaDeNodos node, int graph, int x) {
  int verticeAux = graph;
  while (verticeAux >= 0 && node[verticeAux].inf != x) {
    verticeAux = node[verticeAux].next;
  }

  return (verticeAux >= 0) ? verticeAux : -1;
}

/*
  Adiciona um vértice ao grafo e retorna um ponteiro para ele

  @param *listaDeNodosVazios: ponteiro para o primeiro elemento da lista de
  nodos vazios

  @param node: Lista de nodos que armazena o grafo

  @param *pgraph: Ponteiro para o primeiro elemento no grafo

  @param x: Informação do vértice
*/

int addnode(listaDeNodos node, int *listaDeNodosVazios, int *pgraph, int x) {
  int r = getNode(listaDeNodosVazios, node);
  node[r].inf = x;
  node[r].point = -1;
  node[r].next = *pgraph;
  *pgraph = r;
  return r;
}

/*
  Remove um vértice do grafo e todas as arestas que emanam dele ou são emanadas
  a ele

  @param *listaDeNodosVazios: Ponteiro para o primeiro nodo na lista de nodos
  vazios
  @param node: Ponteiro para o primeiro nodo da lista que armazena o grafo
  @param p: Ponteiro para o vértice a ser removido
*/

int remvnode(int *listaDeNodosVazios, listaDeNodos node, int *graph, int p) {
  int nodoAtual, nodoAnterior, retorno = 0;
  nodoAtual = nodoAnterior = *graph;

  // Percorrer o grafo procurando o nodo e seus arcos
  while (nodoAtual >= 0) {
    if (nodoAtual == p) {
      int nodoAux, nodoAux2;
      // Caso seja o primeiro vertice na lista de grafo
      if (nodoAtual == *graph) {
        *graph = node[*graph].next;
      } else {
        node[nodoAnterior].next = node[nodoAtual].next;
      }

      nodoAux = node[nodoAtual].point; // Remover arestas

      while (nodoAux >= 0) {
        nodoAux2 = nodoAux;
        nodoAux = node[nodoAux].next;
        freeNode(listaDeNodosVazios, node, nodoAux2);
      }
      freeNode(listaDeNodosVazios, node, p);
      retorno = 1;
    } else { // Caso nao seja o nodo a ser removido
             /* Encontrar nodos que emanam para p*/
      int auxAnterior, auxAtual, nodeAux;
      auxAnterior = auxAtual = node[nodoAtual].point;
      while (auxAtual >= 0) {
        if (node[auxAtual].point == p) {
          if (auxAtual == auxAnterior)
            node[nodoAtual].point = node[auxAtual].next;
          else
            node[auxAnterior].next = node[auxAtual].next;
          nodeAux = auxAtual;
          auxAnterior = auxAtual; //??
          auxAtual = node[auxAtual].next;
          freeNode(listaDeNodosVazios, node, nodeAux);
        } else {
          auxAnterior = auxAtual;
          auxAtual = node[auxAtual].next;
        }
      }
    }
    nodoAnterior = nodoAtual;
    nodoAtual = node[nodoAtual].next;
  }
  return retorno;
}

/*
  u: A variável usada para percorrer os nós.

  d: Vetor que armazena as distâncias de cada vértice em relação ao vértice de
  origem s.

  pai: Vetor que armazena o pai (vértice anterior) de cada vértice durante
  busca. vertice: Vetor que armazena os valores dos vértices no grafo.

  numVertices: Conta o número total de vértices no grafo.

  v: Variável usada para iterar sobre os vértices adjacentes de um nó.

  ind:Índice usado para iterar no vetor de vértices.

  cor: Vetor que armazena a cor de cada vértice (usado para indicar o status de
  visita: 'B' para não visitado, 'C' para visitado, 'P' para processado).

  f: Fila usada para implementar a BFS (estruturalmente, uma fila de
  prioridade).

  aux: Estrutura auxiliar usada para manipulação de elementos na fila.
*/

void buscaEmLargura(listaDeNodos node, int graph, int origem) {
  int u, v, numVertice = 0, indice, *distancia = NULL, *pai = NULL;
  int *listaVertices = NULL;
  char *cor = NULL;
  fila f;
  DADOS aux;

  u = graph;

  // Inicializar vetores
  while (u >= 0) {
    ++numVertice;
    distancia = (int *)realloc(distancia, numVertice * sizeof(int));
    pai = (int *)realloc(pai, numVertice * sizeof(int));
    listaVertices = (int *)realloc(listaVertices, numVertice * sizeof(int));
    cor = (char *)realloc(cor, numVertice * sizeof(char));

    // Verifica se eh origem
    if (u != origem) {
      distancia[numVertice - 1] = -1;
      cor[numVertice - 1] = 'B';
      pai[numVertice - 1] = -1;
      listaVertices[numVertice - 1] = node[u].inf;
    } else {
      indice = numVertice - 1;
      distancia[numVertice - 1] = 0;
      cor[numVertice - 1] = 'C';
      pai[numVertice - 1] = -1;
      listaVertices[numVertice - 1] = node[u].inf;
    }
    u = node[u].next;
  }

  // Cria a fila para armazenar os vertices a serem explorados
  cria_fila(&f);
  aux.indInformacao = origem; // Indice do vertice de origem no vetor do grafo
  aux.indMemoria = indice;    // indice do vertice nos vetores de controle
  ins(f, aux);

  while (!eh_vazia(f)) {
    aux = cons_ret(f);
    u = aux.indInformacao; // vertice atual
    v = graph;             // vertice a ser explorado
    indice = -1;

    while (v >= 0) {
      indice++;
      // se o vertice atual eh adjacente ao vertice origem
      if (adjacent(node, u, v)) {
        if (cor[indice] == 'B') { // V ainda nao foi visitado
          DADOS aux2;
          cor[indice] = 'C';
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

void buscaEmLargura2(listaDeNodos node, int graph, int origem) {
  int u, v, indice;
  fila f;

  u = graph;

  while (u >= 0) {
    if (u != origem) {
      node[u].cor = 'B';
      node[u].pai = -1;
      node[u].distancia = -1;
    } else {
      node[u].cor = 'C';
      node[u].pai = -1;
      node[u].distancia = 0;
    }
    u = node[u].next;
  }

  cria_fila(&f);
  // Adiciona indice do vertice origem, em uma fila
  ins(f, (DADOS){origem, 0});
  // normal seria ins(f,origem);

  while (!eh_vazia(f)) {
    u = cons_ret(f).indMemoria; // indice da origem

    v = node[u].point; // Acessando a lista de arestas de u
    while (v >= 0) {
      if (node[node[v].point].cor == 'B') { // n foi acessado
        node[node[v].point].cor = 'C';
        node[node[v].point].distancia = node[u].distancia + 1;
        node[node[v].point].pai = u;
        // Utiliizando uma fila de inteiros, seria apenas
        // ins(f, node[v].point);
        ins(f, (DADOS){node[v].point, 0});
      }
      v = node[v].next;
    }
    node[u].cor = 'P';
  }
}

void visitaProfundidade(listaDeNodos node, int u, int v) {}

void imprimirCaminho(listaDeNodos node, int s, int v) {
  if (v == s) {
    printf("%d ", node[s].inf);
  } else {
    if (node[v].pai == -1) {
      printf("\nNenhum caminho de \"%c\" para \"%c\" existente.\n", node[s].inf,
             node[v].inf); // Informa que não existe caminho
    } else {
      imprimirCaminho(node, s, v);
      printf("%c ", node[v].inf);
    }
  }
}

/*
  Funcoes de teste
*/

void mostrarGrafo(listaDeNodos node, int pgraph) {
  int aux = pgraph;
  printf("========= INICIO DO GRAFO ==========\n");
  while ((aux) >= 0) {
    printf("%d ", node[aux].inf);
    aux = node[aux].next;
  }
  putchar('\n');
  printf("========= FIM DO GRAFO ==========\n");
}

void mostrarArestas(listaDeNodos node, int *pgraph) {
  int verticeAtual = *pgraph, arestaAux;
  while (verticeAtual >= 0) {
    printf("=== LISTA DE ADJACENCIA DO VERTICE %d ===\n",
           node[verticeAtual].inf);
    arestaAux = node[verticeAtual].point;
    while (arestaAux >= 0) {
      int temp = node[arestaAux].point;
      printf("%d -> %d\n", node[verticeAtual].inf, node[temp].inf);
      arestaAux = node[arestaAux].next;
    }
    verticeAtual = node[verticeAtual].next;
    puts("=== FIM DA LISTA DE ADJACENCIA ===");
    putchar('\n');
  }
}

int main() {
  listaDeNodos node;
  int pgraph, listaDeNodosVazios, p, q, a, b, c, d;

  inicializarGrafo(node, &pgraph);
  criaListaDeNodosVazios(&listaDeNodosVazios, node);
  // printf("%d\n", pgraph);

  for (int i = 10; i > 0; i--) {
    addnode(node, &listaDeNodosVazios, &pgraph, i);
  }

  p = findnode(node, pgraph, 1);
  q = findnode(node, pgraph, 2);
  a = findnode(node, pgraph, 3);
  b = findnode(node, pgraph, 4);
  c = findnode(node, pgraph, 9);
  d = findnode(node, pgraph, 10);

  join(node, &listaDeNodosVazios, p, q); // <1,2>
  join(node, &listaDeNodosVazios, q, a); // <2,3>
  join(node, &listaDeNodosVazios, b, d); // <4,9>
  join(node, &listaDeNodosVazios, c, d); // <9,10>
  join(node, &listaDeNodosVazios, d, p); // <10,1>
  join(node, &listaDeNodosVazios, q, p); // <2,1>

  // remv(node, &listaDeNodosVazios, p, a);

  // mostrarArestas(node, &pgraph);

  // mostrarGrafo(node, pgraph);
  // mostrarArestas(node, &pgraph);
  // putchar('\n');
  // putchar('\n');
  // putchar('\n');
  // putchar('\n');
  // remvnode(&listaDeNodosVazios, node, &pgraph, p);
  // mostrarArestas(node, &pgraph);
}