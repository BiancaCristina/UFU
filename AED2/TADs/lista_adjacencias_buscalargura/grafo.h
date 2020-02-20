typedef struct grafo Grafo;

Grafo* cria_grafo (int vertices);
int insere_aresta (Grafo* g,int v1,int v2, int peso);
int verifica_aresta (Grafo* g, int v1,int v2);
int remove_aresta (Grafo* g,int v1,int v2);
int consulta_aresta (Grafo* g, int v1,int v2,int* p);
void mostra_adjacentes (Grafo* g, int v1);
void mostra_grafo (Grafo* g);
void libera_grafo (Grafo** g);

int verifica_adjacencia (Grafo* g, int v1, int v2);
int busca_largura (Grafo* g, int v1);
int busca_largura_todos (Grafo* g);
