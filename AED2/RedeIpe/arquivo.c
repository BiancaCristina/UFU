/////////////////////////REDE IPE/////////////////////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
///////// THAYNARA SILVA PINTO     - 11711BCC    /////////
///////// GUSTAVO                  - 11711BCC    /////////
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "grafo.h"
#include "arquivo.h"

/// ARQUIVO
int le_vertice (vertice* v, char* url,int qtd_vertices)
{
    int i = 0;

    FILE* arq;

    arq = fopen (url,"r");

    if (arq == NULL) return -1;

    else
    {
        char cidade1[20];
        int vertice;
        int x,y;

        for(i=0; i< qtd_vertices && !feof(arq); i++)
        {
            fscanf(arq,"%d %s %d %d\n", &vertice, cidade1,&x,&y);
            ///preenche_vertice(v,i,vertice,cidade1,x,y,qtd_vertices);
            preenche_vertice(v,i,cidade1,vertice,x,y,qtd_vertices);

        }
    }

    return 1;
}

int le_aresta (aresta* a, char* url, int quantidade)
{
    int i = 0;

    FILE* arq;

    arq = fopen (url,"r");

    if (arq == NULL) return -1;

    else
    {
        int v1;
        int v2;
        float peso;


        while (!feof(arq))
        {
            fscanf(arq,"%d %d %f\n",&v1,&v2,&peso);
            preenche_aresta(a,i,v1,v2,peso);
            i++;
        }
    }

    return 1;
}

int tamanho_arquivo (char* url)
{
    int contador = 1;

    char c, letra = '\n';
    FILE* arq;

    arq = fopen (url,"r");

    if (arq == NULL) return -1;

    while(fread (&c, sizeof(char), 1, arq))
    {
        if(c == letra)
        {
            contador++;
        }
    }

    return contador;
}

char* le_cidade ()
{
    setbuf(stdin,NULL);
    char* cidade = (char*)malloc(20*sizeof(char));

    gets(cidade);
    setbuf(stdin,NULL);

    int i = 0;

    for (i=0; i<20; i++)
    {
        if (cidade[i] == ' ')
        {
            cidade[i] ='-';
        }
    }

    /// TRANSFORMA TODOS OS CARACTERES DA STRING EM MAISCULA
    // FAZ ISSO PARA BATER COM  BANCO DE DADOS CASO O USER DIGITE ALGO MINUSCULO

    for (i=0; i<20;i++)
    {
        cidade[i]=toupper(cidade[i]);
    }

    setbuf(stdin,NULL);
    return cidade;
}

char* formata_cidade (char* cidade){
    int i;

    for (i=0; i<20; i++)
    {
        if (cidade[i] == '-')
        {
            cidade[i] =' ';
        }
    }

    return cidade;
}
