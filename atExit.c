#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>

pid_t childpid ;
void complete(){
  int status;
  if (childpid > 0) {
        waitpid(childpid, &status, 0);
        printf("Child in atexit \n");
    }
  
}

int main(){
    
    
    int n;
    if(atexit(complete)){
       perror("Some error occured ");
    }
    childpid = fork();
    if(childpid==-1){
       perror("Unable to create fork");
       
    }
   
    
    else if(childpid==0){
       scanf("%d",&n);
       printf("This is child \n");
       exit(23);
    }
    else{
       
       printf("this is parent \n ");
    }
    
    
    return 0;
}
