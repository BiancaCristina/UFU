#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct no
{
    Registro info;
    struct no* sae;
    struct no* sad;
    int fb; // FB DO NO!
};

typedef struct no no;

Arvore cria_vazia()
{
    return NULL;
}

int arvore_vazia(Arvore* arv)
{
    if ((*arv) == NULL) return 1; // ESTA VAZIA
    else return 0; // NAO ESTA VAZIA
}

int altura_arvore (Arvore arv)
{
    if (arv == NULL) return -1; // ARVORE VAZIA

    int h_sae,h_sad;
    h_sae = altura_arvore(arv->sae);
    h_sad = altura_arvore(arv->sad);

    if (h_sae > h_sad) return h_sae + 1;
    else return h_sad + 1;
}

int calcula_fb (Arvore arv)
{
    int fb = altura_arvore(arv->sae) - altura_arvore(arv->sad);

    return fb;
}

int rot_dir (Arvore* pai)
{
    if (pai == NULL || (*pai) == NULL || (*pai)->sae == NULL) return 0; // ARVORE NAO EXISTE, ARVORE VAZIA OU FILHO ESQUERDA NULL

    Arvore temp = (*pai)->sae; // NO AUXILIAR
    (*pai)->sae = temp->sad; // PRIMEIRO MOVIMENTO
    temp->sad = (*pai); // SEGUNDO MOVIMENTO
    temp->fb = 0; // SETANDO O VALOR DE FB
    (*pai)->fb = 0; // SETANDO VALOR DE FB
    (*pai) = temp; // FAZ O FILHO A ESQUERDA APONTAR PRA RAIZ

    return 1;
}

int rot_esq (Arvore* pai)
{
    if (pai == NULL || (*pai) == NULL || (*pai)->sad == NULL) return 0; // ARVORE NAO EXISTE, ARVORE VAZIA OU FILHO DIREITA NULL

    Arvore temp = (*pai)->sad;
    (*pai)->sad = temp->sae; // PRIMEIRO MOVIMENTO
    temp->sae = (*pai); // SEGUNDO MOVIMENTO
    temp->fb = 0; // SETA FB DO FILHO A DIREITA
    (*pai)-> fb = 0; // SETA FB DO PAI
    (*pai) = temp; // FILHO A DIREITA VIRA RAIZ

    return 1;
}

int rot_dir_esq(Arvore* pai)
{
    // RETURN 0 P/ CASO ARVORE NAO EXISTE, ARVORE VAZIA, FILHO A ESQUERDA NULL, NETO A DIREITA NULL
    if (pai == NULL || (*pai) == NULL || (*pai)->sae == NULL || (*pai)->sae->sad == NULL) return 0;

    /// ROTACIONA O FILHO_SAE PRA ESQUERDA
    Arvore filho_esq = (*pai)->sae;

    Arvore neto_dir = filho_esq->sad; // DEFININDO AUX
    filho_esq->sad = neto_dir->sae; // PRIMEIRO MOVIMENTO
    neto_dir->sae = filho_esq; // SEGUNDO MOVIMENTO

    /// ROTACIONA RAIZ PRA DIREITA
    (*pai)->sae = neto_dir->sad; // TERCEIRO MOVIMENTO
    neto_dir->sad = (*pai); // QUARTO MOVIMENTO

    /// AJUSTA OS FB
    if (neto_dir->fb == -1)
    {
        (*pai)->fb = 0;
        filho_esq-> fb = 1;
    }

    else if (neto_dir->fb == 1)
    {
        (*pai)->fb = -1;
        filho_esq->fb = 0;
    }

    else // NETO_DR-> FB == 0
    {
        (*pai)->fb = 0;
        filho_esq->fb = 0;
    }

    neto_dir->fb = 0;
    (*pai) = neto_dir; // NETO DA DIREITA VIRA RAIZ
    return 1;
}

int rot_esq_dir(Arvore* pai)
{
    // RETURN 0 P/ CASO ARVORE NAO EXISTE, ARVORE VAZIA, FILHO A DIREITA NULL, NETO A ESQUERDA NULL
    if (pai == NULL || (*pai) == NULL || (*pai)->sad == NULL || (*pai)->sad->sae == NULL) return 0;

    /// ROTACIONA O FILHO DA ESQUERDA PRA DIREITA
    Arvore filho_dir = (*pai)->sad;

    Arvore neto_esq = filho_dir->sae; // DEFINIR AUX
    filho_dir->sae = neto_esq->sad; // PRIMEIRO MOVIMENTO
    neto_esq->sad = filho_dir; // SEGUNDO MOVIMENTO

    /// ROTACIONA RAIZ PRA ESQUERDA
    (*pai)->sad = neto_esq->sae; // TERCEIRO MOVIMENTO
    neto_esq->sae = (*pai); // QUARTO MOVIMENTO

    /// AJUSTA OS FB
    if (neto_esq->fb == -1)
    {
        (*pai)->fb = 1;
        filho_dir->fb = 0;
    }

    else if (neto_esq->fb == 1)
    {
        (*pai)->fb = 0;
        filho_dir->fb = -1;
    }

    else // NETO_ESQ-> FB == 0
    {
        (*pai)->fb = 0;
        filho_dir->fb = 0;
    }

    neto_esq->fb = 0;
    (*pai) = neto_esq; // NETO DA ESQUERDA VIRA RAIZ
    return 1;
}

