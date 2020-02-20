#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct no {
    int vertice;
    int peso;
    struct no* prox;
};

typedef struct no no;

struct vertice {
    int grau;
    struct no* aresta; // VERTICES HORIZONTAIS
};

typedef struct vertice vertice;

struct grafo {
    int qtd_vertices,qtd_arestas;
    struct vertice* prox; // VERTICES VERTICAIS
};


Grafo* cria_grafo(int vertices){
   if (vertices < 0) return NULL; // QUANTIDADE INVALIDA DE VERTICES

    Grafo* g= (Grafo*)malloc(sizeof(Grafo));

    if (g==NULL) return NULL; // NAO ALOCOU O GRAFO

    g->prox = (vertice*)calloc(vertices,sizeof(vertice));

    if (g->prox == NULL)
    {
        free(g);
        return NULL;
    }

    g->prox->aresta = (no*)calloc(vertices,sizeof(no));

    if (g->prox->aresta == NULL)
    {
        free(g->prox);
        free(g);
        return NULL;
    }

    g->qtd_vertices = vertices;
    g->qtd_arestas = 0;

    return g ;
}

int insere_aresta (Grafo* g,int v1,int v2, int peso){
    if (g == NULL) return -1; // GRAFO NAO EXISTE
    if (v1 < 0 || v2 < 0) return -1; // VERTICES INVALIDOS

    no* aux = (no*)malloc(sizeof(no));
    if (aux == NULL) return -1; // NAO DEU PRA ALOCAR O NO AUX
    aux = (g->prox[v1]).aresta;

    while (aux != NULL && aux->vertice != v2)
    {
        aux = aux->prox;
    }

    if (aux != NULL) return 0; // ARESTA JA EXISTE!
    // FIM DA VERIFICACAO SE A ARESTA EXISTE

    no* insere = (no*)malloc(sizeof(no));
    if (insere == NULL) return -1; // NAO DEU PRA ALOCAR O NO INSERE

    insere->peso = peso;
    insere->vertice = v2;
    insere->prox = (g->prox[v1]).aresta;
    (g->prox[v1]).aresta = insere;

    g->qtd_arestas++;
    g->prox[v1].grau++;
    g->prox[v2].grau++;

    return 1;
}

int verifica_aresta (Grafo* g, int v1,int v2){
    if (g==NULL) return -1; // GRAFO NAO EXISTE
    if (v1 < 0 || v2< 0) return -1; // VERTICES INVALIDOS

    // VERIFICA SE A ARESTA EXISTE
    no* aux = (no*)malloc(sizeof(no));
    if (aux == NULL) return -1; // NAO DEU PRA ALOCAR O NO AUX
    aux = g->prox[v1].aresta;

    while (aux != NULL && aux->vertice != v2)
    {
        aux = aux->prox;
    }

    // FIM DA VERIFICACAO SE A ARESTA EXISTE

    if (aux != NULL) return 1; // ARESTA EXISTE
    else return 0; // ARESTA NAO EXISTE
}

int remove_aresta (Grafo* g,int v1,int v2){
    if (g==NULL) return -1; // GRAFO NAO EXISTE
    if (v1<0 || v2<0) return -1; // VERTICES INVALIDOS

    // VERIFICA SE A ARESTA EXISTE:
    no* aux = (no*)malloc(sizeof(no));
    no* ant = NULL;
    if (aux == NULL) return -1; // NAO DEU PRA ALOCAR O NO AUX

    aux = g->prox[v1].aresta;

    while (aux != NULL && aux->vertice != v2)
    {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) return 0; // ARESTA NAO EXISTE!

    // FIM DA VERIFICACAO SE A ARESTA EXISTE

    no* remove = (no*)malloc(sizeof(no));
    if (remove == NULL) return -1; // NAO DEU PRA ALOCAR O NO REMOVE

    if (ant == NULL) // ANTERIOR ERA O PRIMEIRO
    {
        g->prox[v1].aresta = aux->prox;
    }

    else
    {
        ant = aux->prox;
    }

    free(aux);

    g->prox[v1].grau--;
    g->prox[v2].grau--;
    g->qtd_arestas--;

    return 1;
}

int consulta_aresta (Grafo* g, int v1,int v2,int* p){
    if (g== NULL) return -1; // GRAFO NAO EXISTE
    if (v1<9 || v2<0) return -1; // GRAFO NAO EXISTE

    // VERIFICA SE ARESTA EXISTE
    no* aux = (no*)malloc(sizeof(no));

    if (aux == NULL) return -1; // NAO DEU PRA ALOCAR O NO AUX
    aux = g->prox[v1].aresta;

    while (aux != NULL && aux->vertice != v2)
    {
        aux = aux->prox;
    }

    // FIM DA VERIFICACAO

    if (aux == NULL) return 0; // ARESTA NAO EXISTE

    else
    {
        *p = g->prox[v1].aresta->peso;
    }

    return 1;
}

void mostra_adjacentes (Grafo* g, int v1){
    if (g== NULL) return; // GRAFO NAO EXISTE
    if (v1 < 0 ) return; // VERTICE INVALIDO

    no* aux = (no*)malloc(sizeof(no));

    if (aux == NULL) return; // NAO DEU PRA ALOCAR O NO AUX
    aux = g->prox[v1].aresta;

    if (aux == NULL)
    {
        printf("O VERTICE %d NAO POSSUI ADJACENTES! \n", v1);
    }

    while (aux != NULL)
    {
        printf("%d -> %d\n", v1,aux->vertice);
        aux = aux->prox;
    }
}

void mostra_grafo (Grafo* g){
    if (g==NULL)
    {
        printf("GRAFO NAO EXISTE!");
        return;
    }
    else if (g->qtd_arestas == 0)
    {
        printf("GRAFO VAZIO!");
        return;
    }

    int i = 0;

    for (i=0;i< g->qtd_vertices;i++)
    {
        // FUNCAO MOSTRA ADJACENTES
        no* aux = (no*)malloc(sizeof(no));

        if (aux == NULL) return; // NAO DEU PRA ALOCAR O NO AUX
        aux = g->prox[i].aresta;

        if (aux == NULL)
        {
            printf("O VERTICE %d NAO POSSUI ADJACENTES! \n", i);
        }

        while (aux != NULL)
        {
            printf("%d -> %d\n", i,aux->vertice);
            aux = aux->prox;
        }
        // FIM FUNCAO MOSTRA ADJACENTES
    }
}

void libera_grafo (Grafo** g){
    if (g==NULL) return; // GRAFO NAO EXISTE

    int i;

    for (i=0; i< (*g)->qtd_vertices;i++)
    {
        no* aux = (no*)malloc(sizeof(no));
        if (aux == NULL) return; // NAO DEU PRA ALOCAR O NO AUX!
        aux = (*g)->prox[i].aresta;

        while (aux != NULL)
        {
            no* aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
    }

    free((*g)->prox->aresta);
    free((*g)->prox);
    free(*g);

    *g = NULL;
}
