/////////////////////////ÁRVORES/////////////////////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
///////// THAYNARA SILVA PINTO     - 11711BCC    /////////
///////// GUSTAVO                  - 11711BCC    /////////
//////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"
#define LIMPATELA system("cls || clear")
#define LIMPABUFFER setbuf(stdin,NULL)

int main()
{
    Arvore a = cria_vazia();
    Arvore b = cria_vazia();

    int resposta = 1;
    int escolha;
    int bal;

    do
    {
        printf("\n\n\n");
        printf("---------------------------------------------- MENU ----------------------------------------------\n");
        printf("1- CRIA ARVORE A E ARVORE B\n");
        printf("2- INSERE EM UMA ARVORE\n");
        printf("3- MOSTRA O NUMERO DE DERIVACAO DE UMA ARVORE AVL\n");
        printf("4- VERIFICA SE A ARVORE EH CHEIA\n");
        printf("5- MOSTRA O NIVEL DE UM DADO NO\n");
        printf("6- VERIFICA SE DUAS ARVORES SAO IGUAIS\n");
        printf("7- MOSTRA O PONTO DE REDE COM MENOR TRAFEGO\n");
        printf("8- MOSTRA A QUANTIDADE DE PONTOS OCIOSOS\n");
        printf("9- EXIBE ARVORES 1 E 2\n");
        printf("10- SAIR\n");

        scanf("%d", &resposta);
        LIMPABUFFER;
        LIMPATELA;

        switch (resposta)
        {
        case 1:
        {
            LIMPATELA;
            printf("ARVORE 1 E ARVORE 2 CRIADAS! \n");
            LIMPABUFFER;
        }
        break;

        case 2:
        {
            LIMPATELA;

            printf("DESEJA INSERIR NA ARVORE 1 OU ARVORE 2? \n");
            scanf("%d",&escolha);

            if (escolha != 1 && escolha != 2)
            {
                do
                {
                    printf("\nARVORE INVALIDA!\n");
                    printf("DESEJA INSERIR NA ARVORE 1 OU ARVORE 2?  ");
                    scanf("%d", &escolha);
                }
                while (escolha != 1 && escolha != 2);
            }

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

            printf("%s %s %d %d", reg.identificador,reg.localizacao,reg.trafego,reg.capacidade);


            if (escolha == 1) insere_avl(&a,reg,&bal);
            else if (escolha == 2) insere_avl(&b,reg,&bal);

            free(identificador);
            free(localizacao);

            LIMPABUFFER;
        }
        break;
        case 3:
        {
            LIMPATELA;

            printf("DESEJA VER O NUMERO DE DERIVACAO DA ARVORE 1 OU ARVORE 2? \n");
            scanf("%d",&escolha);

            if (escolha != 1 && escolha != 2)
            {
                do
                {
                    printf("\nARVORE INVALIDA!\n");
                    printf("DESEJA VER O NUMERO DE DERIVACAO DA ARVORE 1 OU ARVORE 2?   ");
                    scanf("%d", &escolha);
                }
                while (escolha != 1 && escolha != 2);
            }

            if (escolha == 1)
            {
                printf("O NUMERO DE DERIVACAO EH %d ", nro_derivacao(a));
            }

            else if (escolha == 2)
            {
                printf("O NUMERO DE DERIVACAO EH %d ", nro_derivacao(b));
            }

            LIMPABUFFER;
        }
        break;

        case 4:
        {
            LIMPATELA;

            printf("DESEJA VER SE ARVORE 1 OU ARVORE 2 EH CHEIA? \n");
            scanf("%d",&escolha);

            if (escolha != 1 && escolha != 2)
            {
                do
                {
                    printf("\nARVORE INVALIDA!\n");
                    printf("DESEJA VER SE ARVORE 1 OU ARVORE 2 EH CHEIA?    ");
                    scanf("%d", &escolha);
                }
                while (escolha != 1 && escolha != 2);
            }

            if (escolha == 1)
            {
                if (arvore_cheia(a)) printf("\nARVORE 1 EH CHEIA!");
                else printf("\nARVORE 1 NAO EH CHEIA!");
            }

            else if (escolha == 2)
            {
                if (arvore_cheia(b)) printf("\nARVORE 2 EH CHEIA!");
                else printf("\nARVORE 2 NAO EH CHEIA!");
            }

            LIMPABUFFER;

        }
        break;

        case 5:
        {
            LIMPATELA;
            char id[20];
            printf("\nNOME DO IDENTIFICADOR DO PONTO DE REDE: ");
            scanf("%s", id);
            LIMPABUFFER;

            printf("ESSE NO EH DA ARVORE 1 OU ARVORE 2? \n");
            scanf("%d",&escolha);

            if (escolha != 1 && escolha != 2)
            {
                do
                {
                    printf("\nARVORE INVALIDA!\n");
                    printf("ESSE NO EH DA ARVORE 1 OU ARVORE 2? ");
                    scanf("%d", &escolha);
                }
                while (escolha != 1 && escolha != 2);
            }


            if (escolha == 1)
            {
                int nivel = nivel_no(a,*busca_bin_id(a,id));

                if( nivel >= 0)
                {
                    printf("ESSE NO ESTA NO NIVEL %d DA ARVORE 1", nivel);
                }

                else printf("\nESSE NO NAO ESTA INSERIDO NA ARVORE 1\n");

            }

            else if (escolha == 2)
            {
                int nivel = nivel_no(a,*busca_bin_id(b,id));

                if( nivel >= 0)
                {
                    printf("ESSE NO ESTA NO NIVEL %d DA ARVORE 2", nivel);
                }

                else printf("\nESSE NO NAO ESTA INSERIDO NA ARVORE 2\n");
            }

            LIMPABUFFER;

        }
        break;

        case 6:
        {
            LIMPATELA;
            if (arvore_iguais(a,b)) printf("ARVORE 1 E 2 SAO IGUAIS\n");
            else printf("ARVORE 1 E 2 NAO SAO IGUAIS\n");
            LIMPABUFFER;
        }
        break;

        case 7:
        {
            LIMPATELA;

            printf("DESEJA VER O MENOR TRAFEGO DA ARVORE 1 OU ARVORE 2? \n");
            scanf("%d",&escolha);

            if (escolha != 1 && escolha != 2)
            {
                do
                {
                    printf("\nARVORE INVALIDA!\n");
                    printf("DESEJA VER O MENOR TRAFEGO DA ARVORE 1 OU ARVORE 2? ");
                    scanf("%d", &escolha);
                }
                while (escolha != 1 && escolha != 2);
            }

            if (escolha == 1)
            {
                Registro aux = (*menor_trafego(a));
                printf("\n%s POSSUI %d DE TRAFEGO E EH O MENOR DA ARVORE 1\n", aux.identificador, aux.trafego);
            }

            else if (escolha == 2)
            {
                Registro aux = (*menor_trafego(b));
                printf("\n%s POSSUI %d DE TRAFEGO E EH O MENOR DA ARVORE 2\n", aux.identificador, aux.trafego);
            }

            LIMPABUFFER;
        }
        break;

        case 8:
        {
            LIMPATELA;

            printf("DESEJA VER O NUMERO DE PONTOS OCIOSOS DA ARVORE 1 OU ARVORE 2? \n");
            scanf("%d",&escolha);

            if (escolha != 1 && escolha != 2)
            {
                do
                {
                    printf("\nARVORE INVALIDA!\n");
                    printf("DESEJA VER O NUMERO DE PONTOS OCIOSOS DA ARVORE 1 OU ARVORE 2?");
                    scanf("%d", &escolha);
                }
                while (escolha != 1 && escolha != 2);
            }

            if (escolha == 1)
            {
                printf("\nARVORE 1 POSSUI %d PONTOS OCIOSOS\n", qtde_ocioso(a));
            }

            else if (escolha == 2)
            {
                printf("\nARVORE 2 POSSUI %d PONTOS OCIOSOS\n", qtde_ocioso(b));
            }

            LIMPABUFFER;

        }
        break;

        case 9:
        {
            LIMPATELA;
            exibe_arvore(a);
            printf("\n\n");
            exibe_arvore(b);
            printf("\n\n");
            LIMPABUFFER;
        }
        break;

        case 10:
        {
            printf("OBRIGADA POR USAR NOSSO PROGRAMA!  :)  \n");
            LIMPATELA;
            LIMPABUFFER;
            libera_arvore(&a);
            libera_arvore(&b);
            exit(1);
        }
        break;

        default:
        {
            LIMPATELA;
            printf("OPCAO INVALIDA!  \n");
            LIMPABUFFER;
        }
        break;

        }
    }
    while (resposta);

    libera_arvore(&a);
    libera_arvore(&b);
    return 1;
}
