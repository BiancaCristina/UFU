#ifndef TABELA_HASH_H_INCLUDED
#define TABELA_HASH_H_INCLUDED

typedef struct Aluno {
    int matricula; // CAMPO CHAVE
    int idade;
    char nome[30];
} Aluno;

typedef struct Hash Hash;

Hash* cria_Hash(int TABLE_SIZE);
void libera_Hash(Hash* ha);
int insere_Hash_SC(Hash* ha, Aluno al); // INSERE SEM COLISAO
int busca_Hash_SC(Hash* ha, int matricula, Aluno* al); // BUSCA SEM COLISAO
int insere_Hash_CC(Hash* ha, Aluno al); // INSERE COM COLISAO
int busca_Hash_CC(Hash* ha, int matricula, Aluno* al); // BUSCA COM COLISAO

int chave_Divisao(int chave, int TABLE_SIZE);
int chave_Multiplicacao(int chave, int TABLE_SIZE);
int chave_Dobra(int chave, int TABLE_SIZE);
int valor_String(char* str);

#endif // TABELA_HASH_H_INCLUDED
