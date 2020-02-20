#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include "pilhaestatica.h"

int main()
{
    pilha *p = cria_pilha();
    insere_pilha(p, 4);
    insere_pilha(p, 7);
    insere_pilha(p, 11);
    insere_pilha(p, 19);

    exibir_pilha(p);
    printf("\nTAMANHO = %d\n", tamanho_pilha(p));

    remove_pilha(p);
    remove_pilha(p);
    printf("\n");
    exibir_pilha(p);

    libera_pilha(p);
    return 0;
}
