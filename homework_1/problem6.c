#include <pthread.h>
#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>

int value = 0;
void *runner(void *params); // the thread

int main(int argc, char *argv[]){
    pid_t pid;
    pthread_t tid;
    pthread_attr_t attr;

    pid = fork();

    if (pid == 0){ // child process
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, NULL);
        pthread_join(tid, NULL);
        printf("CHILD: value = %d \n", value); // Line C
    }

    else if (pid > 0){ // parent process
        wait(NULL);
        printf("PARENT: value = %d \n", value); // Line P
    }
}

void *runner(void *params){
    value = 5;
    pthread_exit(0);
}