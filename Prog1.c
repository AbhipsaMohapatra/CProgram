#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t childpid ;
    childpid = fork();
    if(childpid ==-1){
        perror("Some error occured");
    }
    if(childpid==0){
        execlp("/bin/ls","ls","-l",NULL);
        printf("child failed to execute");
    }
    else{
        printf("This is for parent");

    }
    return 0;
}
