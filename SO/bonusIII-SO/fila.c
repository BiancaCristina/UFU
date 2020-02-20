#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

fila** cria_fila (fila** fi) {
    if (fi != NULL) {
        (*fi)->inicio = 0;
        (*fi)->fim = 0;
        (*fi)->tamanho = 0;
        (*fi)->busywait = -1; // Flag pro busywait
    }

    return fi;
}

int insere_fila(fila** fi, int i) {
    if ((*fi) == NULL || (*fi)->tamanho == MAX){
        // Fila nao existe ou fila cheia
        printf("Fila nao existe ou fila cheia! \n");
        return 0;
    }

    (*fi)->dados[(*fi)->fim] = i;
    (*fi)->fim = ((*fi)->fim + 1) % MAX;
    (*fi)->tamanho++;

    return 1;
}

int remove_fila(fila** fi) {
    if ((*fi) == NULL || (*fi)->tamanho == 0) return 0; // Fila nao existe ou fila vazia
    
    (*fi)->inicio = ((*fi)->inicio+1) % MAX;
    (*fi)->tamanho--;
    return 1;
}

int remove_especifico(fila** fi) {
    if ((*fi) == NULL || (*fi)->tamanho == 0) return 0; // Fila nao existe ou fila vazia
    
    int removido = (*fi)->dados[(*fi)->inicio];

    (*fi)->inicio = ((*fi)->inicio+1) % MAX;
    (*fi)->tamanho--;

    return removido;
}

void exibe_fila(fila** fi) {
    int i=0;

    if ((*fi)->tamanho == 0) {
        printf("FILA VAZIA! \n");
        return;
    }
    
    while (i< (*fi)->tamanho){
        printf("%d \n", (*fi)->dados[i]);
        i++;
    }
}

int fila_cheia(fila** fi) {
    if ((*fi)->tamanho == MAX) return 1;
    else return 0;
}

int fila_vazia(fila** fi) {
    if ( (*fi)->tamanho == 0) return 1;
    else return 0;
}