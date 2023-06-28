#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

typedef struct NoAWheight {
   int id;          /*Identificador armazenado no nó. */
   int wheight; /*wheight of the connection */
   struct noA *next; /* Próximo nó na lista encadeada. */
} NoAWheight;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoA **Adj; /* Lista de adjacências. */
} GrafoA;

typedef struct GrafoAWheight {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoAWheight **Adj; /* Lista de adjacências. */
} GrafoAWheight;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matrix de adjacências. */
} GrafoM;

/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj (int tamanho) {
   int v;
   GrafoA* G = (GrafoA*)malloc(sizeof(GrafoA));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL;
   }
   return G;
}

NoA* createNode(int id)
{
   NoA* n = (NoA*)malloc(sizeof(NoA));
   n->id = id;
   n->next = NULL;
   return n;
}

NoAWheight* createNodeWheight(int id, int w)
{
   NoAWheight* n = (NoA*)malloc(sizeof(NoA));
   n->id = id;
   n->next = NULL;
   n->wheight = w;
   return n;
}

void addToList(GrafoA* pGraph, int position, NoA* nodeToAdd)
{
   if (pGraph->Adj[position] == NULL)
   {
      pGraph->Adj[position] = nodeToAdd;
      return;
   }
   NoA* listToAdd = pGraph->Adj[position];
   while (listToAdd->next != NULL)
   {
      listToAdd = listToAdd->next;
   }
   listToAdd->next = nodeToAdd;
}

void addConnectionA (GrafoA* pGraph, int a, int b)
{
   if (a >= pGraph->V || b >= pGraph->V)
      return;

   NoA* pNodeA = createNode(a);
   NoA* pNodeB = createNode(b);

   addToList(pGraph, a, pNodeB);
   addToList(pGraph, b, pNodeA);

   pGraph->E += 2;
}

void addConnectionAUnilateral (GrafoA* pGraph, int a, int b)
{
   if (a >= pGraph->V || b >= pGraph->V)
      return;

   NoA* pNodeB = createNode(b);

   addToList(pGraph, a, pNodeB);

   pGraph->E ++;
}

void addConnectionAWheight (GrafoA* pGraph, int a, int b, int wheight)
{
   if (a >= pGraph->V || b >= pGraph->V)
      return;

   NoAWheight* pNodeB = createNodeWheight(b, wheight);

   addToList(pGraph, a, pNodeB);

   pGraph->E++;
}

void printGrafoA(GrafoA* pGraph)
{
   for (int i = 0; i < pGraph->V; i++)
   {
      printf("%d:", i);
      for (int j = 0; pGraph->Adj[i] != NULL; pGraph->Adj[i] = pGraph->Adj[i]->next)
         printf(" -> %d", pGraph->Adj[i]->id);
      printf("\n");
   }
}

void printGrafoAWheight(GrafoAWheight* pGraph)
{
      for (int i = 0; i < pGraph->V; i++)
   {
      printf("%d: ->", i);
      for (int j = 0; pGraph->Adj[i] != NULL; pGraph->Adj[i] = pGraph->Adj[i]->next)
         printf(" %d (w:%d)", pGraph->Adj[i]->id, pGraph->Adj[i]->wheight);
      printf("\n");
   }
}

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
   int v;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
   }
   for(int i = 0; i < G->V; i++)
   {
      for (int j = 0; j < G->V; j++)
         G->Mat[i][j] = 0;
   }
   return G;
}

void addConnectionM(GrafoM* pGraph, int a, int b)
{
   if (a >= pGraph->V || b >= pGraph->V)
      return;
   pGraph->Mat[a][b] = 1;
   pGraph->Mat[b][a] = 1;
   pGraph->E += 2;
}

void addConnectionMUnilateral(GrafoM* pGraph, int a, int b)
{
   if (a >= pGraph->V || b >= pGraph->V)
      return;
   pGraph->Mat[a][b] = 1;
   pGraph->E++;
}

void addConnectionMWheight(GrafoM* pGraph, int a, int b, int wheight)
{
   if (a >= pGraph->V || b >= pGraph->V)
      return;
   pGraph->Mat[a][b] = wheight;
   pGraph->E++;
}

void printGrafoM(GrafoM* pGraph)
{
   printf("   ");
   for(int i = 0; i < pGraph->V; i++)
      printf("%d ", i);
   printf("\n");
   for(int i = 0; i < pGraph->V; i++)
   {
      printf("%d  ", i);
      for (int j = 0; j < pGraph->V; j++)
         printf("%d ", pGraph->Mat[i][j]);
      printf("\n");
   }
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj (GrafoA *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat (GrafoM *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Mat[v] != NULL) {
         free(G->Mat[v]);
      }
   }
   free(G->Mat);
   free(G);
}

#define BRANCO 0
#define NIL -1

typedef struct DFS {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matrix de adjacências. */
} DFS;

void Busca_Profundidade (GrafoA *G) {
   int u;
   DFS *V = (DFS *)malloc(G->V * sizeof(DFS)); // <- Estrutura independente!
   for (u = 0; u < G->V; u++) {
      V[u].cor = BRANCO;
      V[u].pai = NIL;
   }
   int tempo = 0;
   for (u = 0; u < G->V; u++) {
      if (V[u].cor == BRANCO) {
         DFS_Visit (G, u, V, &tempo);
      }
   }
}


/* */
int main () {

   int Va = 6; /*Número de vértices*/

   GrafoA* Ga = criar_grafo_adj (Va);

   addConnectionAUnilateral(Ga, 0, 1);
   addConnectionAUnilateral(Ga, 0, 2);
   addConnectionAUnilateral(Ga, 0, 5);
   addConnectionAUnilateral(Ga, 1, 2);
   addConnectionAUnilateral(Ga, 1, 3);
   addConnectionAUnilateral(Ga, 2, 3);
   addConnectionAUnilateral(Ga, 4, 3);
   addConnectionAUnilateral(Ga, 4, 2);
   addConnectionAUnilateral(Ga, 4, 5);
    
   // printGrafoA(Ga);

   int Vm = 10; /*Número de vértices*/

   GrafoM* Gm = criar_grafo_mat (Vm);

   addConnectionMUnilateral(Gm, 0, 1);
   addConnectionMUnilateral(Gm, 0, 2);
   addConnectionMUnilateral(Gm, 0, 5);
   addConnectionMUnilateral(Gm, 1, 2);
   addConnectionMUnilateral(Gm, 1, 3);
   addConnectionMUnilateral(Gm, 2, 3);
   addConnectionMUnilateral(Gm, 4, 3);
   addConnectionMUnilateral(Gm, 4, 2);
   addConnectionMUnilateral(Gm, 4, 5);

   printGrafoM(Gm);

   liberar_grafo_adj (Ga);
   liberar_grafo_mat (Gm);

   return 0;
}
