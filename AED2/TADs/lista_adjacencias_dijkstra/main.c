#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define LIMPABUFFER setbuf(stdin,NULL)
#define LIMPATELA system("cls || clear")

int main()
{
    int vertices = 5;
    Grafo* g = cria_grafo(vertices);

    insere_aresta(g,0,1,5);
    insere_aresta(g,0,2,40);
    insere_aresta(g,1,2,5);
    insere_aresta(g,2,1,11);
    insere_aresta(g,1,3,5);
    insere_aresta(g,1,4,6);
    insere_aresta(g,3,4,2);
    insere_aresta(g,2,4,2);

    mostra_grafo(g);
    printf("\n\n");
    dijkstra(g,0,2);

    return 1;
}
