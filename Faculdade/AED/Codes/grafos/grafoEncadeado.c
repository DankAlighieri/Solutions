#include <stdio.h>
#include <stdlib.h>

#define MAXNODES 500

/*
  TAD FILA
*/

typedef struct {
  int indInformacao;
  int indMemoria;
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
  *f = (DESCRITOR *)malloc(sizeof(NODO));
  if (!(*f))
    return;
  (*f)->inicio = (*f)->fim = NULL;
}

int eh_vazia(fila f) { return !f->inicio; }

void ins(fila f, DADOS inf) {
  NODO *novo = (NODO *)malloc(sizeof(DADOS));
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
    puts("Vazia");
  } else {
    DADOS aux = f->inicio->inf;
    NODO *aux2 = f->inicio;
    f->inicio = f->inicio->next;
    if (!(f->inicio)) {
      f->fim = NULL;
    }
    free(aux2);
    return aux;
  }
}

/* TAD Grafo*/

typedef struct {
  int info;
  int next;
  int point;
  int livre;
} tipoNodo;

typedef tipoNodo listaDeNodos[MAXNODES];

void criaListaNodosVazios(int *, listaDeNodos);
int getNode(int *, listaDeNodos);
void freeNode(int *, listaDeNodos, int);

void inicializarGrafo(listaDeNodos l, int *grafo) {
  for (int i = 0; i < MAXNODES; i++)
    l[i].livre = 1;
  *grafo = -1;
}

void joinwt(listaDeNodos l, int *listaNodosVazios, int a, int b, int wt) {
  int r = l[a].point, r2 = -1;
  // Procurando pelo arco <A,B>
  while (r >= 0 && l[r].point != b) {
    r2 = r;
    r = l[r].next;
  }
  if (r >= 0) {
    l[r].info = wt;
    return;
  }
  // Arco <A,B> nao existe, necessario cria-lo
  r = getNode(listaNodosVazios, l);
  l[r].point = b;
  l[r].next = -1;
  l[r].info = wt;
  (r2 < 0) ? (l[a].point = r) : (l[r2].next = r);
}

// Lista para nodos vazios para arcos
void criaListaNodosVazios(int *listaNodosVazios, listaDeNodos l) {
  int i;
  for (i = 0; i < MAXNODES; i++)
    l[i - 1].next = i;
  l[i - 1].next = -1;
  *listaNodosVazios = 0;
}

// Encontra um nodo vazio para armazenar a informacao de um arco
int getNode(int *listaDeNodosVazios, listaDeNodos l) {
  int i = *listaDeNodosVazios;
  if (i != -1) {
    *listaDeNodosVazios = l[*listaDeNodosVazios].next;
    return i;
  }
  puts("Mem ins");
  exit(0);
}

void join(int *listaNodosVazios, listaDeNodos l, int a, int b) {
  int r = l[a].point, r2 = -1;
  while (r >= 0 && l[r].point != b) {
    r2 = r;
    r = l[r].next;
  }

  if (r >= 0) {
    return;
  }
  r = getNode(listaNodosVazios, l);
  l[r].point = b;
  l[r].next = -1;
  (r2 < 0) ? (l[a].point = r) : (l[r2].next = r);
}

// Remove o arco entre dois nodos
void remv(listaDeNodos l, int *listaDeNodosVazios, int p, int q) {
  // r aponta para um arco que emana de p, r2 sera seu antecessor
  int r = l[p].point, r2 = -1;
  // Procurando o arco de nodo
  while (r >= 0 && l[r].point != q) {
    r2 = r;
    r = l[r].next;
  }
  // Arco de nodo encontrado
  if (r >= 0) {
    /*
        Dois casos:
        1 - Eh o Primeiro arco
        2 - Nao eh o primeiro arco
    */

    if (r2 < 0) {
      // Primeiro ou unico arco
      l[p].point = l[r].next;
    } else {
      // Qualquer outro arco
      l[r2].next = l[r].next;
    }
    // Metodo para liberar o nodo que armazenada o arco
    freeNode(listaDeNodosVazios, l, r);
    return;
  }
  // Caso nao exista, nao eh necessario fazer nada
}

