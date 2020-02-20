#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
typedef struct Registro Registro;

struct Registro{
    int chave;
    char nome[100];
    int idade;
    double salario;
};

typedef struct no* Arvore;

Arvore cria_vazia ();
int arvore_vazia(Arvore* arv);
void libera_arvore(Arvore* arv);
void exibe_arvore (Arvore arv);
void exibe_ordenado (Arvore arv);
int insere_ordenado(Arvore* arv, Registro reg);
int remove_ordenado(Arvore* arv, int chave);
Arvore busca_bin (Arvore arv, int chave);




#endif // ABB_H_INCLUDED
