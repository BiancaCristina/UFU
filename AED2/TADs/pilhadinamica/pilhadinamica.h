#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

typedef struct no {
    int dados;
    struct no* prox;
} no;

typedef struct pilha {
    int tamanho;
    no* inicio;
    // no* fim; OPCIONAL?
} pilha;

pilha* cria_pilha();
void libera_pilha(pilha* p);
int tamanho_pilha(pilha* p);
int cheia_pilha(pilha* p); // ESSA FUNCAO SO TA AQUI POR ESTAR, UMA VEZ QUE EH PILHA DINAMICA
int vazia_pilha(pilha* p);
int insere_pilha(pilha* p, int i);
int remove_pilha(pilha* p);
int remove_v2 (pilha* p);
// int remove_especifico_pilha(pilha* p, int pos);
void exibe_pilha(pilha* p);


#endif // PILHADINAMICA_H_INCLUDED
