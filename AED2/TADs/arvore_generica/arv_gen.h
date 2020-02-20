typedef struct no* Arvore;

Arvore cria_arvore(int info);
int insere(Arvore arv, Arvore sa);
void exibe_arvore(Arvore arv);
int busca(Arvore arv, int info);
void libera_arvore(Arvore* arv);
int altura_arvore(Arvore arv);
int arvore_vazia(Arvore* arv);

void imprime_preordem(Arvore arv);
void percorre_nivel(Arvore arv);
