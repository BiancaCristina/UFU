#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct no
{
    Registro info;
    struct no* sae;
    struct no* sad;
};

typedef struct no no;

Arvore cria_vazia()
{
    return NULL;
}

int arvore_vazia(Arvore* arv)
{
    if ((*arv) == NULL) return 1; // EST� VAZIA
    else return 0; // N�O EST� VAZIA
}

void libera_arvore (Arvore* arv)
{
    if (!arvore_vazia(arv))   // ARVORE N�O EST� VAZIA
    {

        libera_arvore(&((*arv)->sae)); // LIBERA �RVORE DA ESQUERDA
        libera_arvore(&((*arv)->sad)); // LIBERA �RVORE DA DIREITA
        free (*arv); // LIBERA O N� RAIZ
    }
     *arv = NULL; // COLOCA O CONTE�DO DE A COMO NULL
}

void exibe_arvore (Arvore arv)
{
    if (arvore_vazia(&arv))
    {
        printf("<> ");
        return;
    }

    printf("< ");
    printf("%d ", arv->info.idade);
    exibe_arvore(arv->sae);
    exibe_arvore(arv->sad);
    printf("> ");
}

void exibe_ordenado (Arvore arv)
{
    if (!arvore_vazia(&arv))
    {
        exibe_ordenado(arv->sae);
        printf("%d ",arv->info.idade);
        exibe_ordenado(arv->sad);
    }
}

int insere_ordenado(Arvore* arv, Registro reg)
{
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

    if (reg.idade <= ((*arv)->info.idade)) // INSERE NO LADO ESQUERDO
    {
        return insere_ordenado ((&((*arv)->sae)),reg);
    }

    else // INSERE NO LADO DIREITO PORQUE � MAIOR
    {
        return insere_ordenado ((&((*arv)->sad)),reg);
    }
}

int remove_ordenado(Arvore* arv, int idade)
{
    if (arv == NULL || (*arv) == NULL) return 0;

    int arv_idade = (*arv)->info.idade;

    // PERCORRIMENTO P�S-ORDEM
    if (idade > arv_idade) return remove_ordenado(&(*arv)->sad,idade); // SE A IDADE FOR MAIOR, REMOVE NO LADO DIREITO -> CHAMA A RECURS�O
    else if (idade < arv_idade) return remove_ordenado(&(*arv)->sae,idade); // SE A IDADE FOR MENOR, REMOVE NO LADO ESQUERDO -> CHAMA A RECURS�O

    // TRATA A RAIZ
    else
    {
        if ( (*arv)->sae == NULL && (*arv)->sad == NULL) // SE � FOLHA
        {
            free((*arv)->info.nome); // DESALOCA A VARI�VEL NOME
            free((*arv)->info.curso); // DESALOCA A VARI�VEL CURSO
            free((*arv)); // LIBERA RAIZ
            *arv = NULL; // APONTA CONTE�DO DA RAIZ PRA NULL
            return 1;
        }

        else if ( (*arv)->sae != NULL && (*arv)->sad == NULL) // SE O LADO ESQUERDO � NULL, MAS O DIREITO N�O �
        {
            // REMO��O DO FILHO DA ESQUERDA
            Arvore aux = *arv;
            *arv = aux->sae;
            free(aux);
            return 1;
        }

        else if ( (*arv)->sae == NULL && (*arv)->sad != NULL)
        {
            // REMOVE FILHO DA DIREITA
            Arvore aux = *arv;
            *arv = aux->sad;
            free(aux);
            return 1;
        }

        else // AMBOS OS LADOS DIFERENTES DE NULL
        {
            Arvore aux = (*arv)->sae;

            while (aux->sad != NULL)
            {
                aux = aux->sad;
            }

            Registro temp = (*arv)->info;
            (*arv)->info = aux->info;
            aux->info = temp;

            return remove_ordenado(&(*arv)->sae,idade);
        }
    }
}

Arvore busca_bin (Arvore arv, int idade)
{
    if (arvore_vazia(&arv) || arv == NULL) return NULL; // �RVORE VAZIA

    int idade_arv = arv->info.idade;

    if (idade_arv == idade) return arv; // ENCONTROU A IDADE PROCURADA NA RAIZ
    else if (idade > idade_arv) return busca_bin(arv->sad,idade);
    else return busca_bin(arv->sae,idade);
}

Registro* maior(Arvore arv)
{
    if (arv == NULL || arvore_vazia(&arv)) return NULL; // �RVORE N�O EXISTE OU EST� VAZIA

    if (arv->sad == NULL) return (&arv->info); // ARVORE S� POSSUI N� RAIZ

    // MAIOR ELEMENTO VAI ESTAR SEMPRE NA RAIZ (CASO S� TENHA ELA) OU NO LADO DIREITO
    if (arv->sad != NULL && arv->sad->info.idade > arv->info.idade) return maior(arv->sad);
    else return NULL;
}

int de_maior(Arvore arv)
{
    if (arvore_vazia(&arv) || arv == NULL) return 0; // �RVORE VAZIA OU �RVORE N�O EXISTE

    int id = arv->info.idade;

    if(eh_folha(arv) && id >= 18) return 1; // CASO SEJA N� FOLHA E SEJA MAIOR DE IDADE

    else if (id >= 18) // CASO N�O SEJA N� FOLHA, MAS � MAIOR DE IDADE
    {
        return 1 + de_maior(arv->sae) + de_maior(arv->sad);
    }

    else // QUANDO N�O � N� FOLHA E NEM MAIOR DE IDADE
    {
        return de_maior(arv->sae) + de_maior(arv->sad); // S� CONTINUA A RECURS�O
    }
}

