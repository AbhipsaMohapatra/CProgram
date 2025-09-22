#include <stdio.h>

int main(){
    
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    int a = n1;
    int b = n2;


    while(n2!=0){
        int c = n1%n2;
        n1 = n2;
        n2=c;
    }
    int lcm = (a*b)/n1;
    printf("The gcd is %d \n",n1);
    printf("the lcm is %d \t",lcm);

    return 0;
}