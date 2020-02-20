typedef struct Registro Registro;
typedef struct no* Arvore;

struct Registro{
    int chave;
    char nome[100];
    int idade;
};

Arvore cria_vazia ();
int arvore_vazia(Arvore* arv);
int altura_arvore(Arvore arv);
int calcula_fb (Arvore arv);
int rot_dir(Arvore* pai);
int rota_esq(Arvore* pai);
int rot_dir_esq(Arvore* pai);
int rot_esq_dir(Arvore* pai);
void exibe_arvore (Arvore arv);
int insere_avl(Arvore* arv, Registro reg, int* bal);
void libera_arvore(Arvore* arv);
Arvore busca_bin (Arvore arv, int chave);

int nivel_no(Arvore A, Registro reg); /// CONFERIR! -> FUNÇÃO QUE DISPARA A CALC_NIVEL_NO
int calc_prof_no(Arvore arv, Registro reg, int nivel); // FUNÇÃO QUE CALCULA O NÍVEL DO NÓ
