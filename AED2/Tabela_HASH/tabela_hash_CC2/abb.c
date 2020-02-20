///////////TABELA HASH - ARVORE BINARIA DE BUSCA//////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "abb.h"

struct no {
  Aluno info;
  struct no* sae;
  struct no* sad;
};

typedef struct no no;

Arvore cria_vazia(){
    return NULL;
}

int arvore_vazia(Arvore* arv){
    if ((*arv) == NULL) return 1; // ESTA VAZIA
    else return 0; // NAO ESTA VAZIA
}

void libera_arvore (Arvore* arv)
{
    if (arvore_vazia(arv)) return; // ARVORE ESTA VAZIA

    libera_arvore(&((*arv)->sae)); // LIBERA ARVORE DA ESQUERDA
    libera_arvore(&((*arv)->sad)); // LIBERDA ARVORE DA DIREITA
    free (*arv); // LIBERA O NO RAIZ
    *arv = NULL; // COLOCA O CONTEUDO DE A COMO NULL
}

void exibe_arvore (Arvore arv){
    if (arv == NULL)
    {
        printf("<> ");
        return;
    }

    printf("< ");
    printf("%d", arv->info.matricula);
    exibe_arvore(arv->sae);
    exibe_arvore(arv->sad);
    printf("> ");
}

void exibe_ordenado (Arvore arv){
    if (arv != NULL)
    {
        exibe_ordenado(arv->sae);
        printf("%d ",arv->info.matricula);
        exibe_ordenado(arv->sad);
    }
}

int insere_ordenado(Arvore* arv, Aluno reg){
    if (arv == NULL) return 0;

    if ((*arv) == NULL)
    {
        Arvore aux = (no*)malloc(sizeof(no));
        if (aux == NULL) return 0; // PROBLEMA AO ALOCAR AUX

        aux->info = reg;
        aux->sae = NULL;
        aux->sad = NULL;
        (*arv) = aux;
        return 1;
    }

    if (reg.matricula <= ((*arv)->info.matricula))
    {
        return insere_ordenado ((&((*arv)->sae)),reg);
    }

    else
    {
        return insere_ordenado ((&((*arv)->sad)),reg);
    }
}

int remove_ordenado(Arvore* arv, int chave){
    if (arv == NULL || (*arv) == NULL) return 0;
    int arv_chave = (*arv)->info.matricula;
    if (chave > arv_chave) return remove_ordenado(&(*arv)->sad,chave);
    else if (chave < arv_chave) return remove_ordenado(&(*arv)->sae,chave);
    else
    {
        if ( (*arv)->sae == NULL && (*arv)->sad == NULL)
        {
            free((*arv)->info.nome);
            free((*arv));
            *arv = NULL; return 1;
        }
        else if ( (*arv)->sae != NULL && (*arv)->sad == NULL)
        {
            Arvore aux = *arv;
            *arv = aux->sae;
            free(aux); return 1;
        }
        else if ( (*arv)->sae == NULL && (*arv)->sad != NULL)
        {
            Arvore aux = *arv;
            *arv = aux->sad;
            free(aux); return 1;
        }
        else
        {
            Arvore aux = (*arv)->sae;
            while (aux->sad != NULL)
            {
                aux = aux->sad;
            }
            Aluno temp = (*arv)->info;
            (*arv)->info = aux->info;
            aux->info = temp; return remove_ordenado(&(*arv)->sae,chave);
        }
    }
}

int busca_bin (Arvore arv, int chave){
    if (arvore_vazia(&arv)) return 0; // ARVORE VAZIA

    int chave_arv = arv->info.matricula;

    if (chave_arv == chave) return 1; // ENCONTROU A CHAVE NA RAIZ
    else if (chave > chave_arv) return busca_bin(arv->sad,chave);
    else return busca_bin(arv->sae,chave);
}
