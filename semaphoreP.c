#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <threads.h>
sem_t s1,s2;


int main(){
    
    sem_init(&s1,1,1);
    sem_init(&s2,1,0);
    pid_t c;
    c=fork();
    if(c==0){
       int i=0;
     while(i<100){
        sem_wait(&s1);
        printf("1 ");
        printf("1 ");
        i++;

        sem_post(&s2);
        
      }
      
    }
    else{
      wait(NULL);
       int i=0;
       while(i<100){
        sem_wait(&s2);
        printf("0 ");
        printf("0 ");
        i++;
        sem_post(&s1);
        

      }
       
    }
    sem_destroy(&s1);
    sem_destroy(&s2);
    return 0;
}