void freeNode(int *listaDeNodosVazios, listaDeNodos l, int r) {
  // Adicionado o endereco r a lista de nodos vazios
  // next de r sera o antigo inicio da lista de nodos vazios
  l[r].next = *listaDeNodosVazios;
  // adicionando r ao inicio da lista de nodos vazios
  *listaDeNodosVazios = r;
}

void remvwt(listaDeNodos l, int *listaDeNodosVazios, int p, int q, int wt) {
  int r = l[p].point, r2 = -1;
  while (r >= 0 && l[r].point != q) {
    r2 = r;
    r = l[r].next;
  }
  if (r >= 0) {
    if (r2 < 0) {
      l[p].point = l[r].next;
    } else {
      l[r2].next = l[r].next;
    }
    l[r].info = wt;
    freeNode(listaDeNodosVazios, l, r);
  }
}

char adjacent(listaDeNodos l, int p, int q) {
  int arco = l[p].point;
  while (arco >= 0 && l[arco].point != q) {
    arco = l[arco].next;
  }
  return (arco >= 0) ? arco : -1;
}

/*
    Busca uma aresta no grafo, se existir retorna um ponteiro para seu endereco

    @@l: Lista de nodos que armazena o grafo

    @@graph: Ponteiro para o primeiro elemento do grafo

    @@x: Informacao da aresta a ser procurada
*/
int findNode(listaDeNodos l, int graph, int x) {
  int n = graph;
  while (n >= 0) {
    if (l[n].info == x) {
      return n;
    }
    n = l[n].next;
  }
  return -1;
}

/*
    Adiciona uma aresta ao grafo e retorna um ponteiro para ela

    @@l: Lista de nodos que armazena o grafo

    @@listaDeNodosVazios: Ponteiro para o primeiro endereco da lista de
   enderecos vazios dentro do vetor que armazena o grafo

    @@pgraph: Ponteiro para a primeira aresta do grafo

    @@x: Informacao da aresta
*/

int addNode(listaDeNodos l, int *listaDeNodosVazios, int *pgraph, int x) {
  int r = getNode(listaDeNodosVazios, l);
  l[r].info = x;
  l[r].point = -1;
  l[r].next = *pgraph;
  *pgraph = r;
  return r;
}

/*
    Remove uma aresta do grafo e retorna 1 caso a remoção tenha sido bem
   sucedida e 0 caso tenho ocorrido algum problema

    @@*listaDeNodosVazios: Ponteiro para o primeiro endereco da lista de
   enderecos vazios dentro do vetor que armazena o grafo

    @@l: Lista de nodos que armazena o grafo

    @@*graph: Ponteiro para o primeiro elemento do grafo

    @@p: Informacao de qual aresta a ser removida

*/

int removNode(int *listaDeNodosVazios, listaDeNodos l, int *graph, int p) {
  int i, nodoAtual, nodoAnterior, retorno = 0;
  nodoAtual = nodoAnterior = *graph;

  while (nodoAtual >= 0) {
    // Remover todas os vertices com origem na aresta e a propria aresta

    if (nodoAtual == p) { // Remover o nodo
      int nodoAux, nodoAux2;
      if (nodoAtual == *graph) { // Primeira aresta do grafo
        *graph = l[*graph].next;
      } else {
        l[nodoAnterior].next =
            l[nodoAtual].next; // Qualquer outra aresta do grafo
      }
      // recebendo o endereco do primeiro vertice que emana dessa aresta
      nodoAux = l[nodoAtual].point;
      while (nodoAux >= 0) {
        nodoAux2 = nodoAux;
        nodoAux = l[nodoAux].next;
        freeNode(listaDeNodosVazios, l, nodoAux2); // Eliminando arestas
      }
      nodoAnterior = nodoAtual;
      nodoAtual = l[nodoAtual].next;
      freeNode(listaDeNodosVazios, l, p);
      retorno = 1;
    } else {
      // Remover todos os vertices que levam ao nodo que esta sendo removido
      int auxAnterior, auxAtual, nodoAux;
      // Vertices que emanam do nodo atual
      auxAnterior = auxAtual = l[nodoAtual].point;
      while (nodoAtual >= 0) {
        if (l[auxAtual].point == p) { // Nodo atual possui vertice que aponta
                                      // para a aresta que esta sendo removida
          if (auxAtual == auxAnterior) {

            /*
                Aux atual eh o vertice que emana de nodoAtual
                Caso l[auxAtual].point == p, significa que esse vertice
                aponta para o endereco de memoria de p e ele eh o primeiro
                da lista de vertices.
            */
            l[nodoAtual].point = l[auxAtual].next;
          } else {
            l[auxAnterior].next = l[auxAtual].next;
          }
          nodoAux = auxAtual;
          auxAnterior = auxAtual;
          auxAtual = l[auxAtual].next;
          freeNode(listaDeNodosVazios, l, nodoAux);
        } else {
          auxAnterior = auxAtual;
          auxAtual = l[auxAtual].next;
        }
      }
      nodoAnterior = nodoAtual;
      nodoAtual = l[nodoAtual].next;
    }
  }
  return retorno;
}

