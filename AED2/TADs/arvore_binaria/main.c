#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.h"

int main()
{
    Arvore aux = cria_arvore(3,NULL,NULL);
    Arvore aux1 = cria_arvore(4,NULL,NULL);
    Arvore aux2 = cria_arvore(1,aux1,NULL);
    Arvore b = cria_arvore(7,aux,aux2);

    exibe_arvore(b);
    printf("\n\nA altura da arvore b eh: %d", altura_arvore(b));
    printf("\n\nO no pai de %d eh %d", 4,busca_pai(b,4));

    return 1;
}
