///////////TABELA HASH - ARVORE BINARIA DE BUSCA//////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

struct Hash {
    int qtd; // QUANTIDADE DE ELEMENTOS NA TABELA
    int TABLE_SIZE;
    //Aluno** itens;
    Arvore** itens;
};

Hash* cria_Hash(int TABLE_SIZE){
    if (TABLE_SIZE < 0) return NULL; // TAMANHO INVALIDO

    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if (ha == NULL) return NULL; // PROBLEMA AO ALOCAR TABELA HASH

    ha->itens = (Arvore**)malloc(TABLE_SIZE * sizeof(Arvore*));
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
        ha->itens[i] = (Arvore*)malloc(TABLE_SIZE * sizeof(Arvore));

        if (ha->itens[i] == NULL) // PROBLEMA NA ALOCACAO
        {
            for(k=0;k<i;k++)
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
            if (!arvore_vazia( &(*ha)->itens[i] )) libera_arvore( &(*ha)->itens[i] );
        }
    }

    libera_arvore( &(*ha)->itens );
    free(ha);
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

    // INSERE NA ARVORE, ORDENANDO CADA ALUNO PELA MATRICULA
    insere_ordenado(&ha->itens[posicao], al);
    ha->qtd++;

    return 1;
}

int busca_Hash_CC(Hash* ha, int matricula, Aluno* al){
    if (ha == NULL) return 0;

    int posicao = hash_dupla(matricula, ha->TABLE_SIZE);

    if (ha->itens[posicao] == NULL) return 0; // MATRICULA NAO ENCONTRADA

    else
    {
        return busca_bin(ha->itens[posicao], matricula);
    }
}

int remove_Hash_CC(Hash* ha, int matricula){
    if (ha == NULL) return -1; // HASH NEM EXISTE

    int chave = matricula;
    int posicao = hash_dupla(chave, ha->TABLE_SIZE);

    // REMOVE ORDENADAMENTE DA ARVORE
    remove_ordenado(&ha->itens[posicao],chave);
    ha->qtd--;

    return 1;
}


