#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define LIMPABUFFER setbuf(stdin,NULL)
#define LIMPATELA system("clear || cls")

int main()
{
    int vertices = 5;
    Grafo* g = cria_grafo(vertices);

    insere_aresta(g,0,1,5);
    insere_aresta(g,0,2,4);
    insere_aresta(g,0,3,34);
    insere_aresta(g,4,4,2);

    /// VERIFICANDO SE EH CONEXO COM TODOS OS OUTROS VERTICES:
    if (busca_largura(g,0) == 1)
    {
        printf("EH CONECTADO A TODOS OS OUTROS VERTICES! \n\n");
        return 1;
    }
    /// VERIFICA SE EH NAO EH CONECTADO A NINGUEM OU SE SO NAO EH CONECTADO A ALGUM(ALGUNS) VERTICES
    /// COMENTA O COMANDO "insere_aresta(g,4,4,2);" PRA TESTAR

    else if (busca_largura_v2(g,4))
    {
        printf("NAO EH CONECTADO A NINGUEM!\n");
        return 1;
    }

    else printf("NAO EH CONECTADO A ALGUM VERTICE\n");

    return 1;

}
