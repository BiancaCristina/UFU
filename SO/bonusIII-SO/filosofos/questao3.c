/* QUESTAO 3) IMPLEMENTACAO USANDO SEMAFORO (BASEANDO-SE NA EXPLICACAO DE TANENBAUM) */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define N 5
#define ESQUERDA ((atual+N-1)%N)
#define DIREITA ((atual+1)%N)
#define PENSANDO 0
#define FOME 1
#define COMENDO 2
#define OCUPADO 3
#define LIVRE 4

/* Variaveis globais */
int filosofo[N];
int garfo[N];
sem_t semaforo;
/* Declaracao de funcoes */

void pega_garfo(int atual) {
    filosofo[atual] = FOME;

    while (filosofo[ESQUERDA] == COMENDO);

    garfo[ESQUERDA] = OCUPADO;

    while(filosofo[DIREITA] == COMENDO);
    
    garfo[DIREITA] = OCUPADO;

    filosofo[atual] = COMENDO;
}

void libera_garfo (int atual) {
    garfo[ESQUERDA] = LIVRE;
    garfo[DIREITA] = LIVRE;
}

void* filosofos (void* p) {
    int* indice; // Recebe o "i" que indica qual filosofo estamos analisando no momento
    indice = (int*)p;
    int atual = indice;

    while(1) {
        sem_wait(&semaforo);
        printf("FILOSOFO %d\n", atual);
        pega_garfo(atual);

        if (filosofo[atual] == COMENDO && (filosofo[ESQUERDA] == COMENDO || filosofo[DIREITA] == COMENDO)) {
            printf("IMPASSE! \n");
            break;
        }

        libera_garfo(atual);
        sem_post(&semaforo);
    }

}

/* Programa principal */
int main () {
    int i = 0;
    pthread_t thread[N];

    int x = 0;

    sem_init(&semaforo, 0, 1); // Inicia o semaforo entre threads

    pthread_create(&thread[0], NULL, filosofos, (void*)0);
    pthread_create(&thread[1], NULL, filosofos, (void*)1);
    pthread_create(&thread[2], NULL, filosofos, (void*)2);
    pthread_create(&thread[3], NULL, filosofos, (void*)3);
    pthread_create(&thread[4], NULL, filosofos, (void*)4);
    
    
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL); 
    pthread_join(thread[2], NULL); 
    pthread_join(thread[3], NULL);
    pthread_join(thread[4], NULL);
    
    sem_destroy(&semaforo); // Destroi o semaforo 

    return 1;
}
