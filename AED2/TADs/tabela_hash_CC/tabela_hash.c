///////////////TABELA HASH - LISTA ENCADEADA//////////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

struct no {
    Aluno info;
    struct no* prox;
};

typedef struct no no;

struct Hash {
    int qtd; // QUANTIDADE DE ELEMENTOS NA TABELA
    int TABLE_SIZE;
    //Aluno** itens;
    no** itens;
};

Hash* cria_Hash(int TABLE_SIZE){
    if (TABLE_SIZE < 0) return NULL; // TAMANHO INVALIDO

    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if (ha == NULL) return NULL; // PROBLEMA AO ALOCAR TABELA HASH

    ha->itens = (no**)malloc(TABLE_SIZE * sizeof(no*));
    if (ha->itens == NULL) // PROBLEMA AO ALOCAR HA->ITENS
    {
        free(ha);
        return NULL;
    }

    ha->qtd = 0;
    ha->TABLE_SIZE = TABLE_SIZE;

    int i;
    int k; // USADO PARA CASO A ALOCACAO DE ERRADO

    for(i=0;i< TABLE_SIZE;i++)
    {
        ha->itens[i] = (no*)malloc(TABLE_SIZE * sizeof(no)); // TEORICAMENTE, NAO PRECISA DO TABLE_SIZE

        if (ha->itens[i] == NULL) // PROBLEMA NA ALOCACAO
        {
            for (k = 0; k < i;k++)
            {
                free(ha->itens[k]);
            }

            free(ha->itens);
            free(ha);
            return NULL;
        }
    }

    for (i=0;i< TABLE_SIZE;i++)
    {
        ha->itens[i] = NULL;
    }

    return ha;
}

void libera_Hash(Hash** ha){
    if (ha != NULL) // SE A HASH EXISTIR
    {
        int i;

        for(i=0;i< (*ha)->TABLE_SIZE;i++)
        {
            no* aux = (*ha)->itens[i];

            while (aux != NULL)
            {
                no* aux2 = aux;
                aux = aux->prox;
                free(aux2);
            }
        }

        free((*ha)->itens);
        free(ha);
        *ha = NULL;
    }
}

int chave_Divisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) & TABLE_SIZE;
    // 0x7FFFFFFF = ELIMINA BIT DE SINAL DO VALOR DA CHAVE -> IMPEDE OVERFLOW
}

int chave_Multiplicacao(int chave, int TABLE_SIZE){
    float a = 0.6180339887; // CONSTANTE: 0 <a < 1
    float valor = chave * a;
    valor = valor - (int)valor; // VALOR - PARTE INTEIRA = PARTE FRACIONARIA
    return (int) (TABLE_SIZE * valor);
}

int chave_Dobra(int chave, int TABLE_SIZE){
    int num_bits = 10; // DOBRA A CADA 10 BITS
    int parte1 = chave >> num_bits; // DESLOCA PRA DIREITA
    int parte2 = chave & (TABLE_SIZE - 1);
    return (parte1 ^ parte2); // PARTE1 (OU EXCLUSIVO = ^) parte2
}

int valor_String(char* str){
    int i;
    int valor = 7;
    int tamanho = strlen(str);

    for (i=0;i< tamanho;i++)
    {
        valor = 31 * valor + (int) str[i];
    }

    return valor;
}

int hash_dupla(int chave, int TABLE_SIZE){
    // COMBINA O METODO DA DIVISAO E O METODO DA MULTIPLICACAO
    int valor = chave_Divisao(chave, TABLE_SIZE);
    return chave_Multiplicacao(valor, TABLE_SIZE);
}

int insere_Hash_CC(Hash* ha, Aluno al){
    // 1 = DEU TUDO CERTO
    // -1 = INDICACAO DE ALGUM PROBLEMA
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE) return -1; // HASH NEM EXISTE OU ESTA CHEIA

    int chave = al.matricula;
    int posicao = hash_dupla(chave, ha->TABLE_SIZE);

    if (ha->itens[posicao] == NULL) // LISTA DE ITENS VAZIA NESSA POSICAO, SEM COLISAO AINDA
    {
        no* insere = (no*)malloc(sizeof(no));
        if (insere == NULL) return -1; // PROBLEMA AO ALOCAR O NO DE INSERIR

        insere->info = al;
        insere->prox = NULL;
        ha->itens[posicao] = insere;
        ha->qtd++;
        return 1;
    }

    else
    {
        no* insere = (no*)malloc(sizeof(no));
        if (insere == NULL) return -1; // PROBLEMA AO ALOCAR O NO DE INSERIR

        insere->info = al;
        insere->prox = (ha)->itens[posicao];
        (ha)->itens[posicao] = insere;
        ha->qtd++;
        return 1;
    }
}

int busca_Hash_CC(Hash* ha, int matricula, Aluno* al){
    // 1 = ACHOU A MATRICULA
    // 0 = NAO ACHOU MATRICULA
    // -1 = INDICACAO DE ALGUM PROBLEMA

    if (ha == NULL) return -1; // HASH NEM EXISTE

    int posicao = hash_dupla(matricula, ha->TABLE_SIZE);

    if (ha->itens[posicao] == NULL) return 0; // MATRICULA NAO ENCONTRADA

    else
    {
        no* aux = ha->itens[posicao];

        while (aux != NULL && aux->info.matricula != matricula)
        {
            aux = aux->prox;
        }

        if (aux == NULL) return 0; // MATRICULA NAO ENCONTRADA

        *al = (ha->itens[posicao]->info); // ISSO AQUI É USADO PRA ALGUÉM RECEBER OS DADOS DO ALUNO QUE TEM ESSA MATRICULA

        return 1;
    }
}

int remove_Hash_CC(Hash* ha, int matricula){ // REMOVE COM TRATAMENTO DE COLISAO
    // 1 = ACHOU A MATRICULA
    // 0 = NAO ACHOU MATRICULA
    // -1 = INDICACAO DE ALGUM PROBLEMA
    if (ha == NULL) return -1; // HASH NEM EXISTE

    int posicao = hash_dupla(matricula, ha->TABLE_SIZE);

    if (ha->itens[posicao] == NULL) return 0; // ESSA MATRICULA NAO ESTA NA HASH

    else
    {
        no* aux = ha->itens[posicao];
        no* ant = NULL;
        while (aux != NULL && aux->info.matricula != matricula)
        {
            ant = aux;
            aux = aux->prox;
        }

        if (aux == NULL) return 0; // MATRICULA NAO ENCONTRADA NA HASH

        no* remove = (no*)malloc(sizeof(no));
        if (remove == NULL) return -1; // PROBLEMA AO ALOCAR O NO PRA REMOVER

        if (ant == NULL) // ANTERIOR ERA O PRIMEIRO DA LISTA
        {
            ha->itens[posicao] = aux->prox; // PRIMEIRO DA LISTA AGORA VIROU NULL!
        }

        else
        {
            ant = aux->prox;
        }

        free(aux);

        ha->qtd--;

        return 1;
    }

}
