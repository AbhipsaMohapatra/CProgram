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
       
       printf("This is a child process");
    }
    else{
        sleep(1000);
        getchar();
        printf("This is for parent");

    }
    return 0;
}
