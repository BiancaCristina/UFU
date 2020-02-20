#include <stdio.h>
#include <stdlib.h>
#include "arv_gen.h"

typedef struct no no; // POSSO FAZER ISSO?

struct no
{
    int info;
    struct no* fe; // FILHO A ESQUERDA
    struct no* id; // IRMAOS A DIREITA
};

/// FILA TEMPORARIO


Arvore cria_arvore(int info){
    Arvore aux = (Arvore)malloc(sizeof(no));
    if (aux == NULL) return NULL; // PROBLEMA NA ALOCACAO DO NO AUX

    aux->info = info;
    aux->fe = NULL;
    aux->id = NULL;

    return aux;
}

int insere(Arvore arv, Arvore sa){
    if (arv == NULL) return 0; // NAO HA INSERCAO EM ARVORE QUE NEM EXISTE
    sa->id = arv->fe;
    arv->fe = sa;

    return 1;
}

void exibe_arvore(Arvore arv){
    if (arv == NULL)
    {
        printf("<> ");
        return;
    }

    printf("< ");
    printf("%d", arv->info);
    exibe_arvore(arv->fe);
    printf(">");
    exibe_arvore(arv->id);
}

int busca(Arvore arv, int info){
    if (arv == NULL) return 0;

    if (arv->info == info) return 1;

    if (busca(arv->fe,info)) return 1;

    if (busca(arv->id,info)) return 1;

    return 0;
}


/// FILA -> TEMPORARIO
typedef struct node {
    Arvore dados;
    struct node* prox;
} node;

typedef struct fila {
    int tamanho;
    node* inicio;
    node* fim;
} fila;

fila* cria_fila()
{
    fila* fi = (fila*)malloc(sizeof(fila));

    if (fi != NULL)
    {
        fi->fim = NULL;
        fi->inicio = NULL;
        fi->tamanho= 0;

    }

    return fi;
}

int fila_tamanho(fila* fi)
{
    if (fi == NULL) return 0;

    return fi->tamanho;
}

int fila_cheia(fila* fi)
{
    return 0; // NAO EXISTE FILA CHEIA EM FILA DINAMICA
}

int fila_vazia(fila* fi)
{
    if (fi == NULL) return 0;

    if (fi->inicio == NULL) return 1;

    return 0;
}

int insere_fila(fila* fi, Arvore i)
{
    if (fi== NULL) return 0;

    node* aux= (node*)malloc(sizeof(node));

    if (aux ==NULL) return 0;

    aux->dados= i;
    aux->prox= NULL;
    fi->tamanho++;

    if(fi->fim == NULL) // TESTA SE A LISTA TA VAZIA
    {
        fi->inicio = aux;
        fi->fim= aux;
    }

    else
    {
        fi->fim->prox = aux;
        fi->fim= aux;

    }

    return 1;
}

Arvore remove_fila_v2 (fila* fi){ // MOSTRA QUAL ELEMENTO FOI REMOVIDO
    Arvore removido;
    if (fi != NULL) { // FILA NEM EXISTE

    node* aux = fi->inicio;
    removido = fi->inicio->dados;

    fi->inicio = fi->inicio->prox;
    free(aux);

    if (fi->inicio == NULL){ // FILA FICOU VAZIA
        fi->fim = NULL;

    }

    fi->tamanho--;
    }

    return removido;
}

///

int arvore_vazia(Arvore* arv){
    if ( (*arv) == NULL) return 1;
    else return 0;
}

void libera_arvore(Arvore* arv){
    if (!arvore_vazia(arv))
    {
        libera_arvore(&((*arv)->fe));
        libera_arvore(&((*arv)->id));
        free(*arv);
    }

    *arv = NULL;
}

int altura_arvore(Arvore arv){
    if (arv == NULL) return -1;

    int hmax = -1;
    Arvore aux = arv->fe;

    while (aux != NULL)
    {
        int h = altura_arvore(aux);
        if (h > hmax) hmax = h;
        aux = aux->id;
    }

    return hmax + 1;
}

void imprime_preordem(Arvore arv){
    if (arv == NULL) return;

    printf("%d ", arv->info);
    imprime_preordem(arv->fe);
    imprime_preordem(arv->id);
}

void exibe_fila(fila* fi)
{
    node* percorre = fi->inicio;

    while (percorre != NULL)
    {
        printf("%d\n", percorre->dados->info);
        percorre = percorre->prox;
    }
}

void percorre_nivel(Arvore arv){
    if (arv == NULL) return;

    fila* fi = cria_fila(); // CRIA FILA
    if (fi == NULL) return; // PROBLEMA AO ALOCAR FILA

    insere_fila(fi,arv); // INSERE A ARVORE RAIZ NA FILA
    Arvore atual; // CRIA UMA ARVORE AUX

    while (!fila_vazia(fi)) // ENQUANTO A FILA ESTIVER VAZIA
    {
        atual = remove_fila_v2(fi); // ARVORE AUX RECEBE A ARVORE QUE FOI REMOVIDA

        printf("%d ", atual->info); // PRINTA

        if (arv->fe != NULL) insere_fila(fi,arv->fe); // SE FILHO A ESQUERDA NAO FOR NULL, INSERE ELE NA FILA
        if (arv->id != NULL) insere_fila(fi,arv->id); // IRMAO A DIREITA NAO FOR NULL, INSERE ELE NA FILA
    }
}
