typedef struct grafo Grafo;

// GRAFO NAO DIRECIONADO E NAO PONDERADO:
Grafo* cria_grafo (int vertices);
int insere_aresta (Grafo* g,int v1, int v2);
int verifica_aresta (Grafo* g, int v1,int v2);
int remove_aresta (Grafo* g,int v1,int v2);
void mostra_adjacentes (Grafo* g, int v1); // MUDA AQUI!
void mostra_grafo (Grafo* g);
void libera_grafo (Grafo** g);

int calcula_peso (Grafo* g,int v1,int v2);
void dijkstra(Grafo* g, int v1, int v2);


