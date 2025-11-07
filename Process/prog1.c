#include <stdio.h>
#include <unistd.h>

int main(){
    fork();
    if(fork() && fork()){
        fork();
    }
    getchar();
    return 0;
}