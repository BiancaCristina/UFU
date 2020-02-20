#include <stdio.h>
#include <stdlib.h>
#include "pilhadinamica.h"
int main()
{
    pilha* p = cria_pilha();

    // FAZER FATORIAL COM PILHA
    int n,fat=1,atual;
    scanf("%d", &n);

    insere_pilha(p,n);

    while (!vazia_pilha(p)){
        atual = remove_v2(p);
        fat *= atual;

        n--;
        if (n != 1) insere_pilha(p,n);
    }

    printf("FATORIAL = %d", fat);
    return 0;
}