int qtd_alunos(Arvore arv, int inicial, int fim){
    if (arv == NULL) return 0; // �RVORE VAZIA

    int id = arv->info.idade;

    if (eh_folha(arv)) // CASO SEJA N� FOLHA
    {
        if (id > inicial && id < fim) return 1; // RETORNA 1 SE ESTIVER NO INTERVALO
    }

    else if (id > inicial && id < fim) // CASO N�O SEJA N� FOLHA, MAS EST� NO INTERVALO
    {
        return 1 + qtd_alunos(arv->sae,inicial,fim) + qtd_alunos(arv->sad,inicial,fim); // SOMA 1 E CHAMA A RECURS�O
    }

    else // CASO N�O SEJA N� FOLHA E N�O ESTEJA NO INTERVALO
    {
        return qtd_alunos(arv->sae,inicial,fim) + qtd_alunos(arv->sad,inicial,fim); // S� CHAMA A RECURS�O
    }

    return 0;
}

int conta_filhos(Arvore arv)
{
    if (arv == NULL || arvore_vazia(&arv)) return -1; // �RVORE N�O EXISTE OU � VAZIA

    if (arv->sae == NULL && arv->sad == NULL) return 0; // N�O POSSUI FILHOS
    else if (arv->sae != NULL && arv->sad == NULL) return 1; // POSSUI APENAS UM FILHO
    else if (arv->sae == NULL && arv->sad != NULL) return 1; // POSSUI APENAS UM FILHO
    else if (arv->sae != NULL && arv->sad != NULL) return 2; // POSSUI DOIS FILHOS

    return -1;
}

int um_filho(Arvore arv)
{
    if (arv == NULL) return 0; // �RVORE N�O EXISTE

    if (eh_folha(arv)) return 0; // N� FOLHA N�O POSSUI FILHOS

    else if (conta_filhos(arv) == 1) // QUANDO N� TEM 1 FILHO APENAS
    {
        return 1 + um_filho(arv->sae) + um_filho(arv->sad); // SOMA 1 E CHAMA A RECURS�O
    }

    else // CASO O N� N�O TENHA FILHOS OU TENHA 2 FILHOS
    {
        return um_filho(arv->sae) + um_filho(arv->sad); // S� CHAMA A RECURS�O
    }

}

int eh_folha(Arvore arv)
{
    if (arv == NULL || arvore_vazia(&arv)) return 0;

    if (arv->sae == NULL && arv->sad == NULL) return 1;
    else return 0;
}

int prof_no(Arvore arv, int chave){
    // FUN��O GATILHO QUE CALCULA A PROFUNDIDADE DO N�
    return calc_prof_no(arv, chave,0);
}

int calc_prof_no(Arvore arv, int chave, int nivel){
    if (arv == NULL) return 0;

    int id = arv->info.idade;

    if (id == chave) return nivel;

    int prof = calc_prof_no(arv->sae,chave,nivel+1);
    if (prof != 0) return prof;

    prof = calc_prof_no(arv->sad,chave,nivel+1);
    return prof;
}

int prof_arvore(Arvore arv){
    // FUN��O GATILHO QUE CALCULA A PROFUNDIDADE DO N�
    return calc_prof_arv(arv,0);
}

int calc_prof_arv(Arvore arv, int nivel){
    if (arv == NULL) return 0;

    if (eh_folha(arv)) return nivel;

    int p_sae = calc_prof_arv(arv->sae,nivel + 1);
    int p_sad = calc_prof_arv(arv->sad,nivel + 1);

    if (p_sae > p_sad) return p_sae;
    else return p_sad;
}

int calc_completa(Arvore arv, int altura){
    if (arv == NULL) return 1;

    if(eh_folha(arv)) // CASO SEJA N� FOLHA
    {
        // RETORNA 1 CASO O N� ESTEJA NO �LTIMO OU PEN�LTIMO N�VEL DA �RVORE
        if (prof_arvore(arv) > altura - 1) return 0;
        else return 1;
    }

    else if (eh_folha(arv->sae) && eh_folha(arv->sad)) // CASO SEJA UM N� INTERMEDI�RIO
    {
        if (conta_filhos(arv) == 2) return 1; // SE TIVER DOIS FILHOS, RETORNA 1
        else return 0; // CASO CONTR�RIO RETORNA 0
    }

    else // CASO N�O SEJA N� FOLHA OU N� INTERMEDI�RIO
    {
        return calc_completa(arv->sae,altura),calc_completa(arv->sad,altura); // S� CHAMA A RECURS�O
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

int altura_arvore(Arvore arv)  /// OK
{
    if (arv == NULL) return -1; // ARVORE VAZIA

    int h_sae,h_sad;
    h_sae = altura_arvore(arv->sae);
    h_sad = altura_arvore(arv->sad);

    if (h_sae > h_sad) return h_sae + 1;
    else return h_sad + 1;

}

Arvore concatena(Arvore a, Arvore b)
{
    if (a == NULL) return NULL; // ARVORE A NAO EXISTE OU ESTA VAZIA
    //exibe_arvore(b); // ILUSTRA O PROCESSO
    //printf("\n");

    Arvore aux = a;

    insere_ordenado(&b,aux->info);
    concatena(aux->sae,b);
    concatena(aux->sad,b);

    return b;
}

Arvore juntar (Arvore a, Arvore b)
{
    Arvore c = cria_vazia();

    c = concatena(a,c);
    c = concatena(b,c);
    //exibe_arvore(c); ILUSTRA
    return c;
}




