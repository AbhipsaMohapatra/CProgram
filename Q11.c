#include <stdio.h>
#include <math.h>

int main(){
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    int i= (n1==1|| n1==0)?2:n1;

    for(;i<=n2;i++){
        int j =2;
        int b = 0;
        while(j<=sqrt((double)i)){
            if(i%j==0){
                b=1;
                break;
            }
            j++;

        }
        if(b==0){
            printf("%d\t",i);
        }
    }
    return 0;
}