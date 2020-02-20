#include <stdio.h>
#include <stdlib.h>
#include "pilhadinamica.h"

pilha* cria_pilha()
{
    pilha* p= (pilha*)malloc(sizeof(pilha));

    if (p != NULL)
    {
        p->tamanho = 0;
        p->inicio = NULL;
    }
    return p;
}

void libera_pilha(pilha* p)
{
    if (p!= NULL)
    {

        no* aux;

        while (p->inicio != NULL)
        {
            aux = p->inicio;
            p->inicio = p->inicio->prox;
            free(aux);
        }
    }

}

int tamanho_pilha(pilha* p)
{
    if (p== NULL) return -1;

    else return (p->tamanho);
}

int cheia_pilha(pilha* p)
{
    // FUNCAO MERAMENTE ESTRUTURAL (SO ESTA AQUI POR ESTAR, UMA VEZ QUE EH PILHA DINAMICA)
    return 0;
}

int vazia_pilha(pilha* p){
    if (p == NULL) return 0;
    if (p->inicio == NULL ) return 1;

    return 0;
}

int insere_pilha(pilha* p, int i){
    if (p== NULL) return -1;

    no* aux= (no*)malloc(sizeof(no));

    if (aux==NULL) return -1;

    aux->dados = i;

    // TROCA EH AQUI
    aux->prox= p->inicio;
    p->inicio= aux;

    return 1;

}

int remove_pilha(pilha* p)
{
    if (p== NULL) return -1;

    no* removedor = p->inicio;

    p->inicio = p->inicio->prox;
    free(removedor);

    return 1;

}

int remove_v2 (pilha* p){
    if (p== NULL) return -1;

    no* removedor = p->inicio;
    int removido = p->inicio->dados;
    p->inicio = p->inicio->prox;
    free(removedor);

    return removido;
}

/*int remove_especifico_pilha(pilha* p, int pos)
{
    pilha* secundaria = cria_pilha();
    no* removedor = p->inicio;
    no* tira;
    int i=0;

    while (removedor != NULL || i < pos)
    {
        insere_pilha(secundaria, removedor->dados);
        tira = removedor;
        removedor = removedor->prox;
        free(tira);
        i++;
    }
    no* recoloca = secundaria->inicio;

    while (recoloca != NULL)
    {
        insere_pilha(p, recoloca->dados);
    }

    libera_pilha(secundaria);

    return 1;

}*/

void exibe_pilha(pilha* p)
{
    no* percorre = p->inicio;

    while (percorre != NULL)
    {
        printf("%d\n", percorre->dados);
        percorre = percorre->prox;

    }
}