/*
  Realiza uma busca em largura baseado em um nodo origem escolhido.

  @@l: Lista de nodos que armazena o grafo
  @@G: Ponteiro para o primeiro elemento na lista de nodos de vertice
  @@s: Nodo escolhido como origem para a busca em largura
*/

void buscaEmLargura(listaDeNodos l, int G, int s) {
  int verticeAux, *distancia = NULL, *pai = NULL, *listaDeVertices = NULL,
                  numeroDeVertices = 0, verticeAtual, indice;
  char *cor = NULL;
  fila Queue;
  DADOS aux;
  verticeAux = G;
  // Inicializar o grafo para a busca
  while (verticeAux >= 0) {

    // inicializando os vetores;
    ++numeroDeVertices;
    distancia = (int *)realloc(distancia, numeroDeVertices * sizeof(int));
    pai = (int *)realloc(pai, numeroDeVertices * sizeof(int));
    cor = (char *)realloc(cor, numeroDeVertices * sizeof(char));
    listaDeVertices =
        (int *)realloc(listaDeVertices, numeroDeVertices * sizeof(int));

    if (verticeAux != s) { // Inicializar os vertices a serem buscados
      cor[numeroDeVertices - 1] = 'B';
      distancia[numeroDeVertices - 1] = -1;
      pai[numeroDeVertices - 1] = -1;
    } else { // Eh o vertice escolhido como origem

      // Indice de s na lista que armazena o grafo
      indice = numeroDeVertices - 1;
      cor[numeroDeVertices - 1] = 'C';
      distancia[numeroDeVertices - 1] = 0;
      pai[numeroDeVertices - 1] = -1;
    }

    // ????
    listaDeVertices[numeroDeVertices - 1] = l[verticeAux].info;
    verticeAux = l[verticeAux].next;
  }
  cria_fila(&Queue);

  // Armazenando as informacoes do vertice origem
  aux.indInformacao = s;
  aux.indMemoria = indice;
  // Primeiro elemento da fila sera s, o vertice escolhido como a origem
  ins(Queue, aux);

  while (!(eh_vazia(Queue))) {
    // Recuperando informacoes do primeiro vertice na fila
    aux = cons_ret(Queue);
    // Informacao do vertice da fila
    verticeAux = aux.indInformacao;
    // Comecando do inicio da lista de Grafo
    verticeAtual = G;
    // resetando os indices
    indice = -1;
    // Procurando todos os vertices pertencentes ao Grafo que sao adjacentes ao vertice que foi retirado da fila
    while (verticeAtual >= 0) {
      indice++;
      // Caso seja adjacente
      if (adjacent(l, verticeAux, verticeAtual)) { 
        // Caso nao tenha sido visitado nenhuma vez
        if (cor[indice] == 'B') {
          DADOS aux2;
          cor[indice] = 'C';
          // Atualizando sua distancia do vertice origem
          distancia[indice] = distancia[aux.indMemoria] + 1;
          // Setando seu predecessor
          pai[indice] = verticeAux;
          // Salvando suas informacoes na fila para ser verificado posteriormente
          aux2.indInformacao = verticeAtual;
          aux2.indMemoria = indice;
          ins(Queue, aux2);
        }
      }
      // Indo para o proximo vertice no grafo
      verticeAtual = l[verticeAtual].next;
    }
    // Mudando a cor para preto para indicar que tudo ja foi feito aqui
    cor[aux.indMemoria] = 'P';
  }
}

int main() { return 0; }