#include <stdlib.h>
#include <stdio.h>

void insertion_sort(int vetor[],int n){
    int i,iteracao,aux,elem;

    // CONTROLE DO NUMERO DE ITERACOES
    for(iteracao = 1;iteracao < n;iteracao++)
        {
            //BUSCA POSICAO DO ELEMENTO
            elem = vetor[iteracao];
            i= iteracao-1;

            while (i>=0 && vetor[i] > elem)
            {
                vetor[i+1] = vetor[i];
                i--;
            }

            vetor[i+1]= elem;
        }
}
