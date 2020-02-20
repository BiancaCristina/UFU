#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#define LIMPATELA system("cls || clear")
#define LIMPABUFFER setbuf(stdin,NULL)

Registro cria_Registro()
{
    char* identificador = (char*)malloc(20*sizeof(char));
    char* localizacao = (char*)malloc(20*sizeof(char));
    int capacidade;
    int trafego;

    printf("\nDIGITE AS INFORMACOES DO PONTO DE REDE: \n");
    printf("\nIDENTIFICADOR: ");
    scanf("%s", identificador);
    LIMPABUFFER;

    printf("\nLOCALIZACAO: ");
    scanf("%s", localizacao);
    LIMPABUFFER;

    printf("\nCAPACIDADE: ");
    scanf("%d", &capacidade);

    printf("\nTRAFEGO: ");
    scanf("%d", &trafego);

    Registro reg;
        strcpy(reg.identificador,identificador);
        strcpy(reg.localizacao,localizacao);
        reg.capacidade = capacidade;
        reg.trafego = trafego;

    return reg;
}
