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
int T[LINHA][COLUNA];

int main() {
	register int i,j, aleatorio;
   	register int l,c, C,L=0, soma=0, w=0, r=0;
	
	char* url1 = (char*)malloc(150*sizeof(char));
	char* url2 = (char*)malloc(150*sizeof(char));

	url1 = "/home/bianca/Documentos/Faculdade/2018-2/SO/matrizN.bin";
	url2 = "/home/bianca/Documentos/Faculdade/2018-2/SO/matrizM.bin";

	int espera;
	pid_t p1,p2;
	
	
	// Inicializando as matrizes M,N e R
    	for(i=0;i<LINHA;i++) {
        	for(j=0;j<COLUNA;j++){
            		M[i][j]= rand()%9;
            		N[i][j]= rand()%9;
        	}
    	}

	p1 = fork(); // Cria o primeiro filho

	if (p1 > 0) { 
		// Processo pai
		
		p2 = fork();
		
		if (p2 == 0) {
			// Segundo filho
			FILE* matrizM;
			int tamanho_esc;
			size_t escritos;

			// Computando M
			for(i=0;i<LINHA;i++) {
				for(j=0;j<COLUNA;j++) {
					M[i][j] = pow(M[i][j],10);
				}
			}

			matrizM = fopen(url2,"wb");
			tamanho_esc = sizeof(M);

			if (matrizM == NULL) return -1;
			
			escritos = fwrite(M,1,tamanho_esc,matrizM);
			fclose(matrizM);
			
			
		}
		
		else if (p2 > 0) { 
			wait(&espera);
			wait(&espera);
			
			FILE* arq_l1;
			FILE* arq_l2;
			long tam_l1,tam_l2;
			size_t l1,l2;

			arq_l1 = fopen(url2, "rb");
			arq_l2 = fopen(url1, "rb");

			if (arq_l1 == NULL || arq_l2 == NULL) return -1;

			// Le o tamanho total do arquivo
			fseek(arq_l1,0,SEEK_END);
			tam_l1 = ftell(arq_l1);
			rewind(arq_l1);

			fseek(arq_l2,0,SEEK_END);
			tam_l2 = ftell(arq_l2);
			rewind(arq_l2);

			// Le o arquivo
			l1 = fread(M,1,tam_l1,arq_l1);
			l2 = fread(N,1,tam_l2,arq_l2);
			fclose(arq_l1);
			fclose(arq_l2);

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
		// Primeiro filho
		FILE* matrizN;
		int tamanho_esc;
		size_t escritos;
		
		// Computando N
		for(i=0;i<LINHA;i++) {
			for(j=0;j<COLUNA;j++) {
				N[i][j] = pow(N[i][j],10);
			}
		}
	
		matrizN = fopen(url1,"wb");
		tamanho_esc = sizeof(N);

		if(matrizN == NULL) return -1;
		
		escritos = fwrite(N,1,tamanho_esc,matrizN);
		fclose(matrizN);
		
	}

}