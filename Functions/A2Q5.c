#include <stdio.h>
void find(int a[],int n,int ele){

    int newarr[] = new int[n];
    int pos = n-1;
    if(ele<a[0]){
        pos=0;
    }
    for(int i=0;i<n-1;i++){
        if(ele)
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
    printf("Enter the numbers in ascending order ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    find(a,n);
    return 0;
}