#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Lista {
    int tamanho;
    struct no* inicio;
} Lista;

Lista* cria_Lista();
int vazia_Lista(Lista* li);
int tamanho_Lista(Lista* li);
void exibe_Lista(Lista* li);
int insere_inicio_Lista(Lista* li, int info);
int insere_final_Lista(Lista* li, int info);
int insere_ordenado_Lista(Lista* li, int info);
int remove_Lista(Lista* li, int info);
int ordena_crescente_Lista(Lista* li);
int ordena_decrescente_Lista(Lista* li);
void libera_Lista(Lista** li);

#endif // LISTA_H_INCLUDED
