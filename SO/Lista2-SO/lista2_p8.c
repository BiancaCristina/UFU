#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    pid_t p;
    int i;
    int s; // pro wait!
    p = fork();

    if (p > 0) {
        // p > 0 : processo pai
        wait(&s);
    }

    else if (p == 0) {
        // p == 0 : processo filho
        for(i=1;i<1000;i++){
            i++;
            printf("%d \n",i);
        }
        //printf("Processo filho!");

    }

    exit(0);
}