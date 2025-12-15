#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
    char s1[] = "I am a parent";
    char s2[]  ="I am the child ";
    int i=0;

    pid_t childpid ;
    childpid = fork();

    if(childpid<0){
        perror("Fork failed \n");
        exit(1);
    }
    

    if(childpid ==0 ){
        while(s2[i]){
            fprintf(stderr,"%c",s2[i++]);
            sleep(1);
        }
        exit(0);
    }
    while(s1[i]){
            fprintf(stderr,"%c",s1[i++]);
            sleep(1);
    }
    wait(NULL);
    return 0;


}
