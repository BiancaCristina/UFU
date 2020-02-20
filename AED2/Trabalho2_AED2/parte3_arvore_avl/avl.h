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
int arvore_vazia(Arvore* arv); // DETERMINA SE A �RVORE � VAZIA OU N�O
int altura_arvore(Arvore arv); // CALCULA ALTURA DA �RVORE
int calcula_fb (Arvore arv); // CALCULA O FB DE UMA �RVORE
int rot_dir(Arvore* pai); // ROTACIONA UMA �RVORE PRA DIREITA
int rota_esq(Arvore* pai); // ROTACIONA UMA �RVORE PRA ESQUERDA
int rot_dir_esq(Arvore* pai); // ROTACIONA UMA �RVORE PRA DIREITA-ESQUERDA
int rot_esq_dir(Arvore* pai); // ROTACIONA UMA �RVORE PRA ESQUERDA-DIREITA
void exibe_arvore (Arvore arv); // EXIBE AS CHAVES DA �RVORE
int insere_avl(Arvore* arv, Registro reg, int* bal); // INSERE EM UMA �RVORE AVL
void libera_arvore(Arvore* arv); // LIBERA �RVORE

/// FUN��ES DO TRABALHO
Registro* menor_trafego(Arvore arv); // RETORNA O PONTO DE REDE COM MENOR TR�FEGO
int qtde_ocioso(Arvore arv); // RETORNA A QUANTIDADE DE PONTOS OCIOSOS DA �RVORE
int eh_folha(Arvore arv); // VERIFICA SE UM N� � FOLHA OU N�O
int conta_filhos(Arvore arv); // CONTA QUANTIDADE DE FILHOS DE UMA �RVORE
int nro_derivacao(Arvore arv); // RETORNA O N�MERO DE DERIVA��O DE UMA �RVORE
int prof_arvore(Arvore arv); // DISPARA A FUN��O CALC_PROF_ARV
int calc_prof_arv(Arvore arv, int nivel); // CALCULA A PROF DE UMA �RVORE
int qtd_no_inter(Arvore arv); // CALCULA A QUANTIDADE DE N�S INTERMEDI�RIOS
int qtd_no_folha(Arvore arv); // CALCULA A QUANTIDADE DE N�S FOLHAS
int completa(Arvore arv); // FUNCAO QUE DISPARA O CALCULO QUE VERIFICA SE ARVORE EH COMPLETA OU NAO
int calc_completa(Arvore arv, int altura); // VERIFICA SE UMA �RVORE � COMPLETA OU N�O
int balanceada(Arvore arv); // VERIFICA SE UMA �RVORE � BALANCEADA OU N�O
int arvore_cheia(Arvore arv); // VERIFICA SE UMA �RVORE � CHEIA OU N�O
int nivel_no(Arvore A, Registro reg); // FUN��O QUE DISPARA A CALC_NIVEL_NO
int calc_prof_no(Arvore arv, Registro reg, int nivel); // FUN��O QUE CALCULA O N�VEL DO N�
int arvore_iguais(Arvore a, Arvore b); // VERIFICA SE DUAS �RVORES S�O IGUAIS
Registro* busca_bin_id (Arvore arv, char id[20]); // RETORNA UM REGISTRO � PARTIR DO NOME DO SEU IDENTIFICADOR
