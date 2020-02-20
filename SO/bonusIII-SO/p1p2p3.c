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
#include <semaphore.h>
#include "fila.h"
#define MEM_SZ 4096

/* Variaveis globais */
key_t key_f1 = 1234; // Variavel que guarda a chave da fila F1
key_t key_sem3 = 4567; // Variavel que guarda a chave do semaforo sem3
void* mem_f1_shared = (void*)0; // Variavel que recebe o retorno da shmat
int shmid_f1; // Variavel que recebe o retorno da shmget
fila* f1; // Fila 1 (F1)
int p4 = 17819; // Variavel que guarda PID do processo P4
int elemento = 1; // TEMPORAAAAAAAAAAAARIO !!!!
int contador;

void trata_SIGINT (int sinal) {
    printf("Processo interrompido! Apagando os segmentos de memoria compartilhada...\n");

    shmdt(mem_f1_shared); 
    shmctl(shmid_f1, IPC_RMID,NULL);

    // DESTRUIR O SEMAFORO AQUI!!!!!!
    sem_destroy(&f1->sem1);
    sem_destroy(&f1->sem2);
    exit(0);
}

void insere (int i) {
    int sval;
    int sval2;
    int sval3;
    int sval4;

    while(1) {
        
        sem_wait(&f1->sem1);
        /*
        sval = sem_getvalue(&f1->sem1, &sval3);
        printf("3- SEM1: %d\n", sval3);
        printf("TO BLOQUEADAO! \n");
        */

        
            f1->busywait++;
            printf("SINAL ENVIADO... BW = %d\n", f1->busywait);
            kill(p4, SIGUSR1);
            sem_wait(&f1->sem2);   
      

        sem_post(&f1->sem1);
    }
    
}

int main() {
    int i;
    int aleatorio = 3;

    pid_t p1, p2;

    /* Comandos referentes a alocacao e criacao da fila F1 */
    f1 = (fila*)malloc(sizeof(fila));
    cria_fila(&f1);

    /* Comandos referentes a criacao/busca e acoplamento do segmento de memoria compartilhada (F1) */
    shmid_f1 = shmget(key_f1, MEM_SZ, 0666|IPC_CREAT);

    if (shmid_f1 == -1) {
        // Caso seja == -1, houve algum erro no shmget
        printf("Erro ao utilizar shmget! \n");
        exit(-1);
    }

    mem_f1_shared = shmat(shmid_f1, (void*)0,0); 

    if (mem_f1_shared == (void*)-1) {
        // Caso seja == -1, houve algum erro na shmat
        printf("Erro ao utilizar shmat! \n");
        exit(-1);
    }

    f1 = (fila*) mem_f1_shared; // F1 recebe o endereco da area de memoria compartilhada
    

    /* Cria o semaforo */   

    /* Trata sinal de interrupcao */
    signal(SIGINT, trata_SIGINT);

    /* Preenche F1 */
    p1 = fork();
    
    if (p1 > 0) {
    	// P1
    	
    	p2 = fork();
    	
    	if (p2 == 0) {
    		// P3
    		while(1) insere(3);
    	}
    	
    	else if (p2 > 0) {
    		// P1
    		while (1) insere(1);
    	}
    }
    
    else if (p1 == 0) {
    	// P2
    	while (1) insere(1);
    } 

    /* Destroi o semaforo */
 
    
}
