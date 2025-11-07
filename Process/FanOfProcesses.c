#include <stdio.h>
#include <unistd.h>

int main(){
    __pid_t p;
   for(int i=1;i<5;i++){
    if((p=fork())<=0){
        break;
    }
   }
   printf("Hello ");
   getchar();
   return 0;
}