void exibe_arvore (Arvore arv)
{
    if (arv == NULL)
    {
        printf("<> ");
        return;
    }

    printf("< ");
    printf("%d ", arv->info.chave);
    exibe_arvore(arv->sae);
    exibe_arvore(arv->sad);
    printf(">");
}

int balancear_esq(Arvore* arv)
{
    if ( (*arv)->sae->fb > 0) return rot_dir(arv);
    else return rot_dir_esq(arv);
}

int balancear_dir(Arvore* arv)
{
    if ( (*arv)->sad->fb < 0) return rot_esq(arv);
    else return rot_esq_dir(arv);
}

int insere_avl(Arvore* arv, Registro reg, int* bal)
{
    if (arv == NULL) return 0; // ARVORE NAO EXISTE

    //int chave_arv = ((*arv)->info.chave);
    //int chave_reg = reg.chave;

    if ((*arv) == NULL) // ARVORE VAZIA, REG SERA RAIZ
    {
        Arvore aux = (Arvore)malloc(sizeof(no));
        if (aux == NULL) return 0; // PROBLEMA ALOCACAO DE NO AUX

        aux->info = reg;
        aux->sad = NULL;
        aux->sae = NULL;
        aux->fb = 0;
        (*arv) = aux;
        *bal = 1; // ATIVA VERIFICACAO DE BALANCEAMENTO
        //return 1;
    }

    else if (reg.chave <= (*arv)->info.chave) // INSERIR NO LADO ESQUERDO
    {
        insere_avl(&((*arv)->sae),reg,bal); // CHAMA RECURSIVAMENTE ATE ACHAR UM NO FOLHA

        if ((*bal) == 1) // VERIFICA NECESSIDA DE BALANCEAR
        {

            if ((*arv)->fb == 1)
            {
                balancear_esq(arv);
                *bal = 0; // ARVORE BALANCEADA
            }

            else if ((*arv)->fb == 0)
            {
                (*arv)->fb = 1; // ARVORE QUASE BALANCEADA
            }

            else // CAMPO FB DA RAIZ = -1
            {
                (*arv)->fb = 0;
                *bal = 0; // ARVORE BALANCEADA
            }
        }
    }

    else // CHAVE_REG > CHAVE_ARV, INSERIR NO LADO DIREITO
    {
        insere_avl(&((*arv)->sad),reg,bal);

        if ((*bal) == 1) // VERIFICA NECESSIDA DE BALANCEAR
        {
            if ((*arv)->fb == -1)
            {
                balancear_dir(arv);
                *bal = 0; // ARVORE BALANCEADA
            }

            else if ((*arv)->fb == 0)
            {
                (*arv)->fb = -1; // ARVORE QUASE BALANCEADA
            }

            else // CAMPO FB DA RAIZ = -1
            {
                (*arv)->fb = 0;
                *bal = 0; // ARVORE BALANCEADA
            }
        }
    }

    return 1;
}

void libera_arvore (Arvore* arv)
{
    if (arvore_vazia(arv)) return; // ARVORE ESTA VAZIA

    libera_arvore(&((*arv)->sae)); // LIBERA ARVORE DA ESQUERDA
    libera_arvore(&((*arv)->sad)); // LIBERDA ARVORE DA DIREITA
    free (*arv); // LIBERA O NO RAIZ
    *arv = NULL; // COLOCA O CONTEUDO DE A COMO NULL
}

Arvore busca_bin (Arvore arv, int chave){
    if (arvore_vazia(&arv)) return NULL; // ARVORE VAZIA

    int chave_arv = arv->info.chave;

    if (chave_arv == chave) return arv; // ENCONTROU A CHAVE NA RAIZ
    else if (chave > chave_arv) return busca_bin(arv->sad,chave);
    else return busca_bin(arv->sae,chave);
}

int nivel_no(Arvore arv, Registro reg){
    // FUNÇÃO GATILHO QUE CALCULA A PROFUNDIDADE DO NÓ
    return calc_prof_no(arv, reg,0);
}

int calc_prof_no(Arvore arv, Registro reg, int nivel){
    if (arv == NULL) return 0; // ÁRVORE NULA TEM PROFUNDIDADE 0

    int id = arv->info.chave;

    if (id == reg.chave) return nivel; // SE A RAIZ ATUAL FOR IGUAL AO REGISTRO PROCURADO

    int prof = calc_prof_no(arv->sae,reg,nivel+1); // PROCURA O REGISTRO NA ÁRVORE DA ESQUERDA
    if (prof != 0) return prof; // SE O NÍVEL NÃO FOR ZERO, RETORNA O NÍVEL

    prof = calc_prof_no(arv->sad,reg,nivel+1); // PROCURA O REGISTRO NA ÁRVORE DA DIREITA
    return prof; // RETORNA O NÍVEL

}
