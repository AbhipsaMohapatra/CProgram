#include <stdio.h>
void find(int a[],int n){
   int j=n-1;
   int i=0;
    while(i<j){
       if(a[i]%2==0){
         if(a[j]%2!=0){
            int temp = a[i];
            a[i] = a[j];
            a[j]=temp;
            i++;
            j--;
         }
         else{
            j--;
         }
       }
       else{
         i++;
       }
    }
    printf("'\n the updated array is ");
     for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }


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