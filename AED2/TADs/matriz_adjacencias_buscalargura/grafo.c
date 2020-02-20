#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"

struct grafo
{
    int qtd_vertices,qtd_arestas;
    int* grau;
    int** aresta;
};

Grafo* cria_grafo(int vertices)
{
    if (vertices < 0) return NULL;

    Grafo* g = (Grafo*)malloc(sizeof(Grafo));

    if (g == NULL) return NULL; // GRAFO NAO FOI ALOCADO

    g->qtd_arestas = 0;
    g->qtd_vertices = vertices;

    g->grau = (int*)calloc(vertices,sizeof(int)); // INICIALIZA O VETOR DE GRAU COM 0!

    if (g->grau == NULL)  // VETOR DE GRAU NAO FOI ALOCADO
    {
        free(g);
        return NULL;
    }

    g-> aresta = (int**)calloc(vertices,sizeof(int*));

    if (g->aresta == NULL)
    {
        free(g->grau);
        free(g);
        return NULL;
    }

    int i;// O "i" SERA USADO PARA PREENCHER A `COLUNA` DA MATRIZ DE ARESTAS
    int j; // CASO A ALOCACAO DA COLUNA DA MATRIZ DE ERRADO, O "j" SERA USADO PARA DESALOCAR TUDO

    for (i=0; i<vertices; i++)
    {
        g->aresta[i] = (int*)calloc(vertices,sizeof(int)); // ALOCA G->ARESTA[i]

        if (g->aresta[i] == NULL) // SE NAO DER CERTO, DESALOCA TUDO QUE FOI ALOCADO ATE AGORA!
        {
            for (j=0; j<i; j++) // PERCORRE ATE ONDE A G->ARESTA[i] FOI ALOCADA
            {
                free(g->aresta[j]);
            }

            free(g->aresta);
            free(g->grau);
            free(g);
            return NULL;
        }

    }

    return g;
}

int insere_aresta (Grafo* g,int v1, int v2, int peso){
    if (g == NULL) return -1; // GRAFO NAO EXISTE!
    if (v1 < 0 || v2 < 0) return -1; // VERTICE INVALIDO!
    if (g->aresta[v1][v2] != 0) return 0; // ARESTA JA EXISTE!

    g->aresta[v1][v2] = peso; // COLOCA O PESO NA POSICAO g[V1][V2]
    g->qtd_arestas++; // AUMENTA A QUANTIDADE DE ARESTAS
    g->grau[v1]++; // AUMENTA O INDICE DE GRAU DE V1
    g->grau[v2]++; // AUMENTA O INDICE DE GRAU DE V2


    return 1; // DEU TUDO CERTO!
}

int verifica_aresta (Grafo* g, int v1,int v2){
    if (g == NULL) return -1; // GRAFO NAO EXISTE!
    if (v1 < 0 || v2 < 0) return -1; // VERTICES INVALIDOS!

    if (g->aresta[v1][v2] != 0) return 1; // ARESTA EXISTE
    else return 0; // ARESTA NAO EXISTE
}

int remove_aresta (Grafo* g,int v1,int v2){
    if (g == NULL) return -1; // GRAFO NAO EXISTE!
    if (v1<0 || v2<0) return -1; // VERTICES INVALIDOS!
    if (g->aresta[v1][v2] == 0) return 0; // ARESTA NAO EXISTE!

    g->aresta[v1][v2] = 0; // PARA REMOVER, BASTA INSERIR 0 NA POSICAO DESEJADA!
    g->grau[v1]--; // RETIRA UM GRAU DO V1
    g->grau[v2]--; // RETIRA UM GRAU DO V2
    g->qtd_arestas--; // DIMINUI QUANTIDADE DE ARESTAS

    return 1; // DEU TUDO CERTO!

}

int consulta_aresta (Grafo* g,int v1,int v2,int* p){
    if (g == NULL) return -1; // GRAFO NAO EXISTE!
    if (v1 < 0 || v2 < 0) return -1; // VERTICES INVALIDOS!
    if (g->aresta[v1][v2] == 0) return 0; // ARESTA NAO EXISTE!

    *p = g->aresta[v1][v2];

    return 1; // DEU CERTO!
}

void mostra_adjacentes (Grafo* g, int v1){
    if (g == NULL) return; // GRAFO NAO EXISTE
    if (v1 < 0) return; // VERTICE INVALIDO

    int i;

    for (i=0;i< g->qtd_vertices;i++)
    {
        if ((g->aresta[v1][i]) != 0)
        {
            printf("%d -> %d \n",v1,i);
        }
    }
}

void mostra_grafo (Grafo* g){
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

    int i,j;

    for (j=0;j< g->qtd_vertices;j++)
    {
        // FUNCAO MOSTRA_ADJACENTES
        for (i=0;i< g->qtd_vertices;i++)
    {
        if ((g->aresta[j][i]) != 0)
        {
            printf("%d -> %d \n",j,i);
        }
    }
        // FIM FUNCAO MOSTRA_ADJACENTES
    }
}

void libera_grafo (Grafo** g){
    if (g == NULL) return; // GRAFO NAO EXISTE!

    int i;
    int limite = (*g)->qtd_vertices;

    for (i = 0;i< limite;i++)
    {
        free((*g)->aresta[i]);

    }

    free ((*g)->aresta);
    free ((*g)->grau);
    free(*g);

    (*g) = NULL;
}

int verifica_adjacencia (Grafo* g, int v1, int v2){
    if (g== NULL) return -1; // GRAFO NAO EXISTE
    if (v1 < 0 || v2< 0) return -1; // VERTICES INVALIDOS

    if (g->aresta[v1][v2] != 0) return 1;
    else return 0;
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

