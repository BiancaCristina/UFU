#include <stdio.h>
#include <stdlib.h>
#include "arv_gen.h"

int main()
{
    // CRIACAO DOS NOS RAIZES DAS SUBARVORES
    Arvore a = cria_arvore(1);
    Arvore b = cria_arvore(2);
    Arvore c = cria_arvore(3);
    Arvore d = cria_arvore(4);
    Arvore e = cria_arvore(5);
    Arvore f = cria_arvore(6);
    Arvore g = cria_arvore(7);
    Arvore h = cria_arvore(8);
    Arvore i = cria_arvore(9);

    // MONTAGEM DA ARVORE

    insere(f,i);
    insere(f,h);
    insere(c,f);
    insere(c,e);
    insere(d,g);
    insere(a,d);
    insere(a,c);
    insere(a,b);

    // EXIBE ARVORE
    exibe_arvore(a);
    printf("\n");
    ///imprime_preordem(a);
    ///printf("\n");
    percorre_nivel(a);
    // ALTURA DA ARVORE
    printf("\nA altura da arvore eh %d\n", altura_arvore(a));

    // BUSCA NA ARVORE
    busca(a,798); // VAI RETORNAR 0!
    busca(a,7); // VAI RETORNAR 1
    return 1;
}
