typedef struct no* Arvore;

Arvore cria_vazia ();
Arvore cria_arvore(int info, Arvore sad, Arvore sae);
int arvore_vazia (Arvore arv);
void libera_arvore (Arvore* arv);
int busca_arvore (Arvore arv, int info);
int remove_folha (Arvore* arv, int info);
void exibe_arvore (Arvore arv);
int altura_arvore (Arvore arv);
int busca_pai (Arvore arv, int info);
