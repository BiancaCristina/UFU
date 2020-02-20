#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void intercala(int *vetor, int ini,int meio,int fim)
{
    int p1 = ini,p2 = meio+1,fim1=0,fim2=0;
    int tamanho = fim - ini + 1;
    int* vaux = (int*)malloc(tamanho*sizeof(int));

    if (vaux != NULL)
{
    int i,j,k;

    for (i=0; i<tamanho; i++)
            if (!fim1 && !fim2)
            {
                if (vetor[p1] < vetor[p2]) vaux[i] = vetor[p1++];
                else vaux[i]= vetor[p2++];
                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;
            }

            else
            {
                if (!fim1) vaux[i] = vetor[p2++];
                else vaux[i] = vetor[p1++];


            }

        // COPIA VETOR AUX PARA O ORIGINAL
        //for(j=0; k=ini; j<tamanho; j++; k++) vetor[k] = vaux[i];

        }

        free(vaux);

}
void merge_sort (int vetor[],int ini,int fim)
{
    if (ini < fim) {
        int meio = floor((ini+fim)/2);

        merge_sort(vetor,ini,meio);
        merge_sort(vetor,meio+1,fim);

        intercala(vetor,ini,meio,fim);
    }
}


