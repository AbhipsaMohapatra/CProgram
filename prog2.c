#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>

int main(){
    sem_t sem;
    if(sem_init(&sem,1,5)<0){
        perror("Semaphore initialization failed \n");
        exit(1);
    }
    int val ;
    if(sem_getvalue(&sem,&val)<0){
         perror("Semaphore value access failed ");
        exit(1);
    }
    fprintf(stdout,"Sem value %d \n",val);
    if(sem_wait(&sem)<0){
         perror("Semaphore value access failed ");
        exit(1);

    }
    if(sem_getvalue(&sem,&val)<0){
         perror("Semaphore value access failed ");
        exit(1);
    }
    fprintf(stdout,"Sem value decremented %d \n",val);
    if(sem_post(&sem)<0){
         perror("Semaphore value access failed ");
        exit(1);

    }
    if(sem_getvalue(&sem,&val)<0){
         perror("Semaphore value access failed ");
        exit(1);
    }
    fprintf(stdout,"Sem value incremented %d \n",val);

    if(sem_destroy(&sem)<0){
        perror("Some error occured ");
        exit(1);
    }
    fprintf(stdout,"Semaphore destroy successfull");




    return 0;
}
