#include <stdio.h>
#include <stdlib.h>
#include "filadinamica.h"

int main()
{
    fila* fi= cria_fila();

    insere_fila(fi, 3);
    insere_fila(fi, 7);
    insere_fila(fi, 8);
    insere_fila(fi, 15);
    insere_fila(fi, 99);
    insere_fila(fi, 200);

    printf("--FILA 1--\n");

    exibe_fila(fi);


    remove_fila(fi);
    remove_fila(fi);

    printf("\n-- FILA 1 DEPOIS DE 2 REMOCOES -- \n");
    exibe_fila(fi);

    libera_fila(fi);
    return 0;
}
