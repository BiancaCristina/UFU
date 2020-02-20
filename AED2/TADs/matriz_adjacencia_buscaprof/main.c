#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define LIMPABUFFER setbuf(stdin,NULL)
#define LIMPATELA system("clear || cls")

int main()
{
    int vertices=5;
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
        printf("\n\n\n\n--- MENU --- \n");
        printf("1- QUESTAO 2) \n");
        printf("2- QUESTAO 3) \n");
        printf("3- QUESTAO 4) \n");
        printf("4- SAIR\n");

        scanf("%d", &resposta);
        LIMPABUFFER;
        LIMPATELA;

        switch (resposta)
        {
        case 1:
        {
            printf("BUSCA EM PROFUNDIDADE PARA O VERTICE 0: \n");
            dispara_profundidade_matriz(g,0);
            LIMPABUFFER;
        }
        break;

        case 2:
        {
            printf("BUSCA EM PROFUNDIDADE PARA TODOS OS VERTICES: \n");
            dispara_profundidade_exploratodos_matriz(g);
            LIMPABUFFER;
        }
        break;

        case 3:
        {
            busca_em_profundidade_iter(g,0);
            LIMPABUFFER;
        }
        break;

        case 4:
        {
            printf("OBRIGADA POR USAR NOSSO PROGRAMA!\n");
            libera_grafo(&g);
            exit(1);
            LIMPABUFFER;
        }
        break;

        default:
        {
            printf("DIGITE UMA OPCAO VALIDA!!! \n\n");
            LIMPABUFFER;
        }
        break;
        }

    }
    while (resposta);



        return 1;
}
