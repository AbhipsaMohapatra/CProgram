#include <stdio.h>
#include <unistd.h>
#define MSG_SIZE 32;


int main(){
    int fd[2];
    char *msg = "Welcome to ppwc lab class ";
    char *msg2 = "writing to the pipe";
    char *msg3 = "Hope you can understand";

    if(pipe(fd)<0){
        perror("pipe creation failed");
        exit(1);
    }
    write(fd[1],msg,32);
    write(fd[1],msg2,32);
    write(fd[1],msg2,32);

   close(fd[1]);


    char buffer[32];
    ssize_t bytes_read;
    bytes_read = read(fd[0],buffer,32);

    while(bytes_read){
        fputs(buffer,stdout);
        bytes_read = read(fd[0],buffer,32);
    }
    close(fd[0]);

    return 0;

}