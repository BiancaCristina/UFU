///////////TABELA HASH - ARVORE BINARIA DE BUSCA//////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
//////////////////////////////////////////////////////////

#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

typedef struct Aluno Aluno;

struct Aluno{
    int matricula;
    char nome[30];
    int idade;
};

typedef struct no* Arvore;

Arvore cria_vazia ();
int arvore_vazia(Arvore* arv);
void libera_arvore(Arvore* arv);
void exibe_arvore (Arvore arv);
void exibe_ordenado (Arvore arv);
int insere_ordenado(Arvore* arv, Aluno reg);
int remove_ordenado(Arvore* arv, int chave);
int busca_bin (Arvore arv, int chave);

#endif // ABB_H_INCLUDED
