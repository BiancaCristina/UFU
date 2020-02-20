#include <stdio.h>
#include <stdlib.h>
//67z#include <limits.h>
#include <math.h>
#include "grafo.h"
#include "fila.h"
#include "pilha.h"
#define INFINITO 2452432

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

    no* insere2 = (no*)malloc(sizeof(no));
    if (insere2 == NULL) return -1;

    insere2->vertice = v1;
    insere2->peso = peso;
    insere2->prox = g->aresta[v2];
    g->aresta[v2] = insere2;

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

int verifica_adjacencia (Grafo* g, int v1, int v2)
{
    if (v1 < 0 || v2 < 0) return -1; // VERTICES INVALIDOS

    /// VERIFICANDO SE É ADJACENTE:
    no* aux = (no*)malloc(sizeof(no));
    if (aux == NULL) return -1; // PROBLEMA AO ALOCAR O NO AUX
    aux = g->aresta[v1];

    while (aux != NULL && aux->vertice != v2)
    {
        aux = aux->prox;
    }

    if (aux == NULL) return 0; // NÃO SAO ADJACENTES
    else return 1; // SÃO ADJACENTES
    /// FIM DA VERIFICAÇÃO SE SÃO ADJACENTES
}

int conta_adjacentes (Grafo* g,int v1)
{
    if (g==NULL) return -1; // GRAFO INEXISTENTE
    if (v1 < 0) return -1; // VERTICE INVALIDO

    int contador = 0;

    no* aux = (no*)malloc(sizeof(no));
    if (aux == NULL) return -1; // PROBLEMA AO ALOCAR O NO AUX
    aux = g->aresta[v1];

    if (aux == NULL) contador = 0;

    /// PERCORRE O GRAFO A PARTIR DO VERTICE DADO
    while (aux != NULL)
    {
        aux = aux->prox;
        contador++;
    }
    /// FIM DO PERCORRIMENTO

    return contador;
}


int calcula_peso (Grafo* g,int v1, int v2)
{
    int peso;

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
    peso = aux->peso;
    // ATRIBUI O PESO NA VARIAVEL DE RETORNO

    return peso; // DEU CERTO

}

void busca_em_profundidade (Grafo* g, int v1, int* visitado)
{
    visitado[v1] = 1;
    int qtd_vertices = g->qtd_vertices;
    int i;

    printf("VISITADO: %d \nLISTA DE ADJACENTES AO %d: \n", v1,v1);
    /// LISTA DE ADJACENCENTES DO VERTICE ATUAL
    mostra_adjacentes(g,v1);
    /// FIM DA LISTA DE ADJACENTES

    for (i=0; i< qtd_vertices; i++)
    {
        {
            if (verifica_adjacencia(g,v1,i) && visitado[i] == 0)
            {
                ///printf("%d ", v1);
                printf("PROXIMO VERTICE: %d\n",i);
                printf("\n");
                busca_em_profundidade(g,i,visitado);
            }
        }
    }
}

void dispara_profundidade (Grafo* g, int v1)
{
    int* visitado = (int*)calloc(g->qtd_vertices,sizeof(int));
    busca_em_profundidade(g,v1,visitado);
}

int dispara_profundidade_exploratodos (Grafo* g)
{
    int qtd_vertices = g->qtd_vertices;
    int i;

    int* visitado = (int*)calloc(g->qtd_vertices,sizeof(int));

    for (i=0;i<qtd_vertices;i++)
    {
        printf("\n\n\n----------------BUSCA EM PROFUNDIDADE DO VERTICE %d----------------\n\n\n", i);
        busca_em_profundidade(g,i,visitado);
        dispara_profundidade(g,i);
    }


    return 1;
}

void busca_em_profundidade_iter (Grafo* g, int v1){
    if (g==NULL || v1 > 0) return; // GRAFO NAO EXISTE OU VERTICE INVALIDO

    int qtd_vertices = g->qtd_vertices;
    int* visitado = (int*)calloc(qtd_vertices,sizeof(int));
    if (visitado == NULL) return; // PROBLEMA AO ALOCAR VETOR DE VISITADOS

    pilha* pi = cria_pilha();
    if (pi == NULL) return; // PROBLEMA AO ALOCAR PILHA

    visitado[v1] = 1;
    insere_pilha(pi,v1);

    int atual;
    int i;

    while (!(vazia_pilha(pi)))
    {
        atual = remove_especifico(pi);

        for (i=0; i<qtd_vertices; i++)
        {
            if (visitado[i]==0 && verifica_adjacencia(g,atual,i))
            {

                {
                    insere_pilha(pi,i);
                    visitado[i] = 1;
                    // EXECUTA O QUE EU QUERO COM O VERTICE!
                    printf("%d -> %d \n",atual,i);
                    // FIM DA EXECUCAO
                }
            }
        }
    }


}
