#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int rev = 0;
    int temp = n;

    while(n>0){
        int d = n%10;
        rev = rev*10+d;
        n = n/10;
    }
    printf("The reversd number of number %d is %d",temp,rev);
    return 0;

}