#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
 pid_t pids[2];
 int i;

 for(i=0; i < 2; i++ ){ pids[i] = fork(); }
 
 getchar();

}
