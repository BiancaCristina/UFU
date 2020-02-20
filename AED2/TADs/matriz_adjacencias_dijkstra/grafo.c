#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define INFINITO 290094

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

int calcula_peso (Grafo* g,int v1,int v2){
    if (g==NULL || v1 < 0 || v2 < 0) return -1; // GRAFO NAO EXISTE OU VERTICES INVALIDOS

    if (g->aresta[v1][v2] != 0) return g->aresta[v1][v2]; // RETORNA O PESO
    else return -1; // PESO INVALIDO PRA CASO NAO HAJA ESSA ARESTA

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


