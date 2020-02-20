/////////////////////////REDE IPE/////////////////////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
///////// THAYNARA SILVA PINTO     - 11711BCC    /////////
///////// GUSTAVO                  - 11711BCC    /////////
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"
#include "fila.h"
#include "grafo.h"
#define LIMPATELA system("cls || clear")
#define LIMPABUFFER setbuf(stdin,NULL)


int main()
{
    char* url1 = (char*)malloc(150*sizeof(char));
    char* url2 = (char*)malloc(150*sizeof(char));

    printf("DIGITE A LOCALIZACAO DO ARQUIVO 'no.txt':  ");
    scanf(" %s", url1);
    LIMPABUFFER;

    printf("\nDIGITE A LOCALIZACAO DO ARQUIVO 'arestas.txt':  ");
    scanf(" %s", url2);
    LIMPABUFFER;

    /*
    url1 = "D:/Users/Bianca/Desktop/Facul/2018-1/AED2/no.txt";
    url2 = "D:/Users/Bianca/Desktop/Facul/2018-1/AED2/arestas.txt";
    */

    LIMPATELA;

    int qtd_vertices = tamanho_arquivo(url1) -1; // A QUANTIDADE DE VERTICES == QUANTIDADE DE LINHAS DO ARQUIVO "no.txt"
    int qtd_arestas = tamanho_arquivo(url2); // A QUANTIDADE DE ARESTAS == QUANTIDADE DE LINHAS DO ARQUIVO "arestas.txt"

    Grafo* g = cria_grafo(qtd_vertices); // CRIA O GRAFO
    vertice* v = aloca_vertice(qtd_vertices); // CRIA O VETOR DE VERTICES A PARTIR DO ARQUIVO "no.txt"
    aresta* a = aloca_aresta(qtd_arestas); // CRIA O VETOR DE ARESTAS A PARTIR DO ARQUIVO "arestas.txt"
    le_vertice(v,url1,qtd_vertices); // PREENCHE VETOR DE VERTICES
    le_aresta(a,url2,qtd_arestas); // PREENCHE VETOR DE ARESTAS
    insere_aresta_banco(g,a,url2); // INSERE AS ARESTAS NO GRAFO

    LIMPATELA;
    int resposta = 1;

    do
    {
        printf("\n\n\n");
        printf("---------------------------------------------- MENU ----------------------------------------------\n");
        printf("1- MOSTRA NUMERO DE VERTICES DO GRAFO\n");
        printf("2- MOSTRA GRAU DE UM DETERMINADO VERTICE\n");
        printf("3- VERIFICA SE UM VERTICE EH ADJACENTE AO OUTRO\n");
        printf("4- MOSTRA O CAMINHO MAIS RAPIDO PARA TRAFEGAR UM ARQUIVO\n");
        printf("5- MOSTRA PONTOS QUE RECEBERAO UM ARQUIVO DADO UM TEMPO LIMITE PARA ESSA TRANSMISSAO\n");
        printf("6- MOSTRA A COBERTURA DE UM ENVIO DADA A QUANTIDADE MAXIMA DE PONTOS INTERMEDIARIOS\n");
        printf("7- MOSTRAR GRAFO COMPLETO\n");
        printf("8- VERIFICA SE UMA CIDADE PERTENCE AO GRAFO\n");
        printf("9- SAIR\n");

        scanf("%d", &resposta);
        LIMPABUFFER;
        LIMPATELA;

        switch (resposta)
        {
        case 1:
        {
            LIMPATELA;
            int numero_vertices = num_vertices(g);
            printf("O NUMERO DE VERTICES DO GRAFO EH: %d\n\n\n\n", numero_vertices);
            LIMPABUFFER;

        }
        break;

        case 2:
        {
            LIMPATELA;
            printf("INFORME A CIDADE: ");
            char* cidade1 = le_cidade();
            LIMPABUFFER;

            int v1 = busca(v,cidade1,qtd_vertices);
            if (v1 < 0 )
            {
                printf("CIDADE NAO ENCONTRADA NO BANCO DE DADOS!\n");
                break;
            }

            formata_cidade(cidade1);

            int grau = grau_vertice(g,v1);
            printf("\n %s POSSUI %d CONEXOES!\n\n", cidade1,grau);
            LIMPABUFFER;

        }
        break;

        case 3:
        {
            LIMPATELA;
            int v1,v2;

            printf("INFORME A CIDADE DE ORIGEM: ");
            char* cidade1 = le_cidade();
            LIMPABUFFER;

            v1 = busca(v,cidade1,qtd_vertices);
            if (v1 < 0 )
            {
                printf("CIDADE NAO ENCONTRADA NO BANCO DE DADOS!\n");
                break;
            }
            printf("\nINFORME A CIDADE DESTINO: ");

            char* cidade2 = le_cidade();
            LIMPABUFFER;

            v2 = busca(v,cidade2,qtd_vertices);
            if (v2 < 0 )
            {
                printf("CIDADE NAO ENCONTRADA NO BANCO DE DADOS!\n");
                break;
            }

            formata_cidade(cidade1);
            formata_cidade(cidade2);

            if (verifica_adjacencia(g,v1,v2) == 1) printf("A CIDADE %s e %s SAO ADJACENTES!\n", cidade1,cidade2);
            else printf("A CIDADE %s e %s NAO SAO ADJACENTES!\n", cidade1,cidade2);
            LIMPABUFFER;

        }
        break;

        case 4:
        {
            LIMPATELA;
            int v1,v2;

            printf("INFORME A CIDADE DE ORIGEM: ");
            char* cidade1 = le_cidade();
            LIMPABUFFER;

            v1 = busca(v,cidade1,qtd_vertices);
            if (v1 < 0 )
            {
                printf("CIDADE NAO ENCONTRADA NO BANCO DE DADOS!\n");
                break;
            }
            printf("\nINFORME A CIDADE DESTINO: ");

            char* cidade2 = le_cidade();
            LIMPABUFFER;

            v2 = busca(v,cidade2,qtd_vertices);
            if (v2 < 0 )
            {
                printf("CIDADE NAO ENCONTRADA NO BANCO DE DADOS!\n");
                break;
            }

            float tamanho_arq = 0;

            printf("DIGITE O TAMANHO DO ARQUIVO (EM Mbytes):  ");
            scanf("%f", &tamanho_arq);
            LIMPABUFFER;

            if (tamanho_arq < 0)
            {
                do
                {
                    printf("\nTAMANHO INVALIDO!\n");
                    printf("DIGITE O TAMANHO DO ARQUIVO (EM Mbytes):  ");
                    scanf("%f", &tamanho_arq);
                }
                while (tamanho_arq < 0);
            }

            dijkstra(g,v1,v2,tamanho_arq,qtd_arestas,v);
            LIMPABUFFER;

        }
        break;

        case 5:
        {
            LIMPATELA;
            int v1;

            printf("INFORME A CIDADE DE ORIGEM: ");
            char* cidade1 = le_cidade();
            LIMPABUFFER;

            v1 = busca(v,cidade1,qtd_vertices);
            if (v1 < 0 )
            {
                printf("CIDADE NAO ENCONTRADA NO BANCO DE DADOS!\n");
                break;
            }

            float tamanho_arq = 0;

            printf("DIGITE O TAMANHO DO ARQUIVO (EM Mbytes):  ");
            scanf("%f", &tamanho_arq);
            LIMPABUFFER;

            if (tamanho_arq < 0)
            {
                do
                {
                    printf("\nTAMANHO INVALIDO!\n");
                    printf("DIGITE O TAMANHO DO ARQUIVO (EM Mbytes):  ");
                    scanf("%f", &tamanho_arq);
                }
                while (tamanho_arq < 0);
            }

            float tempo_max1 = 0;

            printf("DIGITE O TEMPO MAXIMO (EM SEGUNDOS):  ");
            scanf("%f", &tempo_max1);
            LIMPABUFFER;

            if (tempo_max1 < 0)
            {
                do
                {
                    printf("\nTEMPO INVALIDO!\n");
                    printf("DIGITE O TEMPO MAXIMO (EM SEGUNDOS):  ");
                    scanf("%f", &tempo_max1);
                }
                while (tempo_max1 < 0);
            }

            tempo_max(g,v1,tempo_max1,tamanho_arq,v);

            LIMPABUFFER;

        }
        break;

        case 6:
        {
            LIMPATELA;
            int v1;

            printf("INFORME A CIDADE DE ORIGEM: ");
            char* cidade1 = le_cidade();
            LIMPABUFFER;

            v1 = busca(v,cidade1,qtd_vertices);
            if (v1 < 0 )
            {
                printf("CIDADE NAO ENCONTRADA NO BANCO DE DADOS!\n");
                break;
            }

            int qtd_pontos;

            printf("DIGITE A QUANTIDADE DE PONTOS INTERMEDIARIOS: ");
            scanf("%d", &qtd_pontos);
            LIMPABUFFER;

            if (qtd_pontos < 0)
            {
                do
                {
                    printf("\nQUANTIDADE DE PONTOS INTERMEDIARIOS INVALIDA!\n");
                    printf("DIGITE A QUANTIDADE DE PONTOS INTERMEDIARIOS: ");
                    scanf("%d", &qtd_pontos);

                }
                while (qtd_pontos < 0);
            }

            cobertura_envio_max(g,v1,qtd_pontos,v);
            LIMPABUFFER;
        }
        break;

        case 7:
        {
            mostra_grafo_comnome(g,v,a);
            LIMPABUFFER;
        }
        break;

        case 8:
        {
            printf("INFORME A CIDADE: ");
            char* cidade1 = le_cidade();
            LIMPABUFFER;

            int v1 = busca(v,cidade1,qtd_vertices);
            if (v1 < 0 )
            {
                printf("CIDADE NAO ENCONTRADA NO BANCO DE DADOS!\n");
                break;
            }

            formata_cidade(cidade1);
            printf("CIDADE %s PERTENCE AO GRAFO!" ,cidade1);
            LIMPABUFFER;

        }
        break;
        case 9:
        {
            LIMPATELA;
            LIMPABUFFER;
            printf("OBRIGADA POR USAR NOSSO PROGRAMA! \n\n");
            libera_grafo(&g);
            free(url1);
            free(url2);
            free(v);
            free(a);
            exit(1);
        }
        break;

        default:
        {
            printf("\n\n\nDIGITE UMA OPCAO VALIDA!\n\n\n");
            system("cls || clear");
            LIMPABUFFER;
        }
        break;

        }
    }
    while (resposta);

    return 1;
}
