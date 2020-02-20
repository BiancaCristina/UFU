/////////////////////////REDE IPE/////////////////////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
///////// THAYNARA SILVA PINTO     - 11711BCC    /////////
///////// GUSTAVO                  - 11711BCC    /////////
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arquivo.h"
#include "fila.h"
#include "grafo.h"
#define INFINITO 24345345
#define LIMPATELA system("cls || clear")

struct vertice
{
    int vf;
    int grau;
    char cidade[20];
    int x;
    int y;
};

struct aresta
{
    int v1;
    int v2;
    float peso;
};

struct no
{
    float peso;
    int vertice;
    struct no* prox;
};

typedef struct no no;

struct grafo
{
    int qtd_vertices, qtd_arestas;
    vertice* info_v;
    no** aresta; // VETOR DE ENDERECO DO PRIMEIRO NO
};

/// GRAFO
Grafo* cria_grafo (int vertices)
{
    if (vertices < 0) return NULL; // VERTICE INVALIDO!

    Grafo* g = (Grafo*)malloc(sizeof(Grafo));

    if (g == NULL) return NULL; // SE GRAFO NAO EXISTIR
    g->qtd_vertices = vertices;
    g->qtd_arestas = 0;

    g->info_v = (vertice*)calloc(vertices,sizeof(vertice)); // ALOCA VETOR DE GRAU

    if (g->info_v == NULL) // SE G->GRAU NAO EXISTIR
    {
        free(g);
        return NULL;
    }

    g->aresta = (no**)calloc(vertices,sizeof(no*)); // ALOCA VETOR PARA ARESTA

    if (g->aresta == NULL)
    {
        free(g->info_v);
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

int insere_aresta (Grafo* g,int v1,int v2, float peso)
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

    /// INSERE UMA VEZ:
    no* insere = (no*)malloc(sizeof(no));

    if (insere == NULL) return -1; // NAO DEU PRA ALOCAR O NO INSERE

    insere->vertice = v2;
    insere->peso = peso;
    insere->prox = g->aresta[v1];
    g->aresta[v1] = insere;


    /// INSERE SEGUNDA VEZ:
    no* insere2 = (no*)malloc(sizeof(no));
    if (insere2 == NULL) return -1;

    insere2->vertice = v1;
    insere2->peso = peso;
    insere2->prox = g->aresta[v2];
    g->aresta[v2] = insere2;


    /// ATUALIZA INFOS DO GRAFO:
    g->qtd_arestas++;
    g->info_v[v1].grau++;
    g->info_v[v2].grau++;

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

    // REMOVE A OUTRA:
    no* aux1 = (no*)malloc(sizeof(no));
    no* ant1 = NULL;

    if (aux1 == NULL) return -1; // NAO DEU PRA ALOCAR O NO AUX1

    aux1 = g->aresta[v2];

    while (aux1 != NULL && aux1->vertice != v1)
    {
        ant1 = aux1;
        aux1 = aux1->prox;
    }
    if (aux1 == NULL) return 0; // ARESTA NAO EXISTE

    if (ant1 == NULL)
    {
        g->aresta[v2] = aux1->prox;
    }

    else
    {
        ant1 = aux1->prox;
    }

    free(aux1);

    g->qtd_arestas--;
    g->info_v[v1].grau--;
    g->info_v[v2].grau--;

    return 1;
}

int consulta_aresta (Grafo* g, int v1,int v2,float* p)
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
    free((*g)->info_v);
    free(g);

    *g = NULL;

}

/// VERTICE:

vertice* aloca_vertice (int n)
{
    vertice* d = (vertice*)malloc(n*sizeof(vertice));

    if (d == NULL) return NULL; // PROBLEMA AO ALOCAR O VETOR DE `D`

    else return d;
}

void preenche_vertice (vertice* d,int i,char c[20],int v, int xx, int yy, int vertices)
{
    d[i].vf = v;
    d[i].x = xx;
    d[i].y = yy;
    strcpy(d[i].cidade,c);

}

