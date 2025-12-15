#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <semaphore.h>

int main(){
    char a1[] = "is";
    char a2[] = "very";
     char a3[] = "PPWC";
      char a4[] = "boring";
    sem_t s1;
    sem_t s2;
    int i=0;
    if( sem_init(&s1,2,0)<0 || sem_init(&s2,2,0)){
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
        
       fprintf(stderr,"%s ",a3);
       sem_post(&s1);
        
    }
    else{
        sem_wait(&s1);
        fprintf(stderr," %s ",a1);
        sem_post(&s1);
        wait(NULL);

    }
     pid_t childpid2 = fork();
    if(childpid2<0){
        perror("Fork failed \n");
        exit(1);
    }

    if(childpid2 ==0 ){
        
        fprintf(stderr," %s ",a2);
        sem_post(&s2);
        exit(0);
        
      
        sem_wait(&s2);
       fprintf(stderr," %s ",a4);
        sem_post(&s2);
        exit(0);


    }
   


    
    return 0;


}
