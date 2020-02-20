/*
    BIANCA CRISTINA DA SILVA
    11711BCC023
    QUESTAO 12), ALTERNATIVA C)
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#define LINHA 5000
#define COLUNA 5000
#define QTD_THREADS 2

int M[LINHA][COLUNA];
int N[LINHA][COLUNA];
int R[LINHA][COLUNA];

void * thread_primeira(void *);
void * thread_segunda (void *);

void * thread_primeira(void* ptr){
    register int i,j;
    
    for (i=0;i<LINHA;i++){
        for (j=0;j<COLUNA;j++){
            M[i][j] = M[i][j] * 10;
        }
    }
}

void * thread_segunda(void* ptr){
    register int i,j;

    for (i=0;i<LINHA;i++){
        for (j=0;j<COLUNA;j++){
            N[i][j] = N[i][j] * 10;
        }
    }
}

int main() {
    pthread_t tids[QTD_THREADS];
    register int i,j;
    register int l,c, C,L=0, soma=0, w=0, r=0;

    // Inicializando as matrizes M,N e R
    for(i=0;i<LINHA;i++) {
        for(j=0;j<COLUNA;j++){
            M[i][j]= 2;
            N[i][j]= 3;
            R[i][i]= 0;	
        }
    }

    /// Cria 2 threads
    pthread_create(&tids[0],NULL,thread_primeira,NULL);
    pthread_create(&tids[1],NULL,thread_segunda,NULL);

    // Aguarda as 2 threads terminarem de computar
    pthread_join(tids[0],NULL);
    pthread_join(tids[1],NULL);

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

    // Imprimindo R
    printf("\n\nMATRIZ R: \n");
    for (i=0;i<LINHA;i++){
        for (j=0;j<COLUNA;j++){
           printf("%d ",R[i][j]);
        }
        printf("\n");   
    }

    /*

    */

    //getchar();
    return 1;
}