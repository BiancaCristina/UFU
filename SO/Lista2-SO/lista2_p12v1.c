/*
    BIANCA CRISTINA DA SILVA
    11711BCC023
    QUESTAO 12), ALTERNATIVA A)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LINHA 500
#define COLUNA 500

int main() {
    
    int M[LINHA][COLUNA];
    int N[LINHA][COLUNA];
    int R[LINHA][COLUNA];
    
    register int i,j, aleatorio;
    register int l,c, C,L=0, soma=0, w=0, r=0;

    // Inicializando as matrizes M,N e R
    for(i=0;i<LINHA;i++) {
        for(j=0;j<COLUNA;j++){
            M[i][j]= rand() % 10;
            N[i][j]= rand() % 10;
            R[i][i]= 0;	
        }
    }

    // Computando M e N
    for (i=0;i<LINHA;i++){
        for (j=0;j<COLUNA;j++){
            M[i][j] = pow(M[i][j], 10);
            N[i][j] = pow(N[i][j], 10);
        }
    }

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
    real	0m0,910s
    user	0m0,324s
    sys	0m0,012s
    */

    getchar();
    return 1;
}