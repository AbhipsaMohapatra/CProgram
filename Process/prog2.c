#include <stdio.h>
#include <unistd.h>

int main(){
    fork();
    if(!fork()){
        if(!fork()){
            if(!fork()){
                fork();
            }
        }
    }
    print("Hello");
    getchar();
    return 0;
}