#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED
#define MAX 100

typedef struct pilha pilha;

pilha* cria_pilha();
void libera_pilha(pilha* p);
int tamanho_pilha(pilha* p);
int cheia_pilha(pilha* p);
int vazia_pilha(pilha* p);
int insere_pilha(pilha* p, int i);
int remove_pilha(pilha* p);
int remove_especifico (pilha* p);
void exibir_pilha(pilha* p);


#endif // PILHAESTATICA_H_INCLUDED

