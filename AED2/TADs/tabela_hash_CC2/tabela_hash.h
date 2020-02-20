///////////TABELA HASH - ARVORE BINARIA DE BUSCA//////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
//////////////////////////////////////////////////////////

#ifndef TABELA_HASH_H_INCLUDED
#define TABELA_HASH_H_INCLUDED
#include "abb.h"
/*
typedef struct Aluno {
    int matricula; // CAMPO CHAVE
    int idade;
    char nome[30];
} Aluno;
*/
typedef struct Hash Hash;

Hash* cria_Hash(int TABLE_SIZE);
void libera_Hash(Hash** ha);
int insere_Hash_CC(Hash* ha, Aluno al); // INSERE COM TRATAMENTO DE COLISAO
int busca_Hash_CC(Hash* ha, int matricula, Aluno* al); // BUSCA COM TRATAMENTO DE COLISAO
int remove_Hash_CC(Hash* ha, int matricula); // REMOVE COM TRATAMENTO DE COLISAO

int chave_Divisao(int chave, int TABLE_SIZE);
int chave_Multiplicacao(int chave, int TABLE_SIZE);
int chave_Dobra(int chave, int TABLE_SIZE);
int valor_String(char* str);

int hash_dupla(int chave, int TABLE_SIZE);


#endif // TABELA_HASH_H_INCLUDED
