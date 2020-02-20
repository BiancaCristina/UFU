#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{
    int vertices = 8;
    Grafo* g = cria_grafo(vertices);

    insere_aresta(g,2,1,9);
    insere_aresta(g,4,1,8);
    insere_aresta(g,5,3,3);
    insere_aresta(g,4,2,11);
    insere_aresta(g,7,6,1);

    //verifica_aresta(g,4,2);
    //mostra_grafo(g);
    //printf("\n");
    //remove_aresta(g,5,3);
    //verifica_aresta(g,5,3);
    //verifica_aresta(g,3,5);
    //consulta_aresta(g,4,2,&p);
    //libera_grafo(&g);
    //mostra_adjacentes(g,4);
    //mostra_grafo(g);

    return 0;
}
