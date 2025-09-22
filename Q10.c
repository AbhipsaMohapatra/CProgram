#include <stdio.h>
int main(){
    int n ;
    scanf("%d",&n);
    if(n<0){
        printf("Negative numbers are not the power of 2");
        return 0;
    }
    if((n&1)==0){
        printf(" YES %d IS A POWER OF 2 ",n);

    }
    else{
        printf(" NO %d IS NOT A POWER OF 2",n);
    }
    return 0;
 }