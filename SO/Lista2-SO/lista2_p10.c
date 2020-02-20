#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    pid_t p[50];
    int i,s;

    for(i=0;i<50;++i){
        p[i] = fork();
        if (p[i]==0) {
            printf("Pid_pai = %d, Pid_filho = %d\n", p,getpid());
            break;        }
    }

    //printf("Eai\n");
    getchar();
    //exit(0);
}