#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define MAX 100

struct pilha{
    int tamanho; // ESSE TAMANHO PODE TAMBEM SER CONSIDERADO `TOPO`
    int dados[MAX];
};

pilha* cria_pilha (){
    pilha* p;
    p = (pilha*)malloc(sizeof(pilha));

    if (p != NULL)
        p->tamanho = 0;

    return p;

}

void libera_pilha(pilha* p)
{
    free(p);
}

int tamanho_pilha(pilha* p)
{
    if (p == NULL) return -1;

    else return (p->tamanho);
}

int cheia_pilha(pilha* p)
{
    if (p== NULL) return -1;

    else return (p->tamanho == MAX);
}

int vazia_pilha(pilha* p)
{
    if (p==NULL) return -1;
    else return (p->tamanho == 0);
}

int insere_pilha(pilha* p, int i)
{
    if (p == NULL) return -1;
    if (cheia_pilha(p)) return 0;

    p->dados[p->tamanho] = i;
    p->tamanho++;

    return 1;
}

int remove_pilha(pilha* p)
{
    if (p == NULL) return -1;
    if (vazia_pilha(p)) return 0;

    p->tamanho--;

    return 1;
}

void exibir_pilha(pilha* p)
{
    int i;

    for(i=0;i< p->tamanho;i++)
    {
        printf("%d\n", p->dados[i]);
    }

}

int remove_especifico (pilha* p){
    if (p == NULL) return -1;
    if (vazia_pilha(p)) return 0;

    int removido = p->dados[(p->tamanho) - 1];

    p->tamanho--;

    return removido;
}

