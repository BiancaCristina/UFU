#include <semaphore.h>
#define MAX 10

typedef struct fila {
	sem_t sem1; // Semaforo que controla os processo p1 e p4
	sem_t sem2; // Semaforo que controla os processos p5 e p6
    int tamanho,inicio,fim, busywait;
    int dados[MAX];
} fila;

fila** cria_fila (fila** fi);
int insere_fila(fila** fi, int i);
int remove_fila(fila** fi);
int remove_especifico(fila** fi);
void exibe_fila(fila** fi);
int fila_cheia(fila** fi);
int fila_vazia(fila** fi);
