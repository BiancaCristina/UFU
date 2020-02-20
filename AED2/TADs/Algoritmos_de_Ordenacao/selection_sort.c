#include <stdio.h>
#include <stdlib.h>

void selection_sort(int vetor[],int n){
    int i, iteracao, aux,menor;

    // CONTROLE DO NUMERO DE ITERACOES
    for (iteracao = 0;iteracao<n-1;iteracao++)
    {
        // BUSCA PELO MENOR ELEMENTO
        menor = iteracao;

        for (i= iteracao+1;i<n;i++)
        {
            if (vetor[i] < vetor[menor]) menor = i;

            // TROCA OS ELEMENTOS
            if (iteracao != menor){
                aux = vetor[iteracao];
                vetor[iteracao] = vetor[menor];
                vetor[menor] = aux;
            }
        }
    }
}
