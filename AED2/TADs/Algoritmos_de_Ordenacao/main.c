#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include <windows.h>

void mede_tempo_bubble (int vetor[],int n) {
     __int64 freq,start,stop;

    double tempo;

    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

    QueryPerformanceCounter((LARGE_INTEGER *)&start);

    // FUNCAO DEVE VIR AQUI!
    bubble_sort(vetor,n);

    QueryPerformanceCounter((LARGE_INTEGER *)&stop);

    //tempo = ((double)stop-(double)start) / (double)freq; // USAR ASSIM PRO ITERATIVO
    tempo = ((double)stop-(double)start) / (double)CLOCKS_PER_SEC; // USAR ASSIM PRO RECURSIVO

    printf("TEMPO = %.50f", tempo);

}

void mede_tempo_selection(int vetor[],int n) {
     __int64 freq,start,stop;

    double tempo;

    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

    QueryPerformanceCounter((LARGE_INTEGER *)&start);

    // FUNCAO DEVE VIR AQUI!
    selection_sort(vetor,n);

    QueryPerformanceCounter((LARGE_INTEGER *)&stop);

    //tempo = ((double)stop-(double)start) / (double)freq; // USAR ASSIM PRO ITERATIVO
    tempo = ((double)stop-(double)start) / (double)CLOCKS_PER_SEC; // USAR ASSIM PRO RECURSIVO

    printf("TEMPO = %.50f", tempo);
}

void mede_tempo_insertion(int vetor[],int n) {
     __int64 freq,start,stop;

    double tempo;

    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

    QueryPerformanceCounter((LARGE_INTEGER *)&start);

    // FUNCAO DEVE VIR AQUI!
    insertion_sort(vetor,n);

    QueryPerformanceCounter((LARGE_INTEGER *)&stop);

    //tempo = ((double)stop-(double)start) / (double)freq; // USAR ASSIM PRO ITERATIVO
    tempo = ((double)stop-(double)start) / (double)CLOCKS_PER_SEC; // USAR ASSIM PRO RECURSIVO

    printf("TEMPO = %.50f", tempo);
}

void mede_tempo_quick(int a[],int inicial,int fim){
     __int64 freq,start,stop;

    double tempo;

    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

    QueryPerformanceCounter((LARGE_INTEGER *)&start);

    // FUNCAO DEVE VIR AQUI!
    quick_sort(a,a[0],a[4]);

    QueryPerformanceCounter((LARGE_INTEGER *)&stop);

    //tempo = ((double)stop-(double)start) / (double)freq; // USAR ASSIM PRO ITERATIVO
    tempo = ((double)stop-(double)start) / (double)CLOCKS_PER_SEC; // USAR ASSIM PRO RECURSIVO

    printf("TEMPO = %.50f", tempo);
}

void imprime (int vetor[], int n)
{
    int i;

    printf("VETOR ORDENADO:[");
    for (i=0; i<n; i++)
    {
        if (i== n-1) printf("%d", vetor[i]);
        else printf("%d, ", vetor[i]);
    }

    printf("]");
}

void imprimeini (int vetor[],int n)
{
    int i;

    printf("VETOR ANTES DE ORDENAR:[");
    for (i=0; i<n; i++)
    {
        if (i== n-1) printf("%d", vetor[i]);
        else printf("%d, ", vetor[i]);
    }

    printf("]");

}

int* cria_preenche (int vetor[],int n)
{
    int i;

    srand( (unsigned)time(NULL) );

    for (i = 0; i<n; i++)
    {
        vetor[i] = 0+ (rand() % 20);
    }

    return vetor;

}
int main()
{
    int n = 10000;

    int* vetor = (int*)malloc(n*sizeof(int));
    int* vetor2 = (int*)malloc(n*sizeof(int));
    int* vetor3 = (int*)malloc(n*sizeof(int));
    int* vetor4 = (int*)malloc(n*sizeof(int));
    int* vetor5 = (int*)malloc(n*sizeof(int));

    vetor= cria_preenche(vetor,n);
    vetor2= cria_preenche(vetor2,n);
    vetor3= cria_preenche(vetor3,n);
    vetor4= cria_preenche(vetor4,n);
    vetor5 = cria_preenche(vetor5,n);

    //BUBBLE SORT
    //imprimeini(vetor2,n);
    printf("\n");
    //bubble_sort(vetor2,n);
    mede_tempo_bubble(vetor2,n);
    printf("\n");
    //imprime(vetor2,n);
    printf("\n\n");

    //SELECTION SORT
    //imprimeini(vetor,n);
    printf("\n");
    //selection_sort(vetor,n); // PROBLEMAS NESSA FUNCAO AQUI!
    mede_tempo_selection(vetor,n);
    printf("\n");
    //imprime(vetor,n);
    printf("\n\n");

    //INSERTION SORT
    //imprimeini(vetor3,n);
    printf("\n");
    //insertion_sort(vetor3,n);
    mede_tempo_insertion(vetor3,n);
    printf("\n");
    //imprime(vetor3,n);
    printf("\n\n");

    // QUICK SORT -> PROBLEMA AQUI!!!
    /*imprimeini(vetor4,n);
    printf("\n");
    quick_sort(vetor,vetor[0],vetor[4]);
    imprime(vetor4,n);
    printf("\n\n");*/

    // MERGE SORT:

    // MEDINDO OS TEMPOS:


    //LIBERA VETOR
    free(vetor);
    free(vetor2);
    free(vetor3);
    free(vetor4);
    free(vetor5);
    return 0;
}
