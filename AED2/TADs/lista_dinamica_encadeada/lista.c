#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no {
    int info;
    struct no* prox;
} no;

Lista* cria_Lista(){
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if (li == NULL) return NULL; // PROBLEMA AO ALOCAR LISTA

    li->tamanho = 0;
    li->inicio = NULL;

    return li;
}

int vazia_Lista(Lista* li){
    if (li == NULL) return 0; // LISTA NAO EXISTE

    if (li->tamanho == 0) return 1;
    else return 0;
}

int tamanho_Lista(Lista* li){
    if (li == NULL) return -1; // LISTA NAO EXISTE

    return li->tamanho;
}

void exibe_Lista(Lista* li){
    if (li != NULL)
    {
        no* aux = li->inicio;

        while (aux != NULL)
        {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }
}

int insere_inicio_Lista(Lista* li, int info){
    if (li == NULL) return 0; // LISTA NAO EXISTE

    no* aux = (no*)malloc(sizeof(no));
    if (aux == NULL) return 0; // PROBLEMA NA ALOCACAO DO NO

    aux->info = info;
    aux->prox = li->inicio;
    li->inicio = aux;
    li->tamanho++;

    return 1;
}

int insere_final_Lista(Lista* li, int info){
    if (li == NULL) return 0; // LISTA NAO EXISTE

    if (vazia_Lista(li))
    {
        // INSERIR NO FINAL DE UMA LISTA VAZIA == INSERIR NO INICIO
        insere_inicio_Lista(li,info);
        return 1;
    }

    else
    {
        no* aux = li->inicio;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        no* insere = (no*)malloc(sizeof(no));
        if (insere == NULL) return 0; // PROBLEMA AO ALOCAR NO

        insere->info = info;
        insere->prox = NULL;
        aux->prox = insere;
        insere = aux;
        li->tamanho++;

        return 1;
    }
}

int insere_ordenado_Lista(Lista* li, int info){
    if (li == NULL) return 0; // LISTA NAO EXISTE

    if (vazia_Lista(li))
    {
        // INSERIR ORDENADO EM LISTA VAZIA == INSERIR NO INICIO
        insere_inicio_Lista(li,info);
        return 1;
    }

    else if (li->inicio->info > info)
    {
        // SE A INFO DO PRIMEIRO DA LISTA FOR MAIOR QUE O ELEMENTO QUE EU QUERO INSERIR
        // INSERE NO INICIO
        insere_inicio_Lista(li,info);
        return 1;
    }
    else
    {
        no* aux = li->inicio;
        no* ant = NULL;

        while (aux->prox != NULL && aux->info < info)
        {
            ant = aux;
            aux = aux->prox;
        }

        no* insere = (no*)malloc(sizeof(no));
        if (insere == NULL) return 0; // PROBLEMA NA ALOCACAO DO NO

        if (aux->prox == NULL)
        {
            // ELEMENTO DEVE SER INSERIDO NO FINAL DA LISTA
            insere->info = info;
            insere->prox = NULL;
            aux->prox = insere;
            insere = aux;
            li->tamanho++;

            return 1;
        }

        else
        {
            // ELEMENTO DEVE SER INSERIDO DE FORMA ORDENADA
            insere->info = info;
            insere->prox = ant->prox;
            ant->prox = insere;
            li->tamanho++;

            return 1;
        }
    }
}

int remove_Lista(Lista* li, int info){
    if (li == NULL || vazia_Lista(li)) return 0; // LISTA NAO EXISTE OU ESTA VAZIA

    if (li->inicio->info == info)
    {
        // ELEMENTO A SER REMOVIDO EH O PRIMEIRO DA LISTA
        li->inicio = li->inicio->prox;
        li->tamanho--;

        return 1;
    }

    else
    {
        no* aux = li->inicio;
        no* ant = NULL;

        while (aux->prox != NULL && aux->info != info)
        {
            ant = aux;
            aux = aux->prox;
        }

        if (aux->prox == NULL) return 0; // ELEMENTO NAO ENCONTRADO NA LISTA

        else
        {
            ant->prox = aux->prox;
            li->tamanho--;

            return 1;
        }
    }
}

int ordena_crescente_Lista(Lista* li){
    if (li == NULL || vazia_Lista(li) || li->tamanho == 1) return 0; // LISTA NAO EXISTE, ESTA VAZIA OU SO POSSUI UM ELEMENTO

    no* aux = li->inicio;
    int troca;

    while (aux->prox != NULL) // COLOCA O MENOR ELEMENTO NO INICIO DA LISTA E O MAIOR NO FIM DA LISTA
    {
        if (aux->info > aux->prox->info)
        {
            troca = aux->info;
            aux->info = aux->prox->info;
            aux->prox->info = troca;
        }

        aux = aux->prox;
    }

    aux = li->inicio;

    while (aux->prox != NULL) // ORDENA A LISTA
    {
        if (aux->info > aux->prox->info)
        {
            troca = aux->info;
            aux->info = aux->prox->info;
            aux->prox->info = troca;
        }

        aux = aux->prox;
    }

    return 1;
}

void libera_Lista(Lista** li){
    if (li != NULL)
    {
        no* aux = (*li)->inicio;
        no* removido = NULL;

        while (aux->prox != NULL)
        {
            removido = aux;
            aux = aux->prox;
            free(removido);
        }
    }

    free(li);
    *li = NULL;
}
