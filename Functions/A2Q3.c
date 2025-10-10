#include <stdio.h>
void find(int a[],int n){
    int max=a[0];
    int min = a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
           
            max=a[i];
        }
        else if(a[i]<min ){
            min=a[i];
        }
    }
    printf("difference between the largest and smallest element is  is %d",(max-min));

}
int main(){
    int n;
    printf("Enter the number of elements ");
    scanf("%d",&n);
    if(n<=0){
        printf("Invalid number of array elements ");
        return -1;
    }
    int a[n];
    printf("Enter the numbers ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    find(a,n);
    return 0;
}