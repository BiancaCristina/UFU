#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED
#define MAX 100

typedef struct pilha pilha;

pilha* cria_pilha(); // CRIA PILHA
void libera_pilha(pilha* p); // LIBERA PILHA
int tamanho_pilha(pilha* p); // CALCULA TAMANHO DA PILHA
int cheia_pilha(pilha* p); // VERIFICA SE PILHA ESTÁ CHEIA
int vazia_pilha(pilha* p); // VERIFICA SE PILHA ESTÁ VAZIA
int insere_pilha(pilha* p, int i); // INSERE NA PILHA (NO FINAL)
int remove_pilha(pilha* p); // REMOVE NA PILHA (NO FINAL)
void exibir_pilha(pilha* p); // EXIBE PILHA


#endif // PILHAESTATICA_H_INCLUDED
