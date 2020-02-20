#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista* li = cria_Lista();

    // INSERE INICIO
    insere_inicio_Lista(li,7);
    insere_inicio_Lista(li,2);

    // INSERE FINAL
    insere_final_Lista(li,4);
    insere_final_Lista(li,5);

    // INSERE ORDENADO
    insere_ordenado_Lista(li,6);

    printf("LISTA ANTES DE QUALQUER REMOCAO: ");
    exibe_Lista(li);
    printf("\nTAMANHO = %d", tamanho_Lista(li));

    // REMOVE 2 E 4:
    //remove_Lista(li,2);
    //remove_Lista(li,4);

    printf("\n\n\nLISTA DEPOIS DA REMOCAO: ");
    exibe_Lista(li);
    printf("\nTAMANHO = %d", tamanho_Lista(li));

    // ORDENA CRESCENTE LISTA:
    ordena_crescente_Lista(li);
    printf("\n\n\nLISTA DEPOIS DA ORDENACAO CRESCENTE: ");
    exibe_Lista(li);
    printf("\nTAMANHO = %d", tamanho_Lista(li));

    libera_Lista(&li);
    return 1;
}
