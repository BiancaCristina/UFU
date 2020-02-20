#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"
#define LIMPATELA system("cls || clear")
#define LIMPABUFFER setbuf(stdin,NULL)

int main()
{
    int vertices = 6;
    Grafo* g = cria_grafo(vertices);

    insere_aresta(g,0,1,5);
    insere_aresta(g,0,2,4);
    insere_aresta(g,2,1,11);
    insere_aresta(g,1,3,5);
    insere_aresta(g,1,4,6);
    insere_aresta(g,3,4,2);
    insere_aresta(g,2,4,2);

    int resposta = 1;

    do
    {
        printf("---- MENU ---- \n");
        printf("1- QUESTAO 5)\n");
        printf("2- SAIR\n");

        scanf("%d", &resposta);
        LIMPABUFFER;
        LIMPATELA;

        switch(resposta)
        {
        case 1:
        {
            printf("BUSCA EM PROFUNDIDADE PARA O VERTICE 0: \n");
            dispara_profundidade(g,0);

            printf("\n\nBUSCA EM PROFUNDIDADE PARA TODOS OS VERTICES: \n");
            dispara_profundidade_exploratodos(g);

            printf("\n\nBUSCA EM PROFUNDIDADE ITERATIVA PARA O VERTICE 0: \n");
            busca_em_profundidade_iter(g,0);

            LIMPABUFFER;
        }
        break;

        case 2:
        {
            printf("OBRIGADA POR USAR O PROGRAMA! \n");
            libera_grafo(&g);
            LIMPABUFFER;
            exit(1);
        }
        break;

        default:
        {
            printf("DIGITE UMA OPCAO VALIDA!\n\n\n");

        } break;
        }
    }
    while (resposta);

    return 1;
}
