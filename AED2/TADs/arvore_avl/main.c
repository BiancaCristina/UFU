#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main()
{
    int bal;
    Arvore arv = cria_vazia();

    /// POSSIVEL PROBLEMA NA HORA DE IDENTIFICAR QUANDO DEVE ROTACIONAR!

    Registro a; // USA MENOS DA METADE
        a.chave = 2323;
        //a.capacidade = 5000;

    Registro b; // USA MAIS QUE A METADE
        b.chave = 1021;
        //b.capacidade = 1500;

    Registro c; // USA MENOS QUE A METADE
        c.chave = 1500; ///
        //c.capacidade = 3100;

    Registro d; // USA MAIS QUE A METADE
        d.chave = 1700;
        //d.capacidade = 2000;

    Registro e;
        e.chave = 500;
        //e.capacidade = 800;

    Registro f; // USA MAIS QUE A METADE
        f.chave = 900;
        //f.capacidade = 1300;

    Registro g; // USA MAIS QUE A METADE
        g.chave = 3440;
        //g.capacidade = 4000;

    Registro h;
        h.chave = 5000;
        //h.capacidade = 9000;

    Registro i;
        i.chave = 1000;
        //i.capacidade = 2500;

    Registro j;
        j.chave = 2000;
        //j.capacidade = 2500;

    Registro k;
        k.chave = 10;
        //k.capacidade = 15;

    // INSERE
    insere_avl(&arv,a,&bal);
    insere_avl(&arv,b,&bal);


    // EXIBE
    exibe_arvore(arv);
    printf("\nNIVEL = %d", nivel_no(arv,b));
    // BUSCA BINARIA
    printf("\n");
    //exibe_arvore(busca_bin(arv,2323));
    libera_arvore(&arv);
    return 0;
}
