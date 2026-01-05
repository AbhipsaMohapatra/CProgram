#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t childpid ;
    int temp;
    childpid = fork();
    if(childpid ==-1){
        perror("Some error occured");
    }
    if(childpid==0){
        scanf("%d",&temp);
       
       printf("This is a child process\n");
       sleep(10000);
    }
    else{
        
        printf("This is for parent\n");

    }
    return 0;
}
