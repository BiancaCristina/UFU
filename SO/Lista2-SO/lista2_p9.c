#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    pid_t p1,p2;
    int i;
    int s;
    p1 = fork();

    if (p1 > 0 ){
        // Processo pai
        p2 = fork();

        if (p2 == 0) {
            // Segundo filho, imprime impares
            for(i=0;i<1000;i++) {
                i++;
                printf("%d \n", i);
            }
        }
    }

    else if (p1 == 0){
        for(i=1;i<1000;i++){
            // Primeiro filho, imprime pares
            i++;
            printf("%d \n", i);
        }
    }

    getchar();
    exit(0);
}