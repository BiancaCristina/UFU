#include <stdio.h>
#include <stdlib.h>

int quick_sort (int a[],int inicial,int fim)   // inicial = p, fim = r
{
    int t; // EH UMA VARIAVEL AUXILIAR PRA TROCAR

    if (inicial < fim)
    {
        int v = (rand() % (fim - inicial)) + inicial;
        int pivo = a[v];
        a[v] = a[fim];
        a[fim] = pivo; // OPCIONAL
        int i= inicial - 1;
        int j= fim;


        do
        {
            do
            {
                i++;
            }
            while (a[i] < pivo);
            do
            {
                j--;
            }
            while ((a[j] > pivo) && (j>inicial));

            if (i < j)
            { // TROCA I COM J
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }

        }
        while (i<j);

        a[fim] = a[i];
        a[i] = pivo;

        // CHAMADAS RECURSIVAS:
        quick_sort(a,inicial,i-1);
        quick_sort(a,i+1,fim);

    }

    //return *a;

}

