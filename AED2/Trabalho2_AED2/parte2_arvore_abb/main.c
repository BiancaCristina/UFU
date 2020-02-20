/////////////////////////ÁRVORES/////////////////////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
///////// THAYNARA SILVA PINTO     - 11711BCC    /////////
///////// GUSTAVO                  - 11711BCC    /////////
//////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"
#define LIMPATELA system("cls || clear")
#define LIMPABUFFER setbuf(stdin,NULL)

int main()
{
    Arvore a = cria_vazia();
    Arvore b = cria_vazia();
    Arvore c;

    int resposta;
    int escolha;

    do
    {
        printf("\n\n\n");
        printf("---------------------------------------------- MENU ----------------------------------------------\n");
        printf("1- CRIA ARVORE 1 E ARVORE 2\n");
        printf("2- INSERE EM UMA ARVORE\n");
        printf("3- MOSTRA QUAL EH O ALUNO MAIS VELHO CADASTRADO\n");
        printf("4- MOSTRA A QUANTIDADE DE ALUNOS MAIORES DE IDADE\n");
        printf("5- MOSTRA QUANTIDADE DE ALUNOS NO INTERVALO INSERIDO\n");
        printf("6- MOSTRA A QUANTIDADE DE NOS DA ARVORE QUE POSSUEM APENAS UM FILHO\n");
        printf("7- VERIFICA SE A ARVORE EH COMPLETA\n");
        printf("8- MOSTRA A ALTURA DA ARVORE\n");
        printf("9- JUNTA AS ARVORES 1 E 2\n");
        printf("10- EXIBE ARVORE 1 E 2\n");
        printf("11- SAIR\n");

        scanf("%d", &resposta);
        LIMPABUFFER;
        LIMPATELA;

        switch (resposta)
        {
        case 1:
        {
            LIMPATELA;
            printf("AS ARVORES 1 E 2 FORAM CRIADAS!\n");
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

            char* nome = (char*)malloc(20*sizeof(char));
            char* curso = (char*)malloc(20*sizeof(char));
            int idade;

            printf("\nDIGITE O NOME DO ALUNO: ");
            scanf("%s", nome);
            LIMPABUFFER;

            printf("\nDIGITE O CURSO DO ALUNO: ");
            scanf("%s", curso);
            LIMPABUFFER;

            printf("\nDIGITE A IDADE DO ALUNO: ");
            scanf("%d", &idade);
            LIMPABUFFER;

            Registro reg;
                strcpy(reg.nome,nome);
                strcpy(reg.curso,curso);
                reg.idade = idade;

            printf("%s %s %d", reg.nome,reg.curso,reg.idade);
            if (escolha == 1) insere_ordenado(&a,reg);
            else if (escolha == 2) insere_ordenado(&b,reg);

            free(nome);
            free(curso);
            LIMPABUFFER;
        }
        break;
        case 3:
        {
            LIMPATELA;

            printf("DESEJA VERIFICAR NA ARVORE 1 OU ARVORE 2? \n");
            scanf("%d",&escolha);

            if (escolha != 1 && escolha != 2)
            {
                do
                {
                    printf("\nARVORE INVALIDA!\n");
                    printf("DESEJA VERIFICAR NA ARVORE 1 OU ARVORE 2?  ");
                    scanf("%d", &escolha);
                }
                while (escolha != 1 && escolha != 2);
            }


            if (escolha == 1)
            {
                Registro temp = (*maior(a));
                printf("O ALUNO MAIS VELHO CADASTRADO NA ARVORE 1 EH %s COM %d ANOS", temp.nome,temp.idade);
            }

            else
            {
                Registro temp = (*maior(b));
                printf("O ALUNO MAIS VELHO CADASTRADO NA ARVORE 2 EH %s COM %d ANOS", temp.nome,temp.idade);
            }

            LIMPABUFFER;

        }
        break;

        case 4:
        {
            LIMPATELA;

            printf("DESEJA VERIFICAR NA ARVORE 1 OU ARVORE 2? \n");
            scanf("%d",&escolha);

            if (escolha != 1 && escolha != 2)
            {
                do
                {
                    printf("\nARVORE INVALIDA!\n");
                    printf("DESEJA VERIFICAR NA ARVORE 1 OU ARVORE 2?  ");
                    scanf("%d", &escolha);
                }
                while (escolha != 1 && escolha != 2);
            }

            if (escolha == 1) printf("HA %d ALUNOS MAIORES DE IDADE NA ARVORE 1", de_maior(a));
            else printf("HA %d ALUNOS MAIORES DE IDADE NA ARVORE 2", de_maior(b));

            LIMPABUFFER;

        }
        break;

        case 5:
        {
            LIMPATELA;

            printf("DESEJA VERIFICAR NA ARVORE 1 OU ARVORE 2? \n");
            scanf("%d",&escolha);

            if (escolha != 1 && escolha != 2)
            {
                do
                {
                    printf("\nARVORE INVALIDA!\n");
                    printf("DESEJA VERIFICAR NA ARVORE 1 OU ARVORE 2?  ");
                    scanf("%d", &escolha);
                }
                while (escolha != 1 && escolha != 2);
            }

            int inicio, fim;

            printf("\nDIGITE O INICIO DO INTERVALO: ");
            scanf("%d",&inicio);

            if (inicio < 0)
            {
                do
                {
                    printf("\nINTERVALO INVALIDO!\n");
                    printf("DIGITE O INICIO DO INTERVALO: \n");
                    scanf("%d",&inicio);
                }
                while (inicio < 0);
            }

            printf("\nDIGITE O FIM DO INTERVALO: ");
            scanf("%d",&fim);

            if (fim < 0)
            {
                do
                {
                    printf("\nINTERVALO INVALIDO!\n");
                    printf("DIGITE O FIM DO INTERVALO: \n");
                    scanf("%d",&fim);
                }
                while (fim < 0);
            }

            if (escolha == 1) printf("HA %d ALUNOS NESSE INTERVALO NA ARVORE 1", qtd_alunos(a,inicio,fim));
            else if (escolha == 2) printf("HA %d ALUNOS NESSE INTERVALO NA ARVORE 2", qtd_alunos(b,inicio,fim));

            LIMPABUFFER;

        }
        break;

        case 6:
        {
            LIMPATELA;

            printf("DESEJA VERIFICAR NA ARVORE 1 OU ARVORE 2? \n");
            scanf("%d",&escolha);

            if (escolha != 1 && escolha != 2)
            {
                do
                {
                    printf("\nARVORE INVALIDA!\n");
                    printf("DESEJA VERIFICAR NA ARVORE 1 OU ARVORE 2?  ");
                    scanf("%d", &escolha);
                }
                while (escolha != 1 && escolha != 2);
            }

            if (escolha == 1) printf("NESSA ARVORE HA %d COM APENAS UM FILHO\n", um_filho(a));
            else printf("NESSA ARVORE HA %d COM APENAS UM FILHO\n", um_filho(b));

            LIMPABUFFER;
        }
        break;

        case 7:
        {
            LIMPATELA;

            printf("DESEJA VERIFICAR NA ARVORE 1 OU ARVORE 2? \n");
            scanf("%d",&escolha);

            if (escolha != 1 && escolha != 2)
            {
                do
                {
                    printf("\nARVORE INVALIDA!\n");
                    printf("DESEJA VERIFICAR NA ARVORE 1 OU ARVORE 2?  ");
                    scanf("%d", &escolha);
                }
                while (escolha != 1 && escolha != 2);
            }

            if (escolha == 1)
            {
                if (completa(a) == 1) printf("ARVORE 1 EH COMPLETA\n");
                else printf("ARVORE 1 NAO EH COMPLETA\n");
            }
            else
            {
                if (completa(b) == 1) printf("ARVORE 2 EH COMPLETA\n");
                else printf("ARVORE 2 NAO EH COMPLETA\n");
            }

            LIMPABUFFER;
        }
        break;

        case 8:
        {
            LIMPATELA;

            printf("DESEJA VERIFICAR NA ARVORE 1 OU ARVORE 2? \n");
            scanf("%d",&escolha);

            if (escolha != 1 && escolha != 2)
            {
                do
                {
                    printf("\nARVORE INVALIDA!\n");
                    printf("DESEJA VERIFICAR NA ARVORE 1 OU ARVORE 2?  ");
                    scanf("%d", &escolha);
                }
                while (escolha != 1 && escolha != 2);
            }

            if (escolha == 1) printf("A ALTURA DA ARVORE 1 EH %d", altura_arvore(a));
            else printf("A ALTURA DA ARVORE 1 EH %d", altura_arvore(b));

            LIMPABUFFER;

        }
        break;

        case 9:
        {
            LIMPATELA;

            c = juntar(a,b);
            exibe_arvore(c);
            free(&c); // TALVEZ ISSO GERE ALGUM PROBLEMA
            LIMPABUFFER;

        }
        break;

        case 10:
        {
            //LIMPATELA;
            exibe_arvore(a);
            printf("\n\n");
            exibe_arvore(b);
            //LIMPABUFFER;

        }break;

        case 11:
        {
            printf("OBRIGADA POR USAR NOSSO PROGRAMA!  :)  \n");
            LIMPATELA;
            LIMPABUFFER;
            libera_arvore(&a);
            libera_arvore(&b);
            exit(1);

        }break;

        default:
        {
            LIMPATELA;
            printf("OPCAO INVALIDA!   \n");
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