void imprime_vertice (vertice* d, int vertices)
{
    int i;

    for (i=0; i< vertices; i++)
    {
        printf("%d %s %d %d\n", d[i].vf,d[i].cidade,d[i].x,d[i].y);
    }
}

char* pertence (vertice* v, int index, int qtd_vertices)
{
    int j = 0;
    int fixa = 0;

    for (j=0; j<qtd_vertices; j++)
    {
        if (v[j].vf == v[index].vf) break;
        fixa++;
    }

    return v[fixa].cidade;
}

int busca (vertice* v, char* c, int qtd_vertices)
{
    int i = 0;
    int vertice=0;
    int encontrado = 0;

    while (i < qtd_vertices)
    {
        if (strcmp(c,v[i].cidade) == 0)
        {
            vertice = i;
            encontrado = 1;
            break;
        }
        i++;
    }

    if (encontrado == 1)
    {
        return vertice;
    }

    else return -1; // ESSA CIDADE NAO ESTA MAPEADA!
}

/// ARESTA:

aresta* aloca_aresta (int quantidade)
{
    if (quantidade < 0) return NULL;

    aresta* a = (aresta*)malloc(quantidade*sizeof(aresta));
    if (a==NULL) return NULL;

    else return a;
}

void preenche_aresta (aresta* a, int i, int v1,int v2, float peso)
{
    if (v1 < 0 || v2 < 0) return; // VERTICES INVALIDOS

    a[i].v1 = v1;
    a[i].v2 = v2;
    a[i].peso = peso;

}

void imprime_aresta (aresta* a, int quantidade)
{
    if (quantidade < 0) return; // QUANTIDADE INVALIDA

    int i;

    for (i=0; i < quantidade; i++)
    {
        printf("%d -> %d PESO: %.2f\n",a[i].v1,a[i].v2,a[i].peso);
    }
}

/// BANCO DE DADOS
int insere_aresta_banco (Grafo* g, aresta* a, char* url)
{
    int i = 0;

    for (i = 0; i<tamanho_arquivo(url); i++)
    {
        insere_aresta(g,a[i].v1,a[i].v2,a[i].peso);
    }

    return 1; // SE DER CERTO!
}

void mostra_grafo_comnome (Grafo* g, vertice* v, aresta* a)
{
    int qtd_vertices = g->qtd_vertices;

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
        /// FUNCAO MOSTRA_ADJACENTES
        no* aux = (no*)malloc(sizeof(no));
        if (aux == NULL) return; // NAO DEU PRA ALOCAR O NO AUX

        aux = g->aresta[i];

        if (aux == NULL) // SE ELE FOR NULL, SIGNIFICA QUE O NO TA APONTANDO PRO NULL, OU SEJA, NAO TEM OUTROS VERTICES COMO ADJANCENTES!
        {
            printf("O VERTICE %d NAO POSSUI VERTICES ADJACENTES\n", i);
        }

        while (aux != NULL)
        {
            if (aux->peso != 0)
            {
                printf("%s -> %s\n",formata_cidade(pertence(v,i,qtd_vertices)),formata_cidade(pertence(v,aux->vertice,qtd_vertices)));
            }

            aux = aux->prox;
        }

        /// FIM DA FUNCAO MOSTRA_ADJACENTES
    }
}

/// FUNÇÕES EXIGIDAS NO TRABALHO
int num_vertices (Grafo* g)
{
    return g->qtd_vertices;
}

int grau_vertice (Grafo* g, int v)
{
    return g->info_v[v].grau;
}

