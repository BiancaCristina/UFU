#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "avl.h"
#include <string.h>

struct no
{
    Registro info;
    struct no* sae;
    struct no* sad;
    int fb; // FB DO NÓ
};

typedef struct no no;

/// ÁRVORE AVL
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
    (*pai)-> fb = 0; // SETA FB DO PAI
    temp->fb = 0; // SETA FB DO FILHO A DIREITA
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
    printf("%s ", arv->info.identificador);
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

void libera_arvore (Arvore* arv)
{
    if (!arvore_vazia(arv))
    {
        libera_arvore(&((*arv)->sae)); // LIBERA ARVORE DA ESQUERDA
        libera_arvore(&((*arv)->sad)); // LIBERDA ARVORE DA DIREITA
        free (*arv); // LIBERA O NO RAIZ
    }
    *arv = NULL; // COLOCA O CONTEUDO DE A COMO NULL
}

int insere_avl(Arvore* arv, Registro reg, int* bal)
{
    if (arv == NULL) return 0; // ARVORE NAO EXISTE

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
    }

    else if (reg.trafego <= (*arv)->info.trafego) // INSERIR NO LADO ESQUERDO
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

/// FUNÇÕES DO TRABALHO
Registro* menor_trafego(Arvore arv)
{
    if (arvore_vazia(&arv) || arv == NULL) return NULL; // ÁRVORE VAZIA OU NEM EXISTE

    if (arv->sae == NULL)
    {
        return (&(arv->info));
    }

    // PROCURA MENOR TRÁFEGO APENAS NO LADO ESQUERDO
    else
    {
        Registro* aux = (&(arv->sae->info));
        if (aux > menor_trafego(arv->sae)) return menor_trafego(arv->sae);

        else return aux;
    }
}

int qtde_ocioso(Arvore arv)
{
    if (arv == NULL) return 0; // ARVORE NEM EXISTE

    if (arvore_vazia(&arv)) return 0; // ARVORE VAZIA = 0 PONTOS OCIOSOS

    int metade = (arv->info.capacidade)/2;
    int trafego = arv->info.trafego;

    if (trafego < metade) // SE O TRÁFEGO FOR MENOR QUE A METADE DA CAPACIDADE
    {
        return 1 + qtde_ocioso(arv->sae) + qtde_ocioso(arv->sad); // SOMA 1 E CHAMA RECURSÃO
    }

    else // CASO NÃO SEJA MENOR
    {
        return qtde_ocioso(arv->sae) + qtde_ocioso(arv->sad); // SÓ CHAMA RECURSÃO
    }
}

int eh_folha(Arvore arv)
{
    if (arv == NULL || arvore_vazia(&arv)) return 0;

    if (arv->sae == NULL && arv->sad == NULL) return 1;
    else return 0;
}

int conta_filhos(Arvore arv)
{
    if (arv == NULL || arvore_vazia(&arv)) return -1;

    if (arv->sae == NULL && arv->sad == NULL) return 0; // NÃO POSSUI FILHOS
    else if (arv->sae != NULL && arv->sad == NULL) return 1; // POSSUI APENAS UM FILHO
    else if (arv->sae == NULL && arv->sad != NULL) return 1; // POSSUI APENAS UM FILHO
    else if (arv->sae != NULL && arv->sad != NULL) return 2; // POSSUI DOIS FILHOS

    return -1; // CASO ESTEJA FORA DAS CONDIÇÕES ACIMA
}
int nro_derivacao(Arvore arv)
{
    if (arv == NULL) return 0; // ARVORE NÃO EXISTE
    if (arvore_vazia(&arv)) return 0; // ÁRVORE VAZIA NÃO POSSUI NÚMERO DE DERIVAÇÃO

    if (arv->sae == NULL && arv->sad == NULL) return 0; // PAI NÃO TEM FILHOS
    else return 1 + nro_derivacao(arv->sae) + nro_derivacao(arv->sad); // CHAMA A RECURSÃO
}

int prof_arvore(Arvore arv){
    // FUNÇÃO GATILHO QUE CALCULA A PROFUNDIDADE DO NÓ
    return calc_prof_arv(arv,0);
}

int calc_prof_arv(Arvore arv, int nivel){
    if (arv == NULL) return 0; // ÁRVORE NEM EXISTE

    if (eh_folha(arv)) return nivel; // SE FOR FOLHA, DEVOLVE O NÍVEL ATUAL

    int p_sae = calc_prof_arv(arv->sae,nivel + 1); // CALCULA NÍVEL NA ÁRVORE ESQUERDA
    int p_sad = calc_prof_arv(arv->sad,nivel + 1); // CALCULA NÍVEL NA ÁRVORE DIREITA

    // RETORNA A MAIOR PROFUNDIDADE CALCULADA
    if (p_sae > p_sad) return p_sae;
    else return p_sad;
}

