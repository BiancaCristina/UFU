/////////////////////////REDE IPE/////////////////////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
///////// THAYNARA SILVA PINTO     - 11711BCC    /////////
///////// GUSTAVO                  - 11711BCC    /////////
//////////////////////////////////////////////////////////

/// GRAFO
typedef struct grafo Grafo; // DECLARACAO DO TIPO GRAFO
Grafo* cria_grafo (int v); // CRIA GRAFO
int insere_aresta (Grafo* g,int v1,int v2, float peso); // INSERE ARESTA
int verifica_aresta (Grafo* g, int v1,int v2); // VERIFICA EXISTENCIA DA ARESTA
int remove_aresta (Grafo* g,int v1,int v2); // REMOVE ARESTA
int consulta_aresta (Grafo* g, int v1,int v2,float* p); // CONSULTA PESO ASSOCIADO A ARESTA
void mostra_adjacentes (Grafo* g, int v1); // MOSTA ADJACENTES DA ARESTA
void libera_grafo (Grafo** g); // LIBERA GRAFO

/// VERTICE
typedef struct vertice vertice; // DECLARACAO DO TIPO VERTICE
vertice* aloca_vertice (int n); // CRIA VERTICE
void preenche_vertice (vertice* d,int i,char c[20],int v, int xx, int yy, int vertices); // PREENCHE VERTICE
void imprime_vertice (vertice* d, int v); // IMPRIME VERTICE
char* pertence (vertice* v, int index, int qtd_vertices); // ACHA O NOME DA CIDADE A PARTIR DO VERTICE DADO
int busca (vertice* v, char* c, int qtd_vertices); // ACHA O NUMERO DO VERTICE A PARTIR DA CIDADE INFORMADA

/// ARESTA
typedef struct aresta aresta; // DECLARACAO DO TIPO ARESTA
aresta* aloca_aresta (int quantidade); // CRIA ARESTA
void preenche_aresta (aresta* a, int i, int v1,int v2, float peso); // PREENCHE ARESTA
void imprime_aresta (aresta* a, int quantidade); // IMPRIME ARESTA

/// BANCO DE DADOS
int insere_aresta_banco (Grafo* g, aresta* a, char* url); // INSERE AS INFORMACOES DO .TXT NO GRAFO
void mostra_grafo_comnome (Grafo* g, vertice* v, aresta* a); // MOSTRA GRAFO COM NOME DAS CIDADES

/// FUNÇÕES EXIGIDAS NO TRABALHO
int num_vertices (Grafo* g); // RETORNA NUMERO DE VERTICES DO GRAFO
int grau_vertice (Grafo* g, int v); // RETORNA O NUMERO DE ARESTAS ASSOCIADAS A DETERMINADO VERTICE
int verifica_adjacencia (Grafo* g, int v1, int v2); // VERIFICA SE UM VERTICE EH ADJACENTE AO OUTRO
int conta_adjacentes (Grafo* g,int v1); // CONTA QUANTOS VERTICES ADJACENTES UM DADO VERTICE POSSUI
float calcula_peso (Grafo* g,int v1, int v2); // CALCULA PESO DA ARESTA
float distancia_cidades (vertice* v, int v1, int v2); // CALCULA DISTANCIA ENTRE DUAS CIDADES

/// FUNÇÕES QUE PERCORREM O GRAFO
void dijkstra(Grafo* g, int v1, int v2,float tamanho_arq, int qtd_arestas, vertice* v); // CALCULA O MENOR CAMINHO ENTRE DOIS VERTICES DADOS
int tempo_max (Grafo* g, int v1, float tempo_max, float tamanho_arq, vertice* v); // APRESENTA TODOS OS PONTOS QUE RECEBERAO UM DADO ARQUIVO SEM EXCEDER O TEMPO LIMITE
int cobertura_envio_max(Grafo* g, int v1, int maximo, vertice* v); // APRESENTA A AREA DE COBERTURA DE ACORDO COM A QUANTIDADE DE PONTOS INTERMEDIARIOS DADO

