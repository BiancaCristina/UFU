#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"

struct no
{
    int peso;
    int vertice;
    struct no* prox;
};

typedef struct no no;

struct grafo
{
    int qtd_vertices, qtd_arestas;
    int* grau;
    no** aresta; // VETOR DE ENDERECO DO PRIMEIRO NO
};

Grafo* cria_grafo (int vertices)
{
    if (vertices < 0) return NULL; // VERTICE INVALIDO!

    Grafo* g = (Grafo*)malloc(sizeof(Grafo));

    if (g == NULL) return NULL; // SE GRAFO NAO EXISTIR
    g->qtd_vertices = vertices;
    g->qtd_arestas = 0;

    g->grau = (int*)calloc(vertices,sizeof(int)); // ALOCA VETOR DE GRAU

    if (g->grau == NULL) // SE G->GRAU NAO EXISTIR
    {
        free(g);
        return NULL;
    }

    g->aresta = (no**)calloc(vertices,sizeof(no*)); // ALOCA VETOR PARA ARESTA

    if (g->aresta == NULL)
    {
        free(g->grau);
        free(g);
        return NULL;
    }

    int i;
    int j; // SE A ALOCACAO DER ERRADO, `J` SERA USADO PARA DESALOCAR O QUE TIVER SIDO ALOCADO ATE O MOMENTO

    for (i = 0; i< vertices; i++)
    {
        g->aresta[i] = (no*)malloc(vertices*sizeof(no));

        if (g->aresta[i] == NULL) // SE ALOCACAO DA COLUNA DA LISTA NAO DEU CERTO
        {
            for (j=0; j<i; j++)
            {
                free(g->aresta[j]);
            }

            free(g->aresta);
            free(g);
            return NULL;
        }
    }

    for (i=0; i<vertices; i++) // PREENCHE OS ELEMENTOS DE G->ARESTA[i] COM NULL!
    {
        g->aresta[i] = NULL;
    }

    return g;
}

int insere_aresta (Grafo* g,int v1,int v2, int peso)
{
    if (g == NULL) return -1; // GRAFO NAO EXISTE
    if (v1 < 0 || v2 < 0) return -1; // VERTICES INVALIDOS

    // VERIFICANDO SE ARESTA JA EXISTE:
    no* aux = (no*)malloc(sizeof(no));
    if (aux == NULL) return -1; // NAO DEU PRA ALOCAR O NO AUXILIAR
    aux = g->aresta[v1];

    while (aux != NULL && aux->vertice != v2)
    {
        aux = aux->prox;
    }

    if (aux != NULL) return 0; // ARESTA JA EXISTE
    // FIM DA VERIFICACAO SE ARESTA JA EXISTE

    no* insere = (no*)malloc(sizeof(no));

    if (insere == NULL) return -1; // NAO DEU PRA ALOCAR O NO INSERE

    insere->vertice = v2;
    insere->peso = peso;
    insere->prox = g->aresta[v1];
    g->aresta[v1] = insere;

    g->qtd_arestas++;
    g->grau[v1]++;
    g->grau[v2]++;

    return 1;
}

int verifica_aresta (Grafo* g, int v1,int v2)
{
    if (g == NULL) return -1; // GRAFO NAO EXISTE!
    if (v1 < 0 || v2 < 0) return -1; // VERTICES INVALIDOS!

    no* aux = (no*)malloc(sizeof(no));

    if (aux == NULL) return -1; // NAO DEU PRA ALOCAR O NO AUX
    aux = g->aresta[v1];

    while (aux != NULL && aux->vertice != v2)
    {
        aux = aux->prox;
    }

    if (aux != NULL) return 1; // ARESTA EXISTE!
    else return 0; // ARESTA NAO EXISTE!
}

int remove_aresta (Grafo* g,int v1,int v2)
{
    if (g == NULL) return -1; // GRAFO NAO EXISTE
    if (v1 <0 || v2 < 0 ) return -1; // VERTICES INVALIDOS!

    no* aux = (no*)malloc(sizeof(no));
    //no* ant = (no*)malloc(sizeof(no));
    no* ant = NULL;

    if (aux == NULL) return -1; // NAO DEU PRA ALOCAR O AUX!

    aux = g->aresta[v1];

    while (aux != NULL && aux->vertice != v2)
    {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) return 0; // ARESTA NAO EXISTE

    if (ant == NULL) // VERIFICA SE EH O NO APONTADO PELA LISTA (PRIMEIRO NO)
    {
        g->aresta[v1] = aux->prox; // ISSO FAZ COM QUE O PRIMEIRO NO DA LISTA AGORA APONTE PARA NULL!
    }

    else
    {
        ant = aux->prox;  // FAZ O ELEMENTO ANTERIOR APONTAR PARA NULL!
    }

    free(aux); // REMOVE O AUX!

    g->qtd_arestas--;
    g->grau[v1]--;
    g->grau[v2]--;

    return 1;
}

int consulta_aresta (Grafo* g, int v1,int v2,int* p)
{
    if (g == NULL) return -1; // GRAFO NAO EXISTE
    if (v1 < 0 || v2 < 0) return -1; // VERTICES INVALIDOS

    no* aux = (no*)malloc(sizeof(no));

    if (aux == NULL) return -1; // NAO DEU PRA ALOCAR O NO AUX
    aux = g->aresta[v1];

    while (aux != NULL && aux->vertice != v2)
    {
        aux = aux->prox;
    }

    if (aux == NULL) return 0; // ARESTA NAO EXISTE

    *p = aux->peso; // ATRIBUI O PESO NA VARIAVEL DE RETORNO

    return 1; // DEU CERTO
}

