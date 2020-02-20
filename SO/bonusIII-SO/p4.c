#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>
#include "fila.h"
#define MEM_SZ 4096

/* Variaveis globais */
void* mem_f1_shared = (void*)0; // Variavel que recebe o retorno da shmat
int shmid_f1; // Variavel que recebe o retorno da shmget
void* mem_f2_shared = (void*)0; // Variavel que recebe o retorno da shmat
int shmid_f2; // Variavel que recebe o retorno da shmget
fila* f1;
fila* f2;
fila* f_temp; // Fila temporaria que sera utilizadas pelas threads 1 e 2
int canal[2]; 
int contador; // !!!!!!!!!!!!!!
int temp;
sem_t sem_thr; // SEMAFORO DAS THREADS


void* thread1 (void* p) {

}

void* thread2 (void* p) {
    

}

void trata_SIGINT (int sinal) {
    printf("Processo interrompido! Apagando os segmentos de memoria compartilhada...\n");

    shmdt(mem_f1_shared); 
    shmctl(shmid_f1, IPC_RMID,NULL);
    shmdt(mem_f2_shared); 
    shmctl(shmid_f2, IPC_RMID,NULL);
    
    while(!fila_vazia(&f_temp)) {
        remove_fila(&f_temp);
    }

    // DESTRUIR O SEMAFORO AQUI !!! 
	sem_destroy(&f1->sem1);
    sem_destroy(&f1->sem2);
	
    exit(0);
}

void trata_SIGUSR1 (int sinal) {
    printf("FAZENDO MINHAS COISINHAS...\n");
    sleep(3);

    sem_post(&f1->sem2);
	
}

int main() {
    int i;

    key_t key_f1 = 1234;
    key_t key_f2 = 7890;

    pid_t p5,p6;

    /* Comandos referentes a alocacao e criacao da fila F1, fila F2 e fila temporaria*/
    f1 = (fila*)malloc(sizeof(fila));
    f2 = (fila*)malloc(sizeof(fila));
    f_temp = (fila*)malloc(sizeof(fila));
    cria_fila(&f1);
    cria_fila(&f2);

    /* Comandos referentes a criacao/busca e acoplamento dos segmentos de memoria compartilhada F1, F2 e sem_4*/
    shmid_f1 = shmget(key_f1,MEM_SZ, 0666|IPC_CREAT);
    shmid_f2 = shmget(key_f2, MEM_SZ, 0666|IPC_CREAT);
    

    if (shmid_f1 == -1 || shmid_f2 == -1) {
        // Caso algum dos tres possua retorno == -1, entao houve algum erro na shmget
        printf("Erro ao utilizar shmget! \n");
        exit(-1);
    }

    mem_f1_shared = shmat(shmid_f1,(void*)0,0); 
    mem_f2_shared = shmat(shmid_f2,(void*)0,0);

    if (mem_f1_shared == (void*)-1 || mem_f2_shared == (void*)-1) {
        // Caso algum dos tres possua retorno == -1, entao houve algum erro na shmat
        printf("Erro ao utilizar shmat! \n");
        exit(-1);
    }

    f1 = (fila*) mem_f1_shared; // F1 recebe o endereco da area de memoria compartilhada correspondente
    f2 = (fila*) mem_f2_shared; // F2 recebe o endereco da area de memoria compartilhada correspondente
    
    /* Comandos referentes ao pipe do canal1 e canal2 */
    if (pipe(canal) < 0) {
        // Caso o pipe retorne um valor negativo, entao existe algum erro
        printf("Erro ao utilizar pipe! \n");
        exit(-1);
    }

    /* Inicia o semaforo */
	sem_init(&f1->sem1,1,1); // Inicializa o semaforo responsavel por controlar a comunicacao entre p1 e p4
    sem_init(&f1->sem2,1,0);
    sem_init(&sem_thr,0,1); // Inicializa o semaforo responsável por controlar as threads
	
    /* Trata sinal SIGINT */
    signal(SIGINT, trata_SIGINT);

    /* Trata sinal SIGUSR1 */
    while(1) {
        // O processo P4 permanecera nesse laco ate receber o sinal SIGUSR1
        signal(SIGUSR1, trata_SIGUSR1);
    }

    printf("Algum dia eu cheguei aqui, ce acredita?\n");

    /* Destroi o semaforo */
    sem_destroy(&f1->sem1);
    sem_destroy(&f1->sem2);
    sem_destroy(&sem_thr);

}
