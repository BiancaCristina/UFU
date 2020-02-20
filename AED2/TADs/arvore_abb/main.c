#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main()
{
    Arvore arv = cria_vazia();
    Registro a;
        a.chave = 2323; //
        a.idade = 10;

    Registro b;
        b.chave = 1021;
        b.idade = 12;

    Registro c; //
        c.chave = 1500;
        c.idade = 20;

    Registro d;
        d.chave = 1700;
        d.idade = 20;

    Registro f;
        f.chave = 900;
        f.idade = 20;

    Registro g;
        g.chave = 344;
        g.idade = 20;

    Registro h;
        h.chave = 1000;
        h.idade = 20;

    Registro i; //
        i.chave = 1600;
        i.idade = 20;

    insere_ordenado(&arv,d);
    insere_ordenado(&arv,g);
    insere_ordenado(&arv,a);
    insere_ordenado(&arv,f);
    insere_ordenado(&arv,i);
    insere_ordenado(&arv,h);
    insere_ordenado(&arv,c);

    // EXIBE ARVORE
    exibe_arvore(arv);

    libera_arvore(&arv);
    return 0;
}