int verifica_adjacencia (Grafo* g, int v1, int v2)
{
    if (g==NULL) return -1; // GRAFO NAO EXISTE
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

float calcula_peso (Grafo* g,int v1, int v2)
{
    if (g==NULL) return -1; // GRAFO NAO EXISTE
    if (v1 < 0 || v2 < 0) return -1; // VERTICES INVALIDOS

    float peso;

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

float distancia_cidades (vertice* v, int v1, int v2){
    float distancia;
    float aux;
    int x1 = v[v1].x;
    int x2 = v[v2].x;
    int y1 = v[v1].y;
    int y2 = v[v2].y;

    aux = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
    distancia = sqrt(aux);

    return distancia;
}


/// FUNÇÕES QUE PERCORREM O GRAFO

int cobertura_envio_max(Grafo* g, int v1, int maximo, vertice* v)
{
    if (g==NULL) return -1; // GRAFO NAO EXISTE
    if (v1 < 0 || maximo < 0 ) return -1; // VERTICE INVALIDO OU QUANTIDE MAXIMA DE PONTOS INTERMEDIARIOS INVALIDA

    int qtd_vertices = g->qtd_vertices;

    int* visitado = (int*)calloc(qtd_vertices,sizeof(int));
    if (visitado == NULL) return -1; // PROBLEMA AO ALOCAR VETOR DE VISITADO

    fila* fi = cria_fila();
    if (fi == NULL)
    {
        free(visitado);
        return -1; // PROBLEMA AO ALOCAR FILA!
    }

    /// VETOR PARA GUARDAR CADA CAMINHO DA BUSCA EM LARGURA:
    int* caminho = (int*)malloc((maximo + 1)*sizeof(int));
    if (caminho == NULL) // PROBLEMA AO ALOCAR VETOR DE CAMINHOS
    {
        libera_fila(fi);
        free(visitado);
        return -1;
    }

    /// TRATA O VERTICE ATUAL
    visitado[v1] = 1;
    insere_fila(fi,v1);
    /// FIM DO TRATAMENTO DO VERTICE ATUAL

    int atual;
    int peso=0;
    int contador = 0;
    int passei_atual = 0;

    /// PERCORRE GRAFO
    int i = 0;

    printf("AREA DE COBERTURA DE ENVIO COM NO MAXIMO %d PONTOS INTERMEDIARIOS\n", maximo);
    while (!(fila_vazia(fi)))
    {

        if (passei_atual > maximo) break;
        atual = remove_fila_v2(fi);

        for (i=0; i<qtd_vertices; i++)
        {
            peso += calcula_peso(g,atual,i);

            if (visitado[i]==0 && verifica_adjacencia(g,atual,i))
            {
                insere_fila(fi,i);
                visitado[i] = 1;
                ++contador;
                // EXECUTA O QUE EU QUERO COM O VERTICE!
                char* temp2 = pertence(v,i,qtd_vertices);
                formata_cidade(temp2);
                printf("%s\n",temp2);
                // FIM DA EXECUCAO

                if (contador == 1)
                {
                    passei_atual++;
                }
            }

        }

        contador = 0;

    }

    return 1;
}

void dijkstra(Grafo* g, int v1, int v2,float tamanho_arq, int qtd_arestas, vertice* v)
{
    if (g==NULL) return; // GRAFO NAO EXISTE
    if (v1 < 0 || v2 < 0 || tamanho_arq < 0 || qtd_arestas < 0) return; // DADOS INVALIDOS

    int i, inicial, k, distancia_aux,minimo,qtd_vertices;
    float distancia_pontos_aux,minimo_pontos;

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

    int* caminho = (int*)malloc(qtd_arestas*3*sizeof(int)); // VETOR AUXILIAR PRA GUARDAR O CAMINHO
    if (caminho == NULL)
    {
        free(distancia);
        free(antecessor);
        free(visitado);
        return; // PROBLEMA AO ALOCAR VETOR PARA CAMINHOS
    }

    float* distancia_pontos = (float*)malloc(qtd_vertices*sizeof(float));
    if (distancia_pontos == NULL)
    {
        free(caminho);
        free(distancia);
        free(antecessor);
        free(visitado);
        return; // PROBLEMA AO ALOCAR VETOR DE DISTANCIA ENTRE CIDADES
    }

    for (i=0; i< qtd_vertices; i++)
    {
        antecessor[i] = -1;
        distancia[i] = INFINITO;
        distancia_pontos[i] = INFINITO;
    }

    inicial = v1;
    distancia[inicial] = 0;
    distancia_pontos[inicial] = 0;

    while (inicial != v2 && inicial != -1) // NAO TERMINOU OU CAMINHO NEM EXISTE
    {
        for(i=0; i< qtd_vertices; i++) // PERCORRE VERTICES ADJACENTES DO INICIAL
        {
            if (verifica_aresta(g,inicial,i)==1 && visitado[i] == 0) // ARESTA EXISTE E NAO FOI VISITADA
            {
                distancia_aux = (distancia[inicial] + calcula_peso(g,inicial,i));
                distancia_pontos_aux = distancia_pontos[inicial] + distancia_cidades(v,inicial,i);

                if (distancia_aux < distancia[i] && distancia_pontos_aux < distancia_pontos[i]) // SE AS AUXS FOREM MENORES QUE A ATUAL, SUBSTITUI
                {
                    distancia[i] = distancia_aux;
                    distancia_pontos[i] = distancia_pontos_aux;
                    antecessor[i] = inicial;
                }
            }
        }

        visitado[inicial] = 1; // TODOS OS ADJACENTES DO VERTICE INICIAL JA FORAM ANALISADOS
        minimo = INFINITO; // INFINITO
        minimo_pontos = INFINITO; // INFINITO
        inicial = -1; // VALOR INVALIDO!

        for (i=0; i<qtd_vertices; i++) // ENCONTRA O PROXIMO VERTICE DO CAMINHO
        {
            if (visitado[i] == 0 && distancia[i] < minimo && distancia_pontos[i] < minimo_pontos) // ESCOLHE O VERTICE QUE POSSUI O MENOR PESO
            {
                minimo = distancia[i]; // NOVO VALOR PRO MINIMO
                minimo_pontos = distancia_pontos[i];
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

    char* cidade1 = pertence(v,v1,qtd_vertices);
    char* cidade2 = pertence(v,v2,qtd_vertices);
    formata_cidade(cidade1);
    formata_cidade(cidade2);

    printf("MELHOR CAMINHO ENTRE %s e %s: ",cidade1,cidade2);

    for (i=k; i>0; i--)
    {
        if (i==1)
        {
            char* temp = pertence(v,caminho[i-1],qtd_vertices);
            formata_cidade(temp);
            printf(" %s ", temp); // IMPRIME A ULTIMA CIDADE SEM A "->"
        }

        else
        {
            char* temp = pertence(v,caminho[i-1],qtd_vertices);
            formata_cidade(temp);
            printf(" %s ->", temp);
        }
    }

    float tempo[k-1];
    float tempototal = 0;

    for (i=0; i < k; i++)
    {
        if (i != k-1)
        {
            tempo[i] = calcula_peso(g,caminho[i],caminho[i+1]);
            tempototal += tamanho_arq/tempo[i];
        }
    }

    printf("\nTEMPO GASTO PARA TRANSFERIR O ARQUIVO: %.2f segundos", tempototal);

}

int tempo_max (Grafo* g, int v1, float tempo_max, float tamanho_arq, vertice* v)
{
    if (g==NULL) return -1; // GRAFO NAO EXISTE
    if (v1 < 0 || tempo_max < 0 || tamanho_arq < 0) return -1; // DADOS INVALIDOS

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
    float tempoatual = 0;
    float peso=0;

    /// PERCORRE GRAFO
    int i = 0;

    printf("PONTOS QUE RECEBERAO O ARQUIVO SEM EXCEDER O TEMPO LIMITE DE %.2f segundos: \n", tempo_max);

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
                    char* temp2 = pertence(v,i,qtd_vertices);
                    peso += calcula_peso(g,atual,i);
                    tempoatual += tamanho_arq/peso;

                    if (tempoatual > tempo_max) break;
                    formata_cidade(temp2);
                    printf("%s DURACAO= %.2f\n",temp2,tempoatual);
                    // FIM DA EXECUCAO
                }
            }
        }
    }

    return 1;
}
