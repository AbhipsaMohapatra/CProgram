#include <stdio.h>
#include <unistd.h>

int main(){
    __pid_t p1,p2,p3;
    for(int i=1;i<3;i++){
        if((p1=fork())){
            break;
        }
    }
    if(p1==0){
        for(int j=1;j<3;j++){
            if((p2=fork())<=0){
                break;
            }
        }
    
    }
    if(p1==0){
        for(int k=1;k<3;k++){
            if(p3=fork()){
                break;
            }
        }
    }
    getchar();
    return 0;
}