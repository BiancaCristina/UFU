#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    pid_t pid;
    int status;
    pid = fork();

    if ( pid == 0 ) {
        printf("PROCESSO FILHO! ");
        getchar();
    }

    else if (pid > 0 ) {
        printf("PROCESSO PAI!");
        wait(&status);
    }

    exit(1);
}