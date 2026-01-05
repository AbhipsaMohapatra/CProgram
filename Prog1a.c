#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc,char *argv[]){
    pid_t childpid ;
    
    childpid = fork();
    if(childpid ==-1){
        perror("Some error occured");
    }
    if(childpid==0){
        execvp("ls",argv);
        printf("child failed to execute\n");
    }
    else{
        printf("This is for parent\n");

    }
    return 0;
}
