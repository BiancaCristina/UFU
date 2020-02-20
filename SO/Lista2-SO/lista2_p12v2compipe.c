/*
    BIANCA CRISTINA DA SILVA
    11711BCC023
    QUESTAO 12), ALTERNATIVA B)
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define LINHA 5000
#define COLUNA 5000

int M[LINHA][COLUNA];
int N[LINHA][COLUNA];
int R[LINHA][COLUNA];

int main(){   
    register int i,j, aleatorio;
    register int l,c, C,L=0, soma=0, w=0, r=0;

    int espera;
    pid_t p1,p2;
    int fd[2]; // File descriptors pro pipe entre Pai e Segundo filho
    int fd2[2]; // File descriptors pro pipe entre Pai e Primeiro filho

    // Inicializando as matrizes M,N e R
    for(i=0;i<LINHA;i++) {
        for(j=0;j<COLUNA;j++){
            M[i][j]= 2;
            N[i][j]= 3;
            R[i][i]= 0;	
        }
    }

    if (pipe(fd) < 0) {
        // Caso o pipe seja < 0, entao tem algum erro, retorna -1
        return -1;
    }

    if (pipe(fd2) < 0) {
        // Caso o pipe seja < 0, entao tem algum erro, retorna -1
        return -1;
    }
    
    p1 = fork(); // Cria o primeiro filho

    if (p1 > 0) {
        // Processo pai

        p2 = fork();

        if (p2 == 0) {
            // Segundo processo filho

            // Farei a escrita no filho, entao fecho fd[0] aqui
            close(fd[0]);

            // Computando N
            for (i=0;i<LINHA;i++){
                for (j=0;j<COLUNA;j++){
                    N[i][j] = N[i][j] * 10;
                }
            }

            // Escrevendo a matriz no pipe
            write(fd[1], N, sizeof(N));
            exit(0);
        }

        else if (p2 > 0) {
            // Processo pai
            wait(&espera);
            wait(&espera);

            // A leitura sera feita no pai, entao fecho fd[1] aqui
            close(fd[1]);

            // Lendo o que foi escrito no pipe e armazenando em N
            read(fd[0], N, sizeof(N));

            // A leitura sera feita no pai, entao fecho fd2[1] aqui
            close(fd[1]);

            // Lendo o que foi escrito no pipe e armazenando em M
            read(fd2[0], M,sizeof(M));

            printf("\n\nMATRIZ MxN: \n");
            for(l=0;l<LINHA;l++){
                for(C=0;C<COLUNA;C++) { 
                    for(c=0; c<LINHA; c++) {   
                        soma = soma + M[l][c] * N[L][C];
                        L++;
                    }
                    R[l][C]=soma;
                    L=0;
                    soma=0;
                    w++;
                }      
            }

            for (i=0;i<LINHA;i++){
                for (j=0;j<COLUNA;j++){
                    printf("%d ",R[i][j]);
                }      
                printf("\n");   
            }

        } 
    }

    else if (p1 == 0) {
        // Primeiro processo filho

        // Farei a escrita no filho, entao fecho fd2[0] aqui
        close(fd2[0]);

        // Computando M
        for (i=0;i<LINHA;i++){
            for (j=0;j<COLUNA;j++){
                M[i][j] = M[i][j] * 10;
            }
        }

        // Escrevendo a matriz no pipe
        write(fd2[1], M,sizeof(M));
        exit(0);
    }

    /*

    */

    //getchar();
    return 1;

}