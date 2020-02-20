typedef struct Registro Registro;

struct Registro{
    char nome[20];
    int idade; // CAMPO CHAVE
    char curso[20];
};

typedef struct no* Arvore;

Arvore cria_vazia (); // CRIA ÁRVORE
int arvore_vazia(Arvore* arv); // VERIFICA SE ÁRVORE É VAZIA
void libera_arvore(Arvore* arv); // LIBERA TODA A ÁRVORE
void exibe_arvore (Arvore arv); // EXIBE A ÁRVORE
void exibe_ordenado (Arvore arv); // EXIBE A ÁRVORE DE FORMA ORDENADA
int insere_ordenado(Arvore* arv, Registro reg); // INSERE ORDENADO NA ÁRVORE
int remove_ordenado(Arvore* arv, int idade); // REMOVE ORDENADO NA ÁRVORE
Arvore busca_bin (Arvore arv, int idade); // BUSCA UMA IDADE ESPECÍFICA NA ÁRVORE

/// FUNCOES DO TRABALHO
Registro* maior(Arvore arv); // RETORNA O REGISTRO DO ALUNO MAIS VELHO
int de_maior(Arvore arv); // RETORNA A QUANTIDADE DE ALUNOS QUE SÃO MAIORES DE IDADE
int qtd_alunos(Arvore arv, int inicial, int fim); // FUNÇÃO QUE CALCULA A QUANTIDADE DE ALUNOS EM UM INTERVALO
int conta_filhos(Arvore arv); // FUNCAO AUXILIAR DA  UM FILHO E COMPLETA
int um_filho(Arvore arv); // VERIFICA QUANTOS NÓS DA ÁRVORE POSSUI APENAS UM FILHO
int eh_folha(Arvore arv); // FUNCAO AUXILIAR DA COMPLETA
int prof_no(Arvore arv, int chave); // FUNCAO AUXILIAR DA COMPLETA -> ESSA FUNCAO DISPARA A FUNCAO CALC_PROF_NO
int calc_prof_no(Arvore arv, int chave, int nivel); // FUNCAO AUXILIAR DA COMPLETA -> CALCULA PROF DO NO
int prof_arvore(Arvore arv); // FUNCAO AUXILIAR DA COMPLETA -> DISPARA A FUNCAO CALC_PROF_ARV
int calc_prof_arv(Arvore arv, int nivel); // FUNCAO AUXILIAR DA COMPLETA -> CALCULA A PROF DE UMA ARVORE
int qtd_no_inter(Arvore arv); // CALCULA A QUANTIDADE DE NÓS INTERMEDIÁRIOS DA ÁRVORE
int qtd_no_folha(Arvore arv); // CALCULA A QUANTDADE DE NÓS FOLHA DA ÁRVORE
int completa(Arvore arv); // FUNCAO QUE DISPARA O CALCULO QUE VERIFICA SE ARVORE EH COMPLETA OU NAO
int calc_completa(Arvore arv, int altura); // VERIFICA SE UMA ÁRVORE É COMPLETA OU NÃO
int altura_arvore(Arvore arv); // CALCULA ALTURA DA ÁRVORE
Arvore concatena(Arvore a, Arvore b); // FUNCAO AUXILIAR DA JUNTAR
Arvore juntar (Arvore a, Arvore b); // CONCATENA DUAS ÁRVORES



