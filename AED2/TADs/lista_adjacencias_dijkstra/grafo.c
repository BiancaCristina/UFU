#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define INFINITO 290097

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

int calcula_peso (Grafo* g,int v1, int v2){
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

void dijkstra(Grafo* g, int v1, int v2)
{
    if (g==NULL) return; // GRAFO NAO EXISTE
    if (v1 < 0 || v2 < 0) return; // DADOS INVALIDOS

    int i, inicial, k, distancia_aux,minimo,qtd_vertices;

    qtd_vertices = g->qtd_vertices;

    int* visitado = (int*)calloc(qtd_vertices,sizeof(int)); // VETOR QUE MARCA SE UM VERTICE JA FOI VISITADO
    if (visitado == NULL) return; // PROBLEMA AO ALOCAR VETOR DE VISITADOS

    int* antecessor = (int*)malloc(qtd_vertices*sizeof(int)); // VETOR QUE MARCA QUAL VERTICE ANTERIOR DO VERTICE ATUAL
    if (antecessor == NULL)
    {
        free(visitado);
        return; // PROBLEMA AO ALOCAR VETOR DE ANTECESSORES
    }

    int* distancia = (int*)malloc(qtd_vertices*sizeof(int)); // VETOR USADO PARA VER SE COMPENSA SUBSTITUIR A DISTANCIA ATUAL
    if (distancia == NULL)
    {
        free(antecessor);
        free(visitado);
        return; // PROBLEMA AO ALOCAR VETOR DE DISTANCIA
    }

    int* caminho = (int*)malloc(qtd_vertices*5*sizeof(int)); // VETOR AUXILIAR PRA GUARDAR O CAMINHO
    if (caminho == NULL)
    {
        free(distancia);
        free(antecessor);
        free(visitado);
        return; // PROBLEMA AO ALOCAR VETOR PARA CAMINHOS
    }

    for (i=0; i< qtd_vertices; i++)
    {
        antecessor[i] = -1;
        distancia[i] = INFINITO;
    }

    inicial = v1;
    distancia[inicial] = 0;


    while (inicial != v2 && inicial != -1) // NAO TERMINOU OU CAMINHO NEM EXISTE
    {
        for(i=0; i< qtd_vertices; i++) // PERCORRE VERTICES ADJACENTES DO INICIAL
        {
            if (verifica_aresta(g,inicial,i)==1 && visitado[i] == 0) // ARESTA EXISTE E NAO FOI VISITADA
            {
                distancia_aux = distancia[inicial] + calcula_peso(g,inicial,i);

                if (distancia_aux < distancia[i]) // SE AS AUXS FOREM MENORES QUE A ATUAL, SUBSTITUI
                {
                    distancia[i] = distancia_aux;
                    antecessor[i] = inicial;
                }
            }
        }

        visitado[inicial] = 1; // TODOS OS ADJACENTES DO VERTICE INICIAL JA FORAM ANALISADOS
        minimo = INFINITO; // INFINITO
        inicial = -1; // VALOR INVALIDO!

        for (i=0; i<qtd_vertices; i++) // ENCONTRA O PROXIMO VERTICE DO CAMINHO
        {
            if (visitado[i] == 0 && distancia[i] < minimo) // ESCOLHE O VERTICE QUE POSSUI O MENOR PESO
            {
                minimo = distancia[i]; // NOVO VALOR PRO MINIMO
                inicial = i; // NOVO VALOR DO VERTICE QUE TA PERCORRENDO
            }
        }
    }


    /// ADICIONANDO O CAMINHO NO VETOR AUXILIAR "CAMINHO"
    if (inicial == v2) // AQUI ENCONTROU ALGUM CAMINHO
    {
        caminho[0] = v2;
        k = 1;

        while (inicial != v1)
        {
            caminho[k] = antecessor[inicial];
            inicial = antecessor[inicial];
            k++;
        }
    }

    else
    {
        printf("NAO EXISTE CAMINHO ENTRE %4d e %4d\n", v1,v2);
    }
    /// FIM DA ADICAO DO CAMINHO NO VETOR AUXILIAR

    printf("MELHOR CAMINHO ENTRE %d e %d: ",v1,v2);

    for (i=k; i>0; i--)
    {
        if (i==1)
        {
            printf(" %d ", caminho[i-1]); // IMPRIME SEM A "->"
        }

        else
        {
            printf(" %d ->", caminho[i-1]);
        }
    }

}
