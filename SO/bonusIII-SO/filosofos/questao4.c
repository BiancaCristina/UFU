/* QUESTAO 3) IMPLEMENTACAO SEM IMPASSES (BASEANDO-SE NA EXPLICACAO DE TANENBAUM)*/


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
sem_t semaforo; // Semaforo geral pro RC
sem_t sem_f[N]; // Semaforo pra cada filosofo (controla quando o garfo nao foi pego)

/* Declaracoes de funcao */
void verifica_vizinhos (int atual) {
    if (filosofo[atual] == FOME && filosofo[ESQUERDA] != COMENDO && filosofo[DIREITA] != COMENDO) {
        // Caso o filosofo atual esteja com fome e os vizinhos nao estao comendo
        filosofo[atual] = COMENDO;
        sem_post(&sem_f[atual]); // Libera o semaforo caso o atual comece a comer
    }
}

void libera_garfo (int atual) {
    sem_wait(&semaforo); // Bloqueia o acesso ao RC pras outras threads

        filosofo[atual] = PENSANDO; // Coloca o filosofo atual pra pensar
        verifica_vizinhos(ESQUERDA); // Verifica se o vizinho da ESQUERDA pode comer
        verifica_vizinhos(DIREITA); // Verifica se o vizinho da DIREITA pode comer

    sem_post(&semaforo); // Libera o acesso ao RC pras outras threads
}

void pega_garfo (int atual) {
    sem_wait(&semaforo); // Bloqueia o acesso ao RC pras outras threads

        filosofo[atual] = FOME; // Filosofo atual esta com fome
        verifica_vizinhos(atual); // Verifica os filosofos vizinhos ao vertice atual

        sem_post(&semaforo); // Libera o acesso ao RC pras outras threads

    sem_wait(&sem_f[atual]); // Bloqueia o filosofo atual caso ele nao tenha pegado os garfos
}


void* filosofos (void* p) {
    int* indice; // Recebe o "i" que indica qual filosofo estamos analisando no momento
    indice = (int*)p;
    int atual = indice;

    while(1) {
        filosofo[atual] = PENSANDO;

        printf("FILOSOFO %d\n", atual);

        pega_garfo(atual);
        
        if (filosofo[atual] == COMENDO && (filosofo[ESQUERDA] == COMENDO || filosofo[DIREITA] == COMENDO)) {
            printf("IMPASSE! \n");
            break;
        }

        libera_garfo(atual);
    }
}
/* Programa principal */
int main () {
    int i = 0;
    pthread_t thread[N];

    int x = 0;

    sem_init(&semaforo, 0, 1); // Inicia o semaforo entre threads
    
    for(i=0;i<5;i++) {
        sem_init(&sem_f[i], 0, 1);
    }

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

    for(i=0;i<5;i++) {
        sem_destroy(&sem_f[i]);
    }

    return 1;
}