int calc_completa(Arvore arv, int altura){
    if (arv == NULL) return 1;

    if(eh_folha(arv)) // CASO SEJA NÓ FOLHA
    {
        // RETORNA 1 CASO O NÓ ESTEJA NO ÚLTIMO OU PENÚLTIMO NÍVEL DA ÁRVORE
        if (prof_arvore(arv) > altura - 1) return 0;
        else return 1;
    }

    else if (eh_folha(arv->sae) && eh_folha(arv->sad)) // CASO SEJA UM NÓ INTERMEDIÁRIO
    {
        if (conta_filhos(arv) == 2) return 1; // SE TIVER DOIS FILHOS, RETORNA 1
        else return 0; // CASO CONTRÁRIO RETORNA 0
    }

    else // CASO NÃO SEJA NÓ FOLHA OU NÓ INTERMEDIÁRIO
    {
        return calc_completa(arv->sae,altura),calc_completa(arv->sad,altura); // SÓ CHAMA A RECURSÃO
    }

    return 0;
}

int completa(Arvore arv){
    int altura = altura_arvore(arv);

    if (arvore_vazia(&arv)) return 1;
    else if (qtd_no_folha(arv) != qtd_no_inter(arv) + 1) return 0;
    else return calc_completa(arv,altura);
}

int qtd_no_inter(Arvore arv){
    if (arv == NULL || arvore_vazia(&arv)) return 0;

    if (eh_folha(arv)) return 0;

    // CASO NAO SEJA FOLHA
    else
    {
        return 1 + qtd_no_inter(arv->sae) + qtd_no_inter(arv->sad);
    }
}

int qtd_no_folha(Arvore arv){
    if (arv == NULL || arvore_vazia(&arv)) return 0;

    if(arv->sae == NULL && arv->sad == NULL) return 1;
    else return qtd_no_folha(arv->sae) + qtd_no_folha(arv->sad);
}

int balanceada(Arvore arv){
   if (arv == NULL) return 1; // ÁRVORE NULL É UMA ÁRVORE BALANCEADA

    int h_sae = altura_arvore(arv->sae); // CALCULA ALTURA DA ÁRVORE DA ESQUERDA
    int h_sad = altura_arvore(arv->sad); // CALCULA ALTURA DA ÁRVORE DA DIREITA

    if (abs(h_sae - h_sad) <= 1 && balanceada(arv->sae) && balanceada(arv->sad)) return 1; // CALCULA A DIFERENÇA DE ALTURA ENTRE OS NÓS FOLHA
    return 0;
}

int arvore_cheia(Arvore arv)
{
    if (balanceada(arv) && completa(arv)) return 1; // SE UMA ÁRVORE É COMPLETA E BALANCEADA, ENTÃO ELA É CHEIA
    else return 0;
}

int nivel_no(Arvore arv, Registro reg){
    // FUNÇÃO GATILHO QUE CALCULA A PROFUNDIDADE DO NÓ
    return calc_prof_no(arv, reg,0);
}

int calc_prof_no(Arvore arv, Registro reg, int nivel){
    if (arv == NULL) return 0; // ÁRVORE NULA TEM PROFUNDIDADE 0

    int id = arv->info.trafego;

    if (id == reg.trafego) return nivel; // SE A RAIZ ATUAL FOR IGUAL AO REGISTRO PROCURADO

    int prof = calc_prof_no(arv->sae,reg,nivel+1); // PROCURA O REGISTRO NA ÁRVORE DA ESQUERDA
    if (prof != 0) return prof; // SE O NÍVEL NÃO FOR ZERO, RETORNA O NÍVEL

    prof = calc_prof_no(arv->sad,reg,nivel+1); // PROCURA O REGISTRO NA ÁRVORE DA DIREITA
    return prof; // RETORNA O NÍVEL

}

int arvore_iguais(Arvore a, Arvore b)
{
    if (arvore_vazia(&a) && arvore_vazia(&b)) return 1; // SE AS DUAS ÁRVORES SÃO VAZIAS, ENTÃO ELAS SÃO IGUAIS
    if ((!arvore_vazia(&a)) && (!arvore_vazia(&b)) && a->info.trafego == b->info.trafego) // SE NÃO FOREM VAZIAS E SEUS CONTEÚDOS FOREM IGUAIS
    {
        arvore_iguais(a->sae,b->sae); // CHAMA A RECURSÃO NOVAMENTE
        arvore_iguais(a->sad,b->sad); // CHAMA A RECURSÃO NOVAMENTE
        return 1;
    }

    else return 0;
}

Registro* busca_bin_id(Arvore arv, char id[20]){
    if (arvore_vazia(&arv) || arv == NULL) return NULL; // ARVORE VAZIA

    //printf("%s ------ %s", arv->info.identificador, id);
    if (strcmp(arv->info.identificador,id)==0) return (&(arv->info)); // ENCONTROU O IDENTIFICADOR NA RAIZ

    Registro* no = (busca_bin_id(arv->sae, id));
    if ((no) != NULL) return no;

    else busca_bin_id(arv->sad, id);

    return no;
}
