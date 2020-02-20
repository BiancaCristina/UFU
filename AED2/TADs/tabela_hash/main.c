#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int main()
{
    Hash* ha = cria_Hash(1427);

    Aluno a;
        a.matricula = 112;

    Aluno b;
        b.matricula = 232;

    Aluno c;
        c.matricula = 114;

    Aluno d;
        d.matricula = 500;

    Aluno aux;

    // INSERE SC
    insere_Hash_SC(ha,a);
    insere_Hash_SC(ha,b);
    insere_Hash_SC(ha,c);
    insere_Hash_SC(ha,d);

    // BUSCA SC
    busca_Hash_SC(ha, 114, &aux);
    libera_Hash(ha);

    return 0;
}
