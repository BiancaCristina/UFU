typedef struct grafo Grafo;

Grafo* cria_grafo (int vertices);
int insere_aresta (Grafo* g,int v1, int v2,int peso);
int verifica_aresta (Grafo* g, int v1,int v2);
int remove_aresta (Grafo* g,int v1,int v2);
int consulta_aresta (Grafo* g,int v1,int v2, int* p);
void mostra_adjacentes (Grafo* g, int v1);
void mostra_grafo (Grafo* g);
void libera_grafo (Grafo** g);
int verifica_adjacencia (Grafo* g, int v1, int v2);

void busca_em_profundidade_matriz (Grafo* g, int v1, int* visitado); // QUESTAO 2
void dispara_profundidade_matriz (Grafo* g, int v1); // QUESTAO 2
int dispara_profundidade_exploratodos_matriz (Grafo* g); // QUESTAO 3
void busca_em_profundidade_iter (Grafo* g, int v1); // QUESTAO 4
