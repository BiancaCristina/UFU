#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

struct Hash {
    int qtd; // QUANTIDADE DE ELEMENTOS NA TABELA
    int TABLE_SIZE;
    Aluno** itens;
};

Hash* cria_Hash(int TABLE_SIZE){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if (ha == NULL) return NULL; // PROBLEMA NA ALOCACAO DA HASH

    int i;
    ha->TABLE_SIZE = TABLE_SIZE;
    ha->itens = (Aluno**)malloc(TABLE_SIZE * sizeof(Aluno*));

    if (ha->itens == NULL) // PROBLEMA NA ALOCACAO DE HA->ITENS
    {
        free(ha);
        return NULL;
    }

    ha->qtd = 0;

    for (i=0;i<ha->TABLE_SIZE;i++) // AQUI DEVERIA SER TABLE_SIZE - 1?
    {
        ha->itens[i] = NULL;
    }

    return ha;
}

void libera_Hash(Hash* ha){
    if (ha == NULL) return;

    int i;

    for (i=0;i< ha->TABLE_SIZE;i++)
    {
        if (ha->itens[i] != NULL) free (ha->itens[i]);
    }

    free(ha->itens);
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

int insere_Hash_SC(Hash* ha, Aluno al){
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE) return 0; // HASH NEM EXISTE OU ESTA CHEIA

    int chave = al.matricula;
    int posicao = chave_Divisao(chave, ha->TABLE_SIZE);

    Aluno* aux = (Aluno*)malloc(sizeof(Aluno));
    if (aux == NULL) return 0; // PROBLEMA AO ALOCAR VARIAVEL AUX

    *aux = al;
    ha->itens[posicao] = aux;
    ha->qtd++;
    return 1;
}

int busca_Hash_SC(Hash* ha, int matricula, Aluno* al){
    if (ha == NULL) return 0; // HASH NEM EXISTE

    int posicao = chave_Divisao(matricula, ha->TABLE_SIZE);
    if (ha->itens[posicao] == NULL) return 0; // ESSA MATRICULA NAO FOI ENCONTRADA

    *al = *(ha->itens[posicao]); // ISSO AQUI É USADO PRA ALGUÉM RECEBER OS DADOS DO ALUNO QUE TEM ESSA MATRICULA
    return 1;
}
