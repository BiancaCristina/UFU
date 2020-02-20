#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

typedef struct no {
    int dados;
    struct no* prox;
} no;

typedef struct fila {
    int tamanho;
    no* inicio;
    no* fim;
} fila;



fila* cria_fila();
void libera_fila(fila* fi);
int fila_tamanho(fila* fi);
int fila_cheia(fila* fi);
int fila_vazia(fila* fi);
void exibe_fila(fila* fi);
int insere_fila(fila* fi, int i);
int remove_fila(fila* fi);

#endif // FILADINAMICA_H_INCLUDED