void mostra_adjacentes (Grafo* g, int v1)
{
    if (g== NULL) return; // GRAFO NAO EXISTE
    if (v1 < 0) return; // VERTICE INVALIDO

    no* aux = (no*)malloc(sizeof(no));
    if (aux == NULL) return; // NAO DEU PRA ALOCAR O NO AUX

    aux = g->aresta[v1];

    if (aux == NULL) // SE ELE FOR NULL, SIGNIFICA QUE O NO TA APONTANDO PRO NULL, OU SEJA, NAO TEM OUTROS VERTICES COMO ADJANCENTES!
    {
        printf("O VERTICE %d NAO POSSUI VERTICES ADJACENTES", v1);
    }
    while (aux != NULL)
    {
        printf("%d -> %d\n",v1,aux->vertice);
        aux = aux->prox;
    }
}

void mostra_grafo (Grafo* g)
{
    if (g == NULL)
    {
        printf("GRAFO NAO EXISTE!");
        return;
    }

    else if (g->qtd_arestas == 0)
    {
        printf("GRAFO VAZIO!");
        return;
    }

    int i=0;

    for (i=0; i< g-> qtd_vertices; i++)
    {
        // FUNCAO MOSTRA_ADJACENTES
        no* aux = (no*)malloc(sizeof(no));
        if (aux == NULL) return; // NAO DEU PRA ALOCAR O NO AUX

        aux = g->aresta[i];

        if (aux == NULL) // SE ELE FOR NULL, SIGNIFICA QUE O NO TA APONTANDO PRO NULL, OU SEJA, NAO TEM OUTROS VERTICES COMO ADJANCENTES!
        {
            printf("O VERTICE %d NAO POSSUI VERTICES ADJACENTES\n", i);
        }
        while (aux != NULL)
        {
            printf("%d -> %d\n",i,aux->vertice);
            aux = aux->prox;
        }

        // FIM DA FUNCAO MOSTRA_ADJACENTES
    }

}

void libera_grafo (Grafo** g)
{
    if (g == NULL) return; // GRAFO NAO EXISTE

    int i;

    for (i=0; i< (*g)->qtd_vertices; i++)
    {
        no* aux = (*g)->aresta[i];

        while (aux != NULL)
        {
            no* aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
    }

    free((*g)->aresta);
    free((*g)->grau);
    free(g);

    *g = NULL;

}

int verifica_adjacencia(Grafo* g, int v1, int v2){
    if (g==NULL || v1 < 0 || v2 <0) return -1; // GRAFO NAO EXISTE OU VERTICES INVALIDOS

    no* aux = (no*)malloc(sizeof(no));
    aux = g->aresta[v1];

    while (aux != NULL && aux->vertice != v2)
    {
        aux = aux->prox;
    }

    if (aux == NULL) return 0;
    else return 1;
}

int busca_largura (Grafo* g, int v1)
{
    if (g==NULL) return -1; // GRAFO NAO EXISTE
    if (v1 < 0) return -1; // DADOS INVALIDOS

    int qtd_vertices = g->qtd_vertices;

    int* visitado = (int*)calloc(qtd_vertices,sizeof(int));
    if (visitado == NULL) return -1; // PROBLEMA AO ALOCAR VETOR DE VISITADO

    fila* fi = cria_fila();
    if (fi == NULL)
    {
        free(visitado);
        return -1; // PROBLEMA AO ALOCAR FILA
    }

    /// TRATA O VERTICE ATUAL
    visitado[v1] = 1;
    insere_fila(fi,v1);
    /// FIM DO TRATAMENTO DO VERTICE ATUAL

    int atual;

    /// PERCORRE GRAFO
    int i = 0;
    int j = 0;

    while (!(fila_vazia(fi)))
    {
        atual = remove_fila_v2(fi);

        for (i=0; i<qtd_vertices; i++)
        {

            if (visitado[i]==0 && verifica_adjacencia(g,atual,i))
            {
                {
                    insere_fila(fi,i);
                    visitado[i] = 1;
                    // EXECUTA O QUE EU QUERO COM O VERTICE!
                    ///printf("%d -> %d \n",atual,i);
                    printf("VETOR DE VISITADO DO VERTICE %d \n", atual);
                        for (j=0;j<qtd_vertices;j++)
                        {
                            printf("VISITADO[%d] = %d \n",j,visitado[j]);
                        }

                    printf("\nFILA DO VERTICE %d \n",atual);
                        exibe_fila(fi);

                    printf("\nLISTA DE ADJACENTE DO VERTICE %d\n", atual);
                        mostra_adjacentes(g,atual);

                    printf("\n\n\n");

                    // FIM DA EXECUCAO
                }
            }
        }
    }

    return 1;
}

int busca_largura_todos (Grafo* g){
    if (g== NULL) return -1; // GRAFO NAO EXISTE

    int qtd_vertices = g->qtd_vertices;
    int i;

    for (i=0;i<qtd_vertices;i++)
    {
        printf("------------- BUSCA EM LARGURA DO VERTICE %d -------------\n\n", i);
        busca_largura(g,i);
    }

    return 1;
}

