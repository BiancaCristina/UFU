///////////////TABELA HASH - LISTA ENCADEADA//////////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"
#define LIMPATELA system("cls || clear")
#define LIMPABUFFER setbuf(stdin,NULL)

int main()
{
    Hash* ha = cria_Hash(1421);

    int resposta;

    do
    {
        printf("\n\n\n");
        printf("---------------------------------------------- MENU ----------------------------------------------\n");
        printf("1- CRIA HASH\n");
        printf("2- INSERE NA HASH\n");
        printf("3- REMOVE NA HASH\n");
        printf("4- BUSCA NA HASH\n");
        printf("5- SAIR\n");

        scanf("%d", &resposta);
        LIMPABUFFER;
        LIMPATELA;

        switch (resposta)
        {
        case 1:
        {
            LIMPATELA;
            printf("HASH CRIADA! \n");
            LIMPABUFFER;

        }
        break;

        case 2:
        {
            LIMPATELA;
            char nome[30];
            int matricula, idade;
            printf("Informe os dados do aluno a ser inserido: \n");
            printf("Nome: ");
            scanf("%s", nome);

            printf("\nIdade: ");
            scanf("%d", &idade);

            printf("\nMatricula: ");
            scanf("%d", &matricula);

            Aluno aux;
                aux.idade = idade;
                aux.matricula = matricula;
                strcpy(aux.nome,nome);

            if (insere_Hash_CC(ha,aux)) printf("\n\nALUNO %s INSERIDO!", nome);
            else printf("\nErro na insercao!");

            LIMPABUFFER;
        }
        break;
        case 3:
        {
            LIMPATELA;
            int matricula;

            printf("Digite a matricula do aluno: ");
            scanf("%d", &matricula);

            if (remove_Hash_CC(ha, matricula)) printf("\nAluno removido!");
            else printf("\nAluno nao encontrado!");
            LIMPABUFFER;

        }
        break;

        case 4:
        {
            LIMPATELA;
            Aluno aux;
            int matricula;
            printf("\nDigite a matricula do aluno: ");
            scanf("%d", &matricula);

            if (busca_Hash_CC(ha, matricula, &aux)) printf("\nAluno ESTA NA HASH!");
            else printf("\nAluno nao esta na HASH!");

            LIMPABUFFER;

        }
        break;

        case 5:
        {
            printf("OBRIGADA POR USAR NOSSO PROGRAMA!  :)  \n");
            LIMPATELA;
            LIMPABUFFER;
            libera_Hash(&ha);
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

    return 1;
}
