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
    if ((*arv) == NULL) return 1; // ESTÁ VAZIA
    else return 0; // NÃO ESTÁ VAZIA
}

void libera_arvore (Arvore* arv)
{
    if (!arvore_vazia(arv))   // ARVORE NÃO ESTÁ VAZIA
    {

        libera_arvore(&((*arv)->sae)); // LIBERA ÁRVORE DA ESQUERDA
        libera_arvore(&((*arv)->sad)); // LIBERA ÁRVORE DA DIREITA
        free (*arv); // LIBERA O NÓ RAIZ
    }
     *arv = NULL; // COLOCA O CONTEÚDO DE A COMO NULL
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

    else // INSERE NO LADO DIREITO PORQUE É MAIOR
    {
        return insere_ordenado ((&((*arv)->sad)),reg);
    }
}

int remove_ordenado(Arvore* arv, int idade)
{
    if (arv == NULL || (*arv) == NULL) return 0;

    int arv_idade = (*arv)->info.idade;

    // PERCORRIMENTO PÓS-ORDEM
    if (idade > arv_idade) return remove_ordenado(&(*arv)->sad,idade); // SE A IDADE FOR MAIOR, REMOVE NO LADO DIREITO -> CHAMA A RECURSÃO
    else if (idade < arv_idade) return remove_ordenado(&(*arv)->sae,idade); // SE A IDADE FOR MENOR, REMOVE NO LADO ESQUERDO -> CHAMA A RECURSÃO

    // TRATA A RAIZ
    else
    {
        if ( (*arv)->sae == NULL && (*arv)->sad == NULL) // SE É FOLHA
        {
            free((*arv)->info.nome); // DESALOCA A VARIÁVEL NOME
            free((*arv)->info.curso); // DESALOCA A VARIÁVEL CURSO
            free((*arv)); // LIBERA RAIZ
            *arv = NULL; // APONTA CONTEÚDO DA RAIZ PRA NULL
            return 1;
        }

        else if ( (*arv)->sae != NULL && (*arv)->sad == NULL) // SE O LADO ESQUERDO É NULL, MAS O DIREITO NÃO É
        {
            // REMOÇÃO DO FILHO DA ESQUERDA
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
    if (arvore_vazia(&arv) || arv == NULL) return NULL; // ÁRVORE VAZIA

    int idade_arv = arv->info.idade;

    if (idade_arv == idade) return arv; // ENCONTROU A IDADE PROCURADA NA RAIZ
    else if (idade > idade_arv) return busca_bin(arv->sad,idade);
    else return busca_bin(arv->sae,idade);
}

Registro* maior(Arvore arv)
{
    if (arv == NULL || arvore_vazia(&arv)) return NULL; // ÁRVORE NÃO EXISTE OU ESTÁ VAZIA

    if (arv->sad == NULL) return (&arv->info); // ARVORE SÓ POSSUI NÓ RAIZ

    // MAIOR ELEMENTO VAI ESTAR SEMPRE NA RAIZ (CASO SÓ TENHA ELA) OU NO LADO DIREITO
    if (arv->sad != NULL && arv->sad->info.idade > arv->info.idade) return maior(arv->sad);
    else return NULL;
}

int de_maior(Arvore arv)
{
    if (arvore_vazia(&arv) || arv == NULL) return 0; // ÁRVORE VAZIA OU ÁRVORE NÃO EXISTE

    int id = arv->info.idade;

    if(eh_folha(arv) && id >= 18) return 1; // CASO SEJA NÓ FOLHA E SEJA MAIOR DE IDADE

    else if (id >= 18) // CASO NÃO SEJA NÓ FOLHA, MAS É MAIOR DE IDADE
    {
        return 1 + de_maior(arv->sae) + de_maior(arv->sad);
    }

    else // QUANDO NÃO É NÓ FOLHA E NEM MAIOR DE IDADE
    {
        return de_maior(arv->sae) + de_maior(arv->sad); // SÓ CONTINUA A RECURSÃO
    }
}

int qtd_alunos(Arvore arv, int inicial, int fim){
    if (arv == NULL) return 0; // ÁRVORE VAZIA

    int id = arv->info.idade;

    if (eh_folha(arv)) // CASO SEJA NÓ FOLHA
    {
        if (id > inicial && id < fim) return 1; // RETORNA 1 SE ESTIVER NO INTERVALO
    }

    else if (id > inicial && id < fim) // CASO NÃO SEJA NÓ FOLHA, MAS ESTÁ NO INTERVALO
    {
        return 1 + qtd_alunos(arv->sae,inicial,fim) + qtd_alunos(arv->sad,inicial,fim); // SOMA 1 E CHAMA A RECURSÃO
    }

    else // CASO NÃO SEJA NÓ FOLHA E NÃO ESTEJA NO INTERVALO
    {
        return qtd_alunos(arv->sae,inicial,fim) + qtd_alunos(arv->sad,inicial,fim); // SÓ CHAMA A RECURSÃO
    }

    return 0;
}

int conta_filhos(Arvore arv)
{
    if (arv == NULL || arvore_vazia(&arv)) return -1; // ÁRVORE NÃO EXISTE OU É VAZIA

    if (arv->sae == NULL && arv->sad == NULL) return 0; // NÃO POSSUI FILHOS
    else if (arv->sae != NULL && arv->sad == NULL) return 1; // POSSUI APENAS UM FILHO
    else if (arv->sae == NULL && arv->sad != NULL) return 1; // POSSUI APENAS UM FILHO
    else if (arv->sae != NULL && arv->sad != NULL) return 2; // POSSUI DOIS FILHOS

    return -1;
}

int um_filho(Arvore arv)
{
    if (arv == NULL) return 0; // ÁRVORE NÃO EXISTE

    if (eh_folha(arv)) return 0; // NÓ FOLHA NÃO POSSUI FILHOS

    else if (conta_filhos(arv) == 1) // QUANDO NÓ TEM 1 FILHO APENAS
    {
        return 1 + um_filho(arv->sae) + um_filho(arv->sad); // SOMA 1 E CHAMA A RECURSÃO
    }

    else // CASO O NÓ NÃO TENHA FILHOS OU TENHA 2 FILHOS
    {
        return um_filho(arv->sae) + um_filho(arv->sad); // SÓ CHAMA A RECURSÃO
    }

}

int eh_folha(Arvore arv)
{
    if (arv == NULL || arvore_vazia(&arv)) return 0;

    if (arv->sae == NULL && arv->sad == NULL) return 1;
    else return 0;
}

int prof_no(Arvore arv, int chave){
    // FUNÇÃO GATILHO QUE CALCULA A PROFUNDIDADE DO NÓ
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
    // FUNÇÃO GATILHO QUE CALCULA A PROFUNDIDADE DO NÓ
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




