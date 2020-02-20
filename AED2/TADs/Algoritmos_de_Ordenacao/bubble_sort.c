#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int vetor[],int n){
    int i,iteracao, aux;


    for (iteracao =0;iteracao < n-1;iteracao++) // CONTROLE DO NUMERO DE ITERACOES (N-1)
    {
        for(i=0;i<n-1;i++) // REPETICAO INTERNA PERCORRIMENTO DO VETOR (N-1)
        {
            if (vetor[i] > vetor [i+1]) // TROCA CASO NECESSARIO
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }
}

void bubble_sort2 (int vetor[],int n){
    int i, iteracao, aux,troca;

    for (iteracao = n-1;iteracao > 0;iteracao--)
    {
        troca = 0;

        for (i=0;i<iteracao;i++)

            if (vetor[i] > vetor [i+1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;

                troca = 1;
            }

        if (troca==0) break;

    }
}
