#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char buf[100];
    int fd[2];

    if (pipe(fd) < 0)
    {
        printf("PIPE DOESNT CONTAIN ANY VALUE");
        exit(1);
    }
    pid_t child = fork();
    if (child == -1)
    {
        perror("fork failed");
        exit(1);
    }
    if (child == 0)
    {
        char *msg1 = "Hello parent I am the child\n";
        char *msg2 = "You are reading it from pipe\n";
        fprintf(stdout, "Writing to thr pipe from child \n");

        close(fd[0]);

        write(fd[1], msg1, 100);
        write(fd[1], msg2, 100);
        fprintf(stdout, "Writing completed");
        close(fd[1]);
        exit(1);
    }
    else
    {
        wait(NULL);
        fprintf(stdout, "Reading from parent by pipe");
        close(fd[1]);
        char buffer[100];
        ssize_t bytes_read;
        bytes_read = read(fd[0], buffer, 100);

        while (bytes_read)
        {
            fputs(buffer, stdout);
            bytes_read = read(fd[0], buffer, 100);
        }
        close(fd[0]);

    }
    return 0;
}