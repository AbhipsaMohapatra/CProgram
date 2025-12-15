#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <semaphore.h>

int main(){
    char s1[] = "I am a parent";
    char s2[] = "I am the child ...I am using semaphore";
    sem_t s;
    int i=0;
    if( sem_init(&s,0,1)<0){
        perror("Some error occured");
        exit(0);
    }


    pid_t childpid ;
    childpid = fork();

    if(childpid<0){
        perror("Fork failed \n");
        exit(1);
    }

    if(childpid ==0 ){
        sem_wait(&s);
        while(s2[i]){
            fprintf(stderr,"%c",s2[i++]);
           // sleep(1);
        }
        sem_post(&s);
        exit(0);
    }
    sem_wait(&s);
    while(s1[i]){
            fprintf(stderr,"%c",s1[i++]);
            //sleep(1);
    }
    sem_post(&s);
    wait(NULL);
    return 0;


}
