typedef struct Registro Registro;
typedef struct no* Arvore;

struct Registro{
    char identificador[20]; // NOME DO PONTO DE REDE
    char localizacao[20]; // COORDENADAS LAT E LONG
    int capacidade; // CAPACIDADE DO PONTO DE REDE
    int trafego; // CAMPO CHAVE
};

/// ARVORE AVL
Arvore cria_vazia ();
int arvore_vazia(Arvore* arv); // DETERMINA SE A ÁRVORE É VAZIA OU NÃO
int altura_arvore(Arvore arv); // CALCULA ALTURA DA ÁRVORE
int calcula_fb (Arvore arv); // CALCULA O FB DE UMA ÁRVORE
int rot_dir(Arvore* pai); // ROTACIONA UMA ÁRVORE PRA DIREITA
int rota_esq(Arvore* pai); // ROTACIONA UMA ÁRVORE PRA ESQUERDA
int rot_dir_esq(Arvore* pai); // ROTACIONA UMA ÁRVORE PRA DIREITA-ESQUERDA
int rot_esq_dir(Arvore* pai); // ROTACIONA UMA ÁRVORE PRA ESQUERDA-DIREITA
void exibe_arvore (Arvore arv); // EXIBE AS CHAVES DA ÁRVORE
int insere_avl(Arvore* arv, Registro reg, int* bal); // INSERE EM UMA ÁRVORE AVL
void libera_arvore(Arvore* arv); // LIBERA ÁRVORE

/// FUNÇÕES DO TRABALHO
Registro* menor_trafego(Arvore arv); // RETORNA O PONTO DE REDE COM MENOR TRÁFEGO
int qtde_ocioso(Arvore arv); // RETORNA A QUANTIDADE DE PONTOS OCIOSOS DA ÁRVORE
int eh_folha(Arvore arv); // VERIFICA SE UM NÓ É FOLHA OU NÃO
int conta_filhos(Arvore arv); // CONTA QUANTIDADE DE FILHOS DE UMA ÁRVORE
int nro_derivacao(Arvore arv); // RETORNA O NÚMERO DE DERIVAÇÃO DE UMA ÁRVORE
int prof_arvore(Arvore arv); // DISPARA A FUNÇÃO CALC_PROF_ARV
int calc_prof_arv(Arvore arv, int nivel); // CALCULA A PROF DE UMA ÁRVORE
int qtd_no_inter(Arvore arv); // CALCULA A QUANTIDADE DE NÓS INTERMEDIÁRIOS
int qtd_no_folha(Arvore arv); // CALCULA A QUANTIDADE DE NÓS FOLHAS
int completa(Arvore arv); // FUNCAO QUE DISPARA O CALCULO QUE VERIFICA SE ARVORE EH COMPLETA OU NAO
int calc_completa(Arvore arv, int altura); // VERIFICA SE UMA ÁRVORE É COMPLETA OU NÃO
int balanceada(Arvore arv); // VERIFICA SE UMA ÁRVORE É BALANCEADA OU NÃO
int arvore_cheia(Arvore arv); // VERIFICA SE UMA ÁRVORE É CHEIA OU NÃO
int nivel_no(Arvore A, Registro reg); // FUNÇÃO QUE DISPARA A CALC_NIVEL_NO
int calc_prof_no(Arvore arv, Registro reg, int nivel); // FUNÇÃO QUE CALCULA O NÍVEL DO NÓ
int arvore_iguais(Arvore a, Arvore b); // VERIFICA SE DUAS ÁRVORES SÃO IGUAIS
Registro* busca_bin_id (Arvore arv, char id[20]); // RETORNA UM REGISTRO À PARTIR DO NOME DO SEU IDENTIFICADOR
