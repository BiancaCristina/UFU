#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.h"

typedef struct no no; // POSSO FAZER ISSO?

struct no
{
    int info;
    struct no *sae;
    struct no* sad;
};

Arvore cria_vazia ()
{
    return NULL;
}

Arvore cria_arvore(int info, Arvore sad, Arvore sae)
{
    no* aux = (no*)malloc(sizeof(no));

    if (aux == NULL)
    {
        return NULL; // FALHA NA ALOCACAO DO NO
    }

    aux->info = info;
    aux->sae = sae;
    aux->sad = sad;

    return aux;
}

int arvore_vazia (Arvore arv)
{
    if (arv == NULL) return 1; // ESTA VAZIA
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

int busca_arvore (Arvore arv, int info)
{
    if (arv == NULL) return 0; // ARVORE ESTA VAZIA

    if (arv->info == info) return 1; // ELEMENTO EH O PROPRIO NO RAIZ

    if (busca_arvore(arv->sae, info)) return 1;  /// PROCURA ELEMENTO NA ARVORE DA ESQUERDA
    if (busca_arvore(arv->sad, info)) return 1;  /// FIM DA PROCURA NA ARVORE DA DIREITA

    return 0;
}

int remove_folha (Arvore* arv, int info){
    if (arv == NULL) return 0; // ARVORE VAZIA

    /// TRATA O NO RAIZ (ISSO AQUI QUEBRA A ARVORE EM DUAS?)
    if ((((*arv)->info)) == info) // NO RAIZ EH O PROPRIO ELEMENTO A SER REMOVIDO // TIREI O & DAQUI!
    {
        if ((*arv)->sae == NULL && (*arv)->sad == NULL) // CASO A ARVORE SO TENHA A RAIZ
        {
            free(*arv); // LIBERA O NO RAIZ
            *arv = NULL; // COLOCA CONTEUDO DA ARVORE PRA NULL
            return 1;
        }

        else // CASO A ARVORE TENHA FILHOS
        {
            return 0;
        }
    }

    else
    {
        if (remove_folha(&((*arv)->sae),info)) return 1;
        if (remove_folha(&((*arv)->sad),info)) return 1;
    }

    return 0;
}

void exibe_arvore (Arvore arv){
    if (arv == NULL)
    {
        printf("<> ");
        return;
    }

    printf("< ");
    printf("%d ", arv->info);
    exibe_arvore(arv->sae);
    exibe_arvore(arv->sad);
    printf(">");
}

int altura_arvore (Arvore arv){
   if (arv == NULL) return -1; // ARVORE VAZIA

   int h_sae,h_sad;
   h_sae = altura_arvore(arv->sae);
   h_sad = altura_arvore(arv->sad);

   if (h_sae > h_sad) return h_sae + 1;
   else return h_sad + 1;


}

int busca_pai (Arvore arv, int info){
    if (arv == NULL) return -1; // ARVORE VAZIA
    if (arv->sad == NULL && arv->sae == NULL) return -1; // NO RAIZ NAO TEM PAI
    if (busca_arvore(arv,info) == 0) return -1; // ELEMENTO NAO ESTA NA ARVORE

    int no_pai;

    if ((arv->sad)->info == info || (arv->sae)->info == info) return arv->info;

    no_pai = busca_pai(arv->sae,info);

    if (no_pai != -1) return no_pai;

    else
    {
        no_pai = busca_pai(arv->sad,info);
        return no_pai;
    }
